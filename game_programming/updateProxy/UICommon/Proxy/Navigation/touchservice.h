#ifndef TOUCHSERVICE_H
#define TOUCHSERVICE_H

#include <QObject>
#include <QList>
#include <QTouchEvent>
#include <QMouseEvent>
#include <QDBusArgument>

enum NaviboxTouchType: int8_t {
    OtherTouch      = -1,
    Navi            = 0,
    Dtv             = 1,
    Hdmi            = 2,
    DtvFullScreen,
    DtvFullVideo,
    HdmiFullScreen,
    HdmiFullVideo,
};

struct TouchPoint
{
    int id;
    int state;
    int scenePositionX;
    int scenePositionY;
    int globalPositionX;
    int globalPositionY;
};

struct TouchInfo
{
    int type;
    QList<TouchPoint> points;

    QMouseEvent toMouseEvent() const;
    QTouchEvent toTouchEvent() const;
};

class TouchServiceProxy;
class TouchServiceAdaptor;

class TouchService : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ese.hmi.TouchService")
public:
    explicit TouchService(QObject *parent = nullptr);
    static TouchServiceProxy *createProxy(QObject *parent);

public slots:
    virtual void sendTouch(const TouchInfo &info) = 0;
};


Q_DECLARE_METATYPE(TouchPoint)
Q_DECLARE_METATYPE(TouchInfo)

QDBusArgument &operator<<(QDBusArgument &argument, const TouchPoint &point);
const QDBusArgument &operator>>(const QDBusArgument &argument, TouchPoint &point);

QDBusArgument &operator<<(QDBusArgument &argument, const TouchInfo &info);
const QDBusArgument &operator>>(const QDBusArgument &argument, TouchInfo &info);

#endif // TOUCHSERVICE_H
