#ifndef NAVIBOXINFOSERVICE_H
#define NAVIBOXINFOSERVICE_H

#include <QDBusArgument>
#include <QObject>
#include <QVariant>

enum class NaviboxInfoType : uint8_t {
    SerialNo,   // ナビボックスのシリアルナンバー
    HardID,     // ナビボックスのハードウェアID
    SoftID,     // ナビボックスのソフトウェアID
    SoftVer,    // ナビボックスのソフトウェアVER
    MapID,      // ナビボックスの地図ID
    MapVer,     // ナビボックスの地図VER
    AppIVR,     // アプリ完全性検証結果
    MapIVR,     //  地図完全性検証結果
};

class NaviboxInfoAdaptor;
class NaviboxInfoProxy;
class NaviboxInfoService : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ese.hmi.nbif")
public:
    explicit NaviboxInfoService(QObject *parent = nullptr);
    virtual ~NaviboxInfoService();
    static void intialize(NaviboxInfoService *service);
    static NaviboxInfoProxy *createProxy(QObject *parent = nullptr);

signals:
    void onNaviboxInfoChanged(const NaviboxInfoType& type, const QDBusVariant& var);

private:
    static NaviboxInfoAdaptor* m_naviboxInfoAdaptor;
};

Q_DECLARE_METATYPE(NaviboxInfoType)

QDBusArgument &operator<<(QDBusArgument &argument, const NaviboxInfoType &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, NaviboxInfoType &type);

#endif // NAVIBOXINFOSERVICE_H
