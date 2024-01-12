#include "ACPAgencyProxy.h"

namespace uicommon
{
    ACPAgencyProxy &ACPAgencyProxy::getInstance()
    {
        static ACPAgencyProxy singleton("ese.hmi.syspopup", "/ACPAgency", QDBusConnection::sessionBus());

        return singleton;
    }

    ACPAgencyProxy::ACPAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
        : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
        qInfo() << "ACPAgencyProxy create instance";
    }

    ACPAgencyProxy::~ACPAgencyProxy()
    {
    }
}