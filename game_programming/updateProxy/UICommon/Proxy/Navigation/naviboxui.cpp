#include "naviboxui.h"
#include "NaviboxUIAdaptor.h"
#include "NaviboxUIProxy.h"

#define DBUS_SERVICE_NAME   "ese.hmi.naviboxui"
#define DBUS_OBJECT_NAME   "/naviboxui"
#define LOG (qWarning() << "NaviboxUI")

NaviboxUI::NaviboxUI(QObject *parent): QObject{parent}
{
    qRegisterMetaType<NaviboxUIState>("NaviboxUIState");
    qDBusRegisterMetaType<NaviboxUIState>();

    new NaviboxUIAdaptor(this);
    QDBusConnection::sessionBus().registerObject(DBUS_OBJECT_NAME, this);
    QDBusConnection::sessionBus().registerService(DBUS_SERVICE_NAME);

    m_currentNaviApp = "";
    m_nextNaviApp = "";
    m_currentTiles.clear();
    m_nextTiles.clear();
}

NaviboxUIProxy *NaviboxUI::createProxy(QObject *parent)
{
    qRegisterMetaType<NaviboxUIState>("NaviboxUIState");
    qDBusRegisterMetaType<NaviboxUIState>();

    NaviboxUIProxy *proxy = new NaviboxUIProxy(DBUS_SERVICE_NAME, DBUS_OBJECT_NAME, QDBusConnection::sessionBus(), parent);
    return proxy;
}

void NaviboxUI::requestTransition(const QString &appid)
{
    std::unique_lock lock(m_mtx);
    LOG << __FUNCTION__ << appid << "cur:" << m_currentNaviApp << "next:" << m_nextNaviApp;
    if (appid.contains("_13") || appid.contains("_23")) {
        if (m_currentNaviApp == "" || m_currentNaviApp == "HOME") {
            m_currentNaviApp = "HOME";

            if (m_currentTiles.contains(appid) == false) {
                m_currentTiles.append(appid);
            }

            emit acceptTransition(appid);
            m_nextNaviApp = "";
        } else {

            m_nextNaviApp = "HOME";
            if (m_nextTiles.contains(appid) == false) {
                m_nextTiles.append(appid);
            }
        }
    } else {
        if (m_currentNaviApp == "") {

            m_currentTiles.clear();
            m_nextTiles.clear();
            m_currentNaviApp = appid;
            emit acceptTransition(appid);
            m_nextNaviApp = "";
        } else if (m_currentNaviApp != appid) {

            m_nextNaviApp = appid;
        } else if (m_currentNaviApp == appid) {

            m_currentTiles.clear();
            m_nextTiles.clear();
            emit acceptTransition(appid);
            m_nextNaviApp = "";
        }
    }
}

void NaviboxUI::notifyState(const QString &appid, const NaviboxUIState state)
{
    std::unique_lock lock(m_mtx);
    LOG << __FUNCTION__ << appid << (int)state << "cur:" << m_currentNaviApp << "next:" << m_nextNaviApp;
    if (appid == m_currentNaviApp && state == NaviboxUIState::EndFull) {

        if (m_nextNaviApp == "HOME") {

            m_currentTiles.clear();
            m_currentNaviApp = "HOME";

            for (uint8_t i = 0; i < m_nextTiles.length(); i++) {
                m_currentTiles.append(m_nextTiles[i]);
                emit acceptTransition(m_nextTiles[i]);
                m_nextNaviApp = "";
            }

            for (uint8_t i = 0; i < m_currentTiles.length(); i++) {
                m_nextTiles.removeOne(m_currentTiles[i]);
            }

        } else if (m_nextNaviApp != "") {
            m_currentTiles.clear();
            m_nextTiles.clear();

            m_currentNaviApp = m_nextNaviApp;
            emit acceptTransition(m_nextNaviApp);
            m_nextNaviApp = "";
        } else {
            m_currentNaviApp = "";
        }
    } else if (m_currentNaviApp == "HOME" && (appid.contains("_13") || appid.contains("_23")) && state == NaviboxUIState::EndHome) {
        m_currentTiles.removeOne(appid);
        m_nextTiles.clear();

        if (m_currentTiles.length() == 0) {
            if (m_nextNaviApp != "") {
                m_currentNaviApp = m_nextNaviApp;
                emit acceptTransition(m_nextNaviApp);
                m_nextNaviApp = "";
            } else {
                m_currentNaviApp = "";
            }
        }
    }
}

void NaviboxUI::changeMediaType(const QString &type)
{

}

void NaviboxUI::setCurrentApp(const QString &appid)
{

}

QDBusArgument &operator<<(QDBusArgument &argument, const NaviboxUIState &type)
{
    argument.beginStructure();
    argument<<static_cast<uint8_t>(type);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, NaviboxUIState &type)
{
    uint8_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<NaviboxUIState>(resValue);
    return argument;
}
