#ifndef WIFIADAPTERAGENCYPROXY_H
#define WIFIADAPTERAGENCYPROXY_H

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
    /*
     * Proxy class for interface ese.hmi.wifiadapter
     */
    class WifiAdapterAgencyProxy : public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        {
            return "ese.hmi.wifiadapter";
        }

    public:
        static WifiAdapterAgencyProxy& getInstance();

        ~WifiAdapterAgencyProxy() {}

    public Q_SLOTS: // METHODS
        inline QDBusPendingReply<int> getPower()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getPower"), argumentList);
        }

        inline QDBusPendingReply<QString> getSSID()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getSSID"), argumentList);
        }

        inline QDBusPendingReply<bool> setPower(int status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setPower"), argumentList);
        }

    protected:
        WifiAdapterAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    Q_SIGNALS: // SIGNALS
        void onPowerChangedSignal(int status);
    };

}
#endif
