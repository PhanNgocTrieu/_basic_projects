#ifndef NAVIBOXINFOPROXY_H
#define NAVIBOXINFOPROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <optional>
#include "naviboxinfoservice.h"

class NaviboxInfoProxy: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "ese.hmi.nbif"; }

public:
    NaviboxInfoProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);
    ~NaviboxInfoProxy();

    std::optional<uint16_t> getSoftVer();
    std::optional<uint16_t> getMapVer();

    inline void setSoftVer(const std::optional<uint16_t>& newVal)
    {
        m_softVer = newVal;
        emit onNaviboxProxyInfoChanged();
    }

    inline void setMapVer(const std::optional<uint16_t>& newVal)
    {
        m_mapVer = newVal;
        emit onNaviboxProxyInfoChanged();
    }

private Q_SLOTS:
    void updateNaviboxInfo(const NaviboxInfoType& type, const QDBusVariant& var);

Q_SIGNALS: // SIGNALS
    void onNaviboxInfoChanged(const NaviboxInfoType& type, const QDBusVariant& var);
    void onNaviboxProxyInfoChanged();
private:
    std::optional<uint16_t> m_softVer = std::nullopt;
    std::optional<uint16_t> m_mapVer = std::nullopt;
};

namespace ese {
  namespace hmi {
    typedef ::NaviboxInfoProxy nbif;
  }
}
#endif
