#include "WifiAdapterAgencyProxy.h"

namespace uicommon
{
    WifiAdapterAgencyProxy& WifiAdapterAgencyProxy::getInstance()
    {
        static WifiAdapterAgencyProxy singleton("ese.hmi.setting", "/WifiAdapter", QDBusConnection::sessionBus());

        return singleton;
    }

    WifiAdapterAgencyProxy::WifiAdapterAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
        : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
    }
}   