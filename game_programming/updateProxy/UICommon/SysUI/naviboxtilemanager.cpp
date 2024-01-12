#include <QQmlProperty>
#include "naviboxtilemanager.h"

static const char *NAVI_APP     = "7_NAVI_App";
static const char *MEDIA_APP    = "8_MEDIA_App";

NaviboxTileManager::NaviboxTileManager(QObject *parent): QObject{parent}
{
    m_layout = "";
    m_timer.setInterval(200);
    m_checkCameraTimer.setInterval(200);
    connect(&m_timer, &QTimer::timeout, this, &NaviboxTileManager::onTimeOut);
    connect(&m_checkCameraTimer, &QTimer::timeout, this, &NaviboxTileManager::onCheckCamera);
    m_startTiles.clear();
}

NaviboxTileManager *NaviboxTileManager::getInstance()
{
    static NaviboxTileManager instance;
    return &instance;
}

void NaviboxTileManager::displayTile(const QString &screenid, const int position, const bool isMedia)
{
    if (screenid == NAVI_APP && position == 0) {
        std::unique_lock lock(m_mtx);
        if (m_naviScreen != nullptr) {
            updateTile(screenid, position, isMedia);
        } else {
            m_requestDisplayNavigation = true;
        }
    } else if (screenid == MEDIA_APP && position == 0) {
        std::unique_lock lock(m_mtx);
        if (m_mediaScreen != nullptr) {
            updateTile(screenid, position, isMedia);
        } else {
            m_requestDisplayMedia = true;
        }
    } else {
        updateTile(screenid, position, isMedia);
    }
}

void NaviboxTileManager::hideTile(const QString &screenid, const bool isMedia)
{
    qWarning() << "NaviboxTileManager" << __FUNCTION__ << screenid << isMedia;
    if (screenid != "") {
        setIsDisplayFull(false);
        emit tileUpdated(screenid, true, 0);

        if (isMedia == true) {
            m_isDisplayMedia = false;
        } else {
            m_isDisplayNavi = false;
        }
        emit centerCameraStateChanged(m_isDisplayMedia || m_isDisplayNavi);
    }
}

void NaviboxTileManager::notifyCreate(QObject *object, const QString &appid, const bool isFull)
{
    qWarning() << "NaviboxTileManager" << __FUNCTION__ << appid << isFull;
    if (isFull == false && (m_isCurrentApp == "HOME" || m_isCurrentApp == "")) {
        std::unique_lock lock(m_mtx);
        m_resetLayout = true;
        m_tiles.append(object);
        if (m_length > 0 && m_tiles.length() == m_length) {
            m_timer.start();
        }
    } else if (isFull == true) {
        if (appid == NAVI_APP) {

            std::unique_lock lock(m_mtx);
            m_naviScreen = object;
            if (m_requestDisplayNavigation == true) {
                updateTile(NAVI_APP, 0, false);
            }
        } else if (appid == MEDIA_APP) {

            std::unique_lock lock(m_mtx);
            m_mediaScreen = object;
            if (m_requestDisplayMedia == true) {
                updateTile(MEDIA_APP, 0, true);
            }
        } else {
            m_naviScreen = nullptr;
            m_mediaScreen = nullptr;
        }
    }
}

void NaviboxTileManager::notifyDestroy(QObject *object, const QString &appid, const bool isFull)
{
    qWarning() << "NaviboxTileManager" << __FUNCTION__ << appid << isFull;
    if (isFull == false) {
        std::unique_lock lock(m_mtx);
        if (m_tiles.length() > 0) {
            m_resetLayout = true;
            for (int i = 0; i < m_tiles.length(); i++) {
                if (m_tiles[i] == object) {
                    m_tiles.removeAt(i);
                    break;
                }
            }
            if (m_length > 0 && m_tiles.length() == m_length) {
                m_timer.start();
            } else {
                m_timer.stop();
            }
        }
    } else if (appid == NAVI_APP) {
        std::unique_lock lock(m_mtx);
        m_naviScreen = nullptr;
        m_requestDisplayNavigation = false;
    } else if (appid == MEDIA_APP) {

        std::unique_lock lock(m_mtx);
        m_mediaScreen = nullptr;
        m_requestDisplayMedia = false;
    }
}

