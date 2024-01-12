#include "BluetoothAdapterAgencyProxy.h"

namespace uicommon
{
    BluetoothAdapterAgencyProxy &BluetoothAdapterAgencyProxy::getInstance()
    {
        static BluetoothAdapterAgencyProxy singleton("ese.hmi.setting", "/BluetoothAdapter", QDBusConnection::sessionBus());

        return singleton;
    }

    BluetoothAdapterAgencyProxy::BluetoothAdapterAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
        : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
    }

    BluetoothAdapterAgencyProxy::~BluetoothAdapterAgencyProxy()
    {
    }

}
