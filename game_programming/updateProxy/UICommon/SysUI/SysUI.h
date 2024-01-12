#ifndef SYSUI_H
#define SYSUI_H
#include <QObject>
#include <QDBusArgument>
#include <QDBusMetaType>
#include <QMetaType>
#include <unordered_map>
#include <QMap>
namespace uicommon
{
    class SysUI: public QObject{
        Q_OBJECT
        Q_ENUMS(TransitionRetCode)
        public:
            /**
             * @brief The return code for the request of displaying (Screens or Popups)
             * 
             */
            enum class TransitionRetCode{
                SuccessRet,   // In case the request is successful (Replace, Stackup)
                FailedRet,    // All the other case (Queue, Dismiss, Store)
                PendingRet,
            }; 


            enum class LayerState{
                INACTIVE = 0,
                ACTIVE,
                QUEUEING,
                BACKGROUND
            };

            enum TransitionType {
                ShowTransition,
                HideTransition,
                QueueTransition,
            };
            Q_ENUM(TransitionType) 

            enum DisplayLayer{
                StartEndLayer,
                CameraLayer,
                DisclamationLayer,
                InterrupDriveLayer,
                EmergencyLayer,
                InstantSettingVolumeLayer,
                InterrupPhoneLayer,
                VALayer,
                CPAAPopupLayer,
                CPAALayer,
                NotifyPopupLayer,
                ChargingInfoLayer,
                GenericPopupLayer,
                DisplayOffLayer,
                OTANotificationLayer,
                SMSLayer,
                MyRoomLayer,
                DesktopLayer,
                DisplayLayerMax
            };
            Q_ENUM(DisplayLayer)

            enum ServiceAACP{
                CARPLAY = 0,
                AndroidAuto
            };
            static QMap<QString, uicommon::SysUI::TransitionType> g_screenStates; 

    };
};
extern bool isScreenRegistered(const QString& screenID);

extern bool isScreenInQueuedState(const QString& screenID);

extern bool isScreenInActiveState(const QString& screenID);

extern bool isScreenInInActiveState(const QString& screenID);

extern void toActiveState(const QString& screenID);

extern void toInActiveState(const QString& screenID);

extern void toQueueState(const QString& screenID);

extern void setScreenState(const QString&, const uicommon::SysUI::TransitionType&);

Q_DECLARE_METATYPE(uicommon::SysUI::TransitionType)
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::SysUI::TransitionType &req);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::SysUI::TransitionType &req);

Q_DECLARE_METATYPE(uicommon::SysUI::TransitionRetCode)
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::SysUI::TransitionRetCode &req);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::SysUI::TransitionRetCode &req);

Q_DECLARE_METATYPE(uicommon::SysUI::ServiceAACP)
QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::SysUI::ServiceAACP &serviceType);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::SysUI::ServiceAACP &serviceType);

#endif //SYSUI_H
