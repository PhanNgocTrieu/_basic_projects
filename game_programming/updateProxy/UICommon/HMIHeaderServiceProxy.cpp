
#include "HMIHeaderServiceProxy.h"

namespace uicommon {
    /*
     * Implementation of interface class EseHmiSysInterface
     */

    HMIHeaderServiceProxy& HMIHeaderServiceProxy::getInstance()
    {
        static HMIHeaderServiceProxy singleton("ese.hmi.services","/HeaderService",QDBusConnection::sessionBus());

        return singleton;
    }

    HMIHeaderServiceProxy::HMIHeaderServiceProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
        : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
    }

    HMIHeaderServiceProxy::~HMIHeaderServiceProxy()
    {
    }
}
