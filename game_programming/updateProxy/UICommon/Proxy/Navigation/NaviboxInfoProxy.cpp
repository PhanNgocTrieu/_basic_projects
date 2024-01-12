#include "NaviboxInfoProxy.h"

NaviboxInfoProxy::NaviboxInfoProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
    connect(this, &NaviboxInfoProxy::onNaviboxInfoChanged, this, &NaviboxInfoProxy::updateNaviboxInfo);
}

NaviboxInfoProxy::~NaviboxInfoProxy()
{
}

std::optional<uint16_t> NaviboxInfoProxy::getSoftVer()
{
    return m_softVer;
}

std::optional<uint16_t> NaviboxInfoProxy::getMapVer()
{
    return m_mapVer;
}

void NaviboxInfoProxy::updateNaviboxInfo(const NaviboxInfoType &type, const QDBusVariant &var)
{
    QVariant variant = var.variant();
    if (variant.isValid() == true) {
        switch (type) {
        case NaviboxInfoType::SoftVer:
            m_softVer = std::optional<uint16_t>(variant.toUInt());
            break;
        case NaviboxInfoType::MapVer:
            m_mapVer = std::optional<uint16_t>(variant.toUInt());
            break;
        default:
            break;
        }
    }
    emit onNaviboxProxyInfoChanged();
}
