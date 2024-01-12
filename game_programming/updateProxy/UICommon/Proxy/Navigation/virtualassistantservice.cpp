#include "virtualassistantservice.h"
#include "VirtualAssistantAdaptor.h"
#include "VirtualAssistantProxy.h"

#define DBUS_SERVICE_NAME   "ese.hmi.VirtualAssistantService"
#define DBUS_OBJECT_NAME   "/naviboxvrservice"

VirtualAssistantService::VirtualAssistantService(QObject *parent)
    : QObject{parent}
{
    intialize();
}

void VirtualAssistantService::intialize()
{
    qRegisterMetaType<VAComand>("VAComand");
    qDBusRegisterMetaType<VAComand>();

    new VirtualAssistantAdaptor(this);
    QDBusConnection::sessionBus().registerObject(DBUS_OBJECT_NAME, this);
    QDBusConnection::sessionBus().registerService(DBUS_SERVICE_NAME);
}

VirtualAssistantProxy *VirtualAssistantService::createProxy(QObject *parent)
{
    qRegisterMetaType<VAComand>("VAComand");
    qDBusRegisterMetaType<VAComand>();

    VirtualAssistantProxy *proxy = new VirtualAssistantProxy(DBUS_SERVICE_NAME, DBUS_OBJECT_NAME, QDBusConnection::sessionBus(), parent);
    return proxy;
}

QDBusArgument &operator<<(QDBusArgument &argument, const VAComand &type)
{
    argument.beginStructure();
    argument<<static_cast<uint8_t>(type);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, VAComand &type)
{
    uint8_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<VAComand>(resValue);
    return argument;
}
