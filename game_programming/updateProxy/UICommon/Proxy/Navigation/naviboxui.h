#ifndef NAVIBOXUI_H
#define NAVIBOXUI_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDBusArgument>
#include <shared_mutex>

enum class NaviboxUIState : uint8_t
{
    Full = 0,
    Home,
    EndFull,
    EndHome,
};

class NaviboxUIAdaptor;
class NaviboxUIProxy;

class NaviboxUI : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ese.hmi.naviboxui")
public:
    explicit NaviboxUI(QObject *parent = nullptr);
    static NaviboxUIProxy *createProxy(QObject *parent);

signals:
    void acceptTransition(const QString &appid);
    void mediaTypeChanged(const QString &type);

public slots:
    virtual void requestTransition(const QString &appid);
    virtual void notifyState(const QString &appid, const NaviboxUIState state);
    virtual void changeMediaType(const QString &type);
    void setCurrentApp(const QString &appid);

private:
    QString m_currentNaviApp;
    QString m_nextNaviApp;

    QStringList m_currentTiles;
    QStringList m_nextTiles;

    int m_tileCounter {0};
    std::shared_mutex m_mtx;
};

QDBusArgument &operator<<(QDBusArgument &argument, const NaviboxUIState &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, NaviboxUIState &type);

#endif // NAVIBOXUI_H
