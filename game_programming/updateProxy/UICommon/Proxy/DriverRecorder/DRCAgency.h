#ifndef DRC_AGENCY_H
#define DRC_AGENCY_H

#include <QObject>
#include "DRCAgencyDefine.h"
namespace uicommon {
    class DRCAgency: public QObject {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.DRCAgency")
        public:
            virtual ~DRCAgency() {}

        public slots:
            virtual void requestDRCService(uicommon::DRCAgencyRequest req, int reqValue = 0) = 0;

            virtual QString getDVRVersion() = 0;

            virtual void stopRecordingForTransition() = 0;

            virtual void confirmStopRecoding() = 0;

            virtual void indicateEmptyStorage() = 0;


            virtual uicommon::RecordingStatus getRecordingStatus() = 0;

            virtual void toPreviewMode() = 0;

            virtual void outPreviewMode() = 0;

            virtual bool isSDCardPlugIn() = 0;

            virtual void confirmHighTemperature() = 0;

            virtual void confirmDisconnectionWithAllowanceToAppearAgain(bool) = 0;

            virtual void confirmUpdating() = 0;

            virtual void confirmDropSDCard() = 0;

            virtual void confirmFileAccessError() = 0;

            virtual void confirmResumesRecording() = 0;


        signals:
            void onSetCalibrationResultChanged(int result);  

            void onDRCServiceResponse(uicommon::DRCInvocationResult, uicommon::DRCAgencyRequest, int);  

            void onDRVConnectStatusChanged(bool);

            void requestStopRecordingSuccessfully();

            void onRecordingStatusChanged(uicommon::RecordingStatus);

            void onSDCardPlugInOutStatusChanged(bool); 

        protected:  
            DRCAgency() = default;
            uicommon::RecordingStatus m_recordingStatus = uicommon::RecordingStatus::NOT_CONNECTED;
    };
}


#endif // DRC_AGENCY_H
