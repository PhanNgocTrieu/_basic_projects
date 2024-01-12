#ifndef VIRTUALASSISTANTSERVICE_H
#define VIRTUALASSISTANTSERVICE_H

#include <QObject>
#include <QVariant>
#include <QDBusArgument>

enum class VAComand : uint8_t {
    SeekUp,
    SeekDown,
    ScanOn,
    ScanOff,
};

class VirtualAssistantProxy;
class VirtualAssistantService : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ese.hmi.VirtualAssistantService")
public:
    explicit VirtualAssistantService(QObject *parent = nullptr);
    static VirtualAssistantProxy *createProxy(QObject *parent);

private:
    void intialize();

public slots:
    virtual void sendCommand(VAComand command, const QDBusVariant& data) = 0;
};

Q_DECLARE_METATYPE(VAComand)

QDBusArgument &operator<<(QDBusArgument &argument, const VAComand &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, VAComand &type);

#endif // VIRTUALASSISTANTSERVICE_H
