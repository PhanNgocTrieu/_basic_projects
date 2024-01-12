#include <QDBusConnection>
#include <QDBusMetaType>
#include <QStringList>
#include <QEventPoint>

#include "touchservice.h"
#include "TouchServiceAdaptor.h"
#include "TouchServiceProxy.h"

#define DBUS_SERVICE_NAME   "ese.hmi.TouchService"
#define DBUS_OBJECT_NAME   "/naviboxtouchservice"

TouchService::TouchService(QObject *parent): QObject{parent}
{
    qRegisterMetaType<TouchInfo>("TouchInfo");
    qDBusRegisterMetaType<TouchInfo>();
    qRegisterMetaType<TouchPoint>("TouchPoint");
    qDBusRegisterMetaType<TouchPoint>();

    new TouchServiceAdaptor(this);
    QDBusConnection::sessionBus().registerObject(DBUS_OBJECT_NAME, this);
    QDBusConnection::sessionBus().registerService(DBUS_SERVICE_NAME);
}

TouchServiceProxy *TouchService::createProxy(QObject *parent)
{
    qRegisterMetaType<TouchInfo>("TouchInfo");
    qDBusRegisterMetaType<TouchInfo>();
    qRegisterMetaType<TouchPoint>("TouchPoint");
    qDBusRegisterMetaType<TouchPoint>();

    TouchServiceProxy *proxy = new TouchServiceProxy(DBUS_SERVICE_NAME, DBUS_OBJECT_NAME, QDBusConnection::sessionBus(), parent);
    return proxy;
}

QDBusArgument &operator<<(QDBusArgument &argument, const TouchPoint &point)
{
    argument.beginStructure();
    argument << point.id;
    argument << point.state;
    argument << point.scenePositionX;
    argument << point.scenePositionY;
    argument << point.globalPositionX;
    argument << point.globalPositionY;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, TouchPoint &point)
{
    argument.beginStructure();
    argument >> point.id;
    argument >> point.state;
    argument >> point.scenePositionX;
    argument >> point.scenePositionY;
    argument >> point.globalPositionX;
    argument >> point.globalPositionY;
    argument.endStructure();
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const TouchInfo &info)
{
    argument.beginStructure();
    argument << info.type;
    argument.beginArray(qMetaTypeId<TouchPoint>());
    int lenght = info.points.length();

    for (int i = 0; i < lenght; i++) {
        argument << info.points[i];
    }
    argument.endArray();
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, TouchInfo &info)
{
    argument.beginStructure();
    argument >> info.type;

    argument.beginArray();
    while (argument.atEnd() == false) {
        TouchPoint point;
        argument >> point;
        info.points.append(point);
    }
    argument.endArray();
    argument.endStructure();
    return argument;
}

QMouseEvent TouchInfo::toMouseEvent() const
{
    QEvent::Type type = static_cast<QEvent::Type>(this->type);
    Qt::MouseButton button = Qt::NoButton;
    Qt::MouseButtons buttons = Qt::NoButton;

    int posX = 0;
    int posY = 0;

    if (points.length() > 0) {
        posX = points[0].scenePositionX;
        posY = points[0].scenePositionY;

        button = static_cast<Qt::MouseButton>(points[0].globalPositionX);
        buttons = static_cast<Qt::MouseButtons>(points[0].globalPositionY);
    }

    return QMouseEvent(type, QPointF(posX, posY), button, buttons, Qt::NoModifier);
}

QTouchEvent TouchInfo::toTouchEvent() const
{
    QEvent::Type type = static_cast<QEvent::Type>(this->type);
    QList<QEventPoint> epoints;

    for (const TouchPoint &point: points) {

        int id =  point.id;
        QEventPoint::State state = static_cast<QEventPoint::State>(point.state);

        QEventPoint epoint(id, state, QPointF(point.scenePositionX, point.scenePositionY), QPointF(point.globalPositionX, point.globalPositionY));
        epoints.append(epoint);
    }

    return QTouchEvent(type, nullptr, Qt::NoModifier, epoints);
}
