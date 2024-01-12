/*
Adaptor: qdbusxml2cpp -a ConnectedServiceAdaptor -c ConnectedServiceAdaptor -i ConnectedServiceAgency.h ConnectedServiceInf.xml
Proxy: qdbusxml2cpp -p ConnectedServiceProxy -c ConnectedServiceProxy ConnectedServiceInf.xml
*/

#ifndef CONNECTED_SERVICE_
#define CONNECTED_SERVICE_

#include <QObject>
#include <QVariant>
#include <QList>
#include <QString>
#include <QDBusVariant>
#include <QDBusArgument>
#include "UICommon_global.h"
namespace uicommon {
    class UICOMMON_EXPORT ConnectedServiceAgency : public QObject {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.csif")
        public:
            virtual ~ConnectedServiceAgency() {}

        public slots:
            virtual void requestStartCall() = 0;
            virtual void requestEndCall() = 0;
            virtual void requestDeleteDigitalKey() = 0;
            virtual void requestResetNetwork() = 0;
            virtual bool requestGetDigitalKeyActiveStatus() = 0;
            virtual void requestSetDigitalKeySettingStatus(bool active) = 0;
            virtual bool requestGetDigitalKeySettingStatus() = 0;
            // virtual QList<srvwrp::ConnectedServiceWrapper::ImageDataBase64> requestListWallPaperDownload() = 0;

        Q_SIGNALS: // SIGNALS
            void onCompletedStartOpening();
            void onConnectedChanged(const bool _tele, const bool _conSetFlag);
            void onConnectedListChanged(const QString &conInfList);
            void onDCMWaveStatusChanged(const int dcmWaveStatus);
            void onDigitalKeyActiveStatusChanged(bool dcmWaveStatus);
            void onDigitalKeyResponseResult(const int digKeyRespRes);
            void onDigitalKeySettingStatusChanged(bool value);
            // void onInforChanged(const QList<srvwrp::ConnectedServiceWrapper::ConnectedInformation> &listConnectedInf);
            void onNetworkResultChanged(const int networkResult);
            void wallpaperDownloadStatusChanged(int wallDownStt);

    };
}

#endif // CONNECTED_SERVICE_