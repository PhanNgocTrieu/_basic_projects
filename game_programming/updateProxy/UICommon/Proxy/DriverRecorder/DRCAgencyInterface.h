#ifndef DRC_AGENCY_INTERFACE
#define DRC_AGENCY_INTERFACE

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "DRCAgencyDefine.h"
namespace uicommon{
    class DRCAgencyInterface: public QDBusAbstractInterface{
        Q_OBJECT
        public:
            static inline const char* staticInterfaceName(){
                return "ese.hmi.DRCAgency";
            };
            static DRCAgencyInterface& getInstance();
            ~DRCAgencyInterface();
        protected:
            DRCAgencyInterface(const QString& service, const QString& path, const QDBusConnection& connection, QObject* parent = nullptr);
        public Q_SLOTS:
            inline QDBusPendingReply<> requestDRCService(uicommon::DRCAgencyRequest req, int reqValue = 0){
                QList<QVariant> argumentList;
                argumentList<< QVariant::fromValue(req);
                argumentList<<reqValue;
                return asyncCallWithArgumentList(QStringLiteral("requestDRCService"), argumentList);
            }

            inline QDBusPendingReply<QString> getDVRVersion(){
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList(QStringLiteral("getDVRVersion"), argumentList);
            }

            inline QDBusPendingReply<> stopRecordingForTransition()
            {
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("stopRecordingForTransition", argumentList);
            }

            inline QDBusPendingReply<> confirmStopRecoding()
            {
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("confirmStopRecoding", argumentList);
            }

            inline QDBusPendingReply<> indicateEmptyStorage()
            {
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("indicateEmptyStorage", argumentList);
            }

            inline QDBusPendingReply<uicommon::RecordingStatus> getRecordingStatus()
            {
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("getRecordingStatus", argumentList);
            }

            inline QDBusPendingReply<> toPreviewMode()
            {
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("toPreviewMode", argumentList);
            }

            inline QDBusPendingReply<> outPreviewMode()
            {
                QList<QVariant> argumentList;
                return asyncCallWithArgumentList("outPreviewMode", argumentList);
            }
            
            inline QDBusPendingReply<bool> isSDCardPlugIn()
            {
                return asyncCall("isSDCardPlugIn");
            }

            inline QDBusPendingReply<> confirmHighTemperature()
            {
                return asyncCall("confirmHighTemperature");
            }

            inline QDBusPendingReply<> confirmUpdating()
            {
                return asyncCall("confirmUpdating");
            }

            inline QDBusPendingReply<> confirmDropSDCard()
            {
                return asyncCall("confirmDropSDCard");
            }
            
            inline QDBusPendingReply<> confirmFileAccessError()
            {
                return asyncCall("confirmFileAccessError");
            }

            inline QDBusPendingReply<> confirmDisconnectionWithAllowanceToAppearAgain(bool allowed)
            {
                return asyncCall("confirmDisconnectionWithAllowanceToAppearAgain", allowed);
            }

            inline QDBusPendingReply<> confirmResumesRecording()
            {
                return asyncCall("confirmResumesRecording");
            }


        Q_SIGNALS:
            void onSetCalibrationResultChanged(int value);

            void onDRCServiceResponse(uicommon::DRCInvocationResult, uicommon::DRCAgencyRequest, int);

            void onDRVConnectStatusChanged(bool);

            void requestStopRecordingSuccessfully();

            void onRecordingStatusChanged(uicommon::RecordingStatus);

            void onSDCardPlugInOutStatusChanged(bool);
    };
};

#endif //DRC_AGENCY_INTERFACE
