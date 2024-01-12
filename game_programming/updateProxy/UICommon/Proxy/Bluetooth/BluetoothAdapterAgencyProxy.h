#ifndef BLUETOOTHADAPTERAGENCYPROXY_H
#define BLUETOOTHADAPTERAGENCYPROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

namespace uicommon
{
    class BluetoothAdapterAgencyProxy : public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        {
            return "ese.hmi.btadapter";
        }

        static BluetoothAdapterAgencyProxy& getInstance();

        ~BluetoothAdapterAgencyProxy();

    protected:
        BluetoothAdapterAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);    

    public Q_SLOTS: // METHODS
        inline QDBusPendingReply<int> getPower()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getPower"), argumentList);
        }

        inline QDBusPendingReply<bool> setPower(int status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setPower"), argumentList);
        }

    Q_SIGNALS: // SIGNALS
        void onPowerChangedSignal(int status);
        void onPairFinishedSignal(bool successFlag);
    };

}
#endif
