#include <QDBusArgument>
#include <QDBusMetaType>
#include "naviboxinfoservice.h"
#include "NaviboxInfoAdaptor.h"
#include "NaviboxInfoProxy.h"

#define DBUS_SERVICE_NAME   "ese.hmi.nbif"
#define DBUS_OBJECT_NAME   "/naviboxinfoservice"

// START - Fix klocwork MLK.MUST
NaviboxInfoAdaptor* NaviboxInfoService::m_naviboxInfoAdaptor = nullptr;
// END - Fix klocwork MLK.MUST

NaviboxInfoService::NaviboxInfoService(QObject *parent): QObject{parent}
{

}

NaviboxInfoService::~NaviboxInfoService()
{
    // START - Fix klocwork MLK.MUST
    if (m_naviboxInfoAdaptor != nullptr) {
        delete m_naviboxInfoAdaptor;
        m_naviboxInfoAdaptor = nullptr;
    }
    // END - Fix klocwork MLK.MUST
}

void NaviboxInfoService::intialize(NaviboxInfoService *service)
{
    qRegisterMetaType<NaviboxInfoType>("NaviboxInfoType");
    qDBusRegisterMetaType<NaviboxInfoType>();

    // START - Fix klocwork MLK.MUST
    if (m_naviboxInfoAdaptor != nullptr) {
        delete m_naviboxInfoAdaptor;
        m_naviboxInfoAdaptor = nullptr;
    }
    m_naviboxInfoAdaptor = new NaviboxInfoAdaptor(service);
    // END - Fix klocwork MLK.MUST

    QDBusConnection::sessionBus().registerObject(DBUS_OBJECT_NAME, service);
    QDBusConnection::sessionBus().registerService(DBUS_SERVICE_NAME);
}

NaviboxInfoProxy *NaviboxInfoService::createProxy(QObject *parent)
{
    qRegisterMetaType<NaviboxInfoType>("NaviboxInfoType");
    qDBusRegisterMetaType<NaviboxInfoType>();

    NaviboxInfoProxy *proxy = new NaviboxInfoProxy(DBUS_SERVICE_NAME, DBUS_OBJECT_NAME, QDBusConnection::sessionBus(), parent);
    return proxy;
}

QDBusArgument &operator<<(QDBusArgument &argument, const NaviboxInfoType &type)
{
    argument.beginStructure();
    argument<<static_cast<uint8_t>(type);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, NaviboxInfoType &type)
{
    uint8_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<NaviboxInfoType>(resValue);
    return argument;
}