void NaviboxTileManager::notifyLayoutChanged(const QString &layout)
{
    qWarning() << "NaviboxTileManager" << __FUNCTION__ << layout;
    setIsDisplayFull(false);
    std::unique_lock lock(m_mtx);
    if (layout != "") {

        if (m_layout == layout && m_resetLayout == false) {
        } else {
            m_layout = layout;
            m_appids = layout.split(",");
            m_length = m_appids.length();

            if (m_length > 0 && m_tiles.length() == m_length) {
                m_timer.start();
            } else {
                m_timer.stop();
            }
        }
    }
}

void NaviboxTileManager::setCurrentApp(const QString &appid)
{
    qWarning() << "NaviboxTileManager" << __FUNCTION__ << appid;
    m_isCurrentApp = appid;
}

void NaviboxTileManager::notifyCameraState(const bool loaded)
{
    m_loadedCamera = loaded;
}

void NaviboxTileManager::onTimeOut()
{
    qWarning() << "NaviboxTileManager" << __FUNCTION__ << m_layout;
    m_timer.stop();
    bool result = verifyLayout();
    if (result == true) {
        m_resetLayout = false;
        emit layoutCompleted(m_layout);
    }
}

void NaviboxTileManager::onCheckCamera()
{
    if (m_waitCamera == true) {
        if (m_loadedCamera == true) {
            m_waitCamera = false;
            m_checkCameraTimer.stop();
            emit centerCameraStateChanged(true);
            for (uint8_t i = 0; i < m_startTiles.length(); i++) {
                emit tileUpdated(m_startTiles[i].screenid, false, m_startTiles[i].dispType);
            }
            m_startTiles.clear();
        }
    } else {
        m_checkCameraTimer.stop();
    }
}

bool NaviboxTileManager::verifyLayout()
{
    int count = 0;

    if (m_length == m_tiles.length()) {
        for (QObject *tile: m_tiles) {
            QString appid = QQmlProperty::read(tile, "appId").toString();
            int tileIndex = QQmlProperty::read(tile, "tileIndex").toInt();
            if (0 <= tileIndex && tileIndex < m_length) {
                if (m_appids[tileIndex].contains(appid) == true) {
                    count += 1;
                }
            }
        }
    }

    return count == m_length && count > 0;
}

void NaviboxTileManager::updateTile(const QString &screenid, const int dispType, const bool isMedia)
{
    if (isMedia == false) {
        setIsDisplayFull(dispType == 0);
        m_requestDisplayNavigation = false;
        m_isDisplayNavi = true;
    } else {
        m_requestDisplayMedia = false;
        m_isDisplayMedia = true;
    }

    if (m_waitCamera == true) {
        if (m_loadedCamera == true) {
            m_waitCamera = false;
            m_checkCameraTimer.stop();
            emit centerCameraStateChanged(true);
            emit tileUpdated(screenid, false, dispType);
        } else {
            m_checkCameraTimer.start();
            TileInfo info = {
                .screenid = screenid,
                .dispType = dispType,
            };
            m_startTiles.append(info);
        }
    } else {
        emit centerCameraStateChanged(true);
        emit tileUpdated(screenid, false, dispType);
    }
}

bool NaviboxTileManager::isDisplayFull() const
{
    return m_isDisplayFull;
}

void NaviboxTileManager::setIsDisplayFull(bool newIsDisplayFull)
{
    if (m_isDisplayFull == newIsDisplayFull)
        return;
    m_isDisplayFull = newIsDisplayFull;
    emit isDisplayFullChanged();
}

bool NaviboxTileManager::isActiveCamera()
{
    return m_isDisplayMedia || m_isDisplayNavi;
}
