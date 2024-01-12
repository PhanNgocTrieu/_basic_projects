#ifndef UICOMMON_MEDIA_AGENCY_INTERFACE_H
#define UICOMMON_MEDIA_AGENCY_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <common/Signal.h>
namespace uicommon
{
    class DBusWatcher: public QObject
    {
        Q_OBJECT
        public:
            DBusWatcher() = default;

            ~DBusWatcher() {}

            void listen();

            inline bool isServiceReady() const
            {
                return m_isServiceReady;
            }

        private:

            bool m_isServiceReady = false;
    };

    class MediaAgencyInterface : public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char* staticInterfaceName()
        {
            return "ese.hmi.MediaAgency";
        };
        static void initialize();

        static bool isServiceReady();

        static MediaAgencyInterface* getInstance();
        
        ~MediaAgencyInterface();
    protected:

        MediaAgencyInterface(const QString& service, const QString& path, const QDBusConnection& connection, QObject* parent = nullptr);
    
    public Q_SLOTS:
        inline QDBusPendingReply<QString> getCurrentService()
        {
            return asyncCall(QStringLiteral("getCurrentService"));
        }

        inline QDBusPendingReply<> requestService(const QString& serviceName, bool force)
        {
            QList<QVariant> argumentList;
            argumentList<< QVariant::fromValue(serviceName);
            argumentList<< QVariant::fromValue(force);
            return asyncCallWithArgumentList(QStringLiteral("requestService"), argumentList);
        }

        inline QDBusPendingReply<> muteAllMediaSource()
        {
            return asyncCall("muteAllMediaSource");
        }

        inline QDBusPendingReply<> unMuteAllMediaSource()
        {
            return asyncCall("unMuteAllMediaSource");
        }

    Q_SIGNALS:
        void onServiceChanged(const QString& oldService, const QString& newService); 
    };
}

#endif //UICOMMON_MEDIA_AGENCY_INTERFACE_H
