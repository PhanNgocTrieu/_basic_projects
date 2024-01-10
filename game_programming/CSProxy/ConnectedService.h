/*
~/Qt/6.2.9/gcc_64/bin/qdbusxml2cpp -l ConnectedService -c ConnectedServiceInf -a ConnectedServiceAdaptor -p ConnectedServiceProxy ConnectedServiceInf.xml
*/

#ifndef CONNECTED_SERVICE_
#define CONNECTED_SERVICE_

#include <QObject>
#include <QVariant>
#include <QList>
#include <QString>
#include <QDBusVariant>
#include <QDBusArgument
#if 0
#include "UICommon_global.h"
#define UICOMMON_EXPORT Q_DECL_EXPORT
#endif
namespace uicommon {
    class 
#if 0
    UICOMMON_EXPORT
#endif 
    ConnectedService : public QObject{
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.csif")
        public:
            virtual ~ConnectedService();

        public slots:
            virtual void requestStartCall() = 0;
            virtual void requestEndCall() = 0;
            virtual void requestDeleteDigitalKey() = 0;
            virtual void requestResetNetwork() = 0;
            virtual void requestSetDigitalKeyActiveStatus(int active) = 0;
            virtual int requestGetDigitalKeyActiveStatus() = 0;
            virtual void requestSetDigitalKeySettingStatus(int active) = 0;
            virtual int requestGetDigitalKeySettingStatus() = 0;
            virtual QList<srvwrp::ConnectedServiceWrapper::ImageDataBase64> requestListWallPaperDownload() = 0;

        Q_SIGNALS: // SIGNALS
            void onCompletedStartOpening();
            void onConnectedChanged(const QString &signalName, const QDBusVariant &value);
            void onConnectedListChanged(const QString &conInfList);
            void onDCMWaveStatusChanged(const int dcmWaveStatus);
            void onDigitalKeyActiveStatusChanged(bool dcmWaveStatus);
            void onDigitalKeyResponseResult(const int digKeyRespRes);
            void onDigitalKeySettingStatusChanged(bool value);
            void onInforChanged(const QList<srvwrp::ConnectedServiceWrapper::ConnectedInformation> &listConnectedInf);
            void onNetworkResultChanged(const int networkResult);
            void wallpaperDownloadStatusChanged(int wallDownStt);

    };
}

#endif // CONNECTED_SERVICE_