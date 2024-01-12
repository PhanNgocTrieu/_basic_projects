#ifndef SERVICE_BUS_AGENCY_PROXY_H
#define SERVICE_BUS_AGENCY_PROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <QByteArray>

namespace uicommon
{
    class ServiceBusAgencyProxy : public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        {
            return "ese.hmi.servicebus";
        }

        static ServiceBusAgencyProxy &getInstance();
        virtual ~ServiceBusAgencyProxy();

    protected:
        ServiceBusAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    public Q_SLOTS:
    inline QDBusPendingReply<> sendData(const QByteArray& data)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(data);
            return asyncCallWithArgumentList(QStringLiteral("sendData"), argumentList);
        }
        //void sendData(const QByteArray& data);
    Q_SIGNALS:
        void dataOnBus(const QByteArray& data);
    };
}

#endif