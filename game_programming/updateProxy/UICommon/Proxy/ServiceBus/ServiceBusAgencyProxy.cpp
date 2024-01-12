#include "ServiceBusAgencyProxy.h"

namespace uicommon
{
    ServiceBusAgencyProxy &ServiceBusAgencyProxy::getInstance()
    {
        static ServiceBusAgencyProxy singleton("ese.hmi.servicebus", "/ServiceBusAgency", QDBusConnection::sessionBus());

        return singleton;
    }

    ServiceBusAgencyProxy::ServiceBusAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
        : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
    }

    ServiceBusAgencyProxy::~ServiceBusAgencyProxy()
    {
    }
}