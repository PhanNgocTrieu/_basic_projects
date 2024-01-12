#ifndef NAVIBOXTILEMANAGER_H
#define NAVIBOXTILEMANAGER_H

#include <QObject>
#include <QMutex>
#include <QStringList>
#include <QString>
#include <QTimer>
#include <mutex>
#include <shared_mutex>

struct TileInfo
{
    QString screenid;
    int dispType;
};

class NaviboxTileManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isDisplayFull READ isDisplayFull WRITE setIsDisplayFull NOTIFY isDisplayFullChanged)

    explicit NaviboxTileManager(QObject *parent = nullptr);
public:
    static NaviboxTileManager *getInstance();

    void displayTile(const QString& screenid, const int position, const bool isMedia);
    void hideTile(const QString& screenid, const bool isMedia);

    Q_INVOKABLE void notifyCreate(QObject *object, const QString &appid = "", const bool isFull = false);
    Q_INVOKABLE void notifyDestroy(QObject *object, const QString &appid = "", const bool isFull = false);
    Q_INVOKABLE void notifyLayoutChanged(const QString &layout);
    Q_INVOKABLE void setCurrentApp(const QString &appid = "HOME");
    Q_INVOKABLE void notifyCameraState(const bool loaded);

    bool isDisplayFull() const;
    void setIsDisplayFull(bool newIsDisplayFull);
    bool isActiveCamera();

private slots:
    void onTimeOut();
    void onCheckCamera();

private:
    bool verifyLayout();
    void updateTile(const QString& screenid, const int dispType, const bool isMedia);

signals:
    void centerCameraStateChanged(const bool state);
    void layoutCompleted(const QString &layout);
    void tileUpdated(const QString& screenid, const bool isClose, const int position);
    void isDisplayFullChanged();

private:
    QObject *m_naviScreen {nullptr};
    QObject *m_mediaScreen {nullptr};
    QList<QObject *> m_tiles;

    std::shared_mutex m_mtx;
    QString m_layout;
    QStringList m_appids;
    uint8_t m_length {0};

    QTimer m_timer;
    bool m_isDisplayFull{false};
    bool m_resetLayout {false};
    QString m_isCurrentApp;
    bool m_loadedCamera {false};
    bool m_waitCamera {true};
    QTimer m_checkCameraTimer;
    QList<TileInfo> m_startTiles;

    bool m_requestDisplayNavigation {false};
    bool m_requestDisplayMedia {false};
    bool m_isDisplayNavi {false};
    bool m_isDisplayMedia {false};
};

#endif // NAVIBOXTILEMANAGER_H
