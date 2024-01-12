#ifndef DRC_AGENCY_DEFINE_H
#define DRC_AGENCY_DEFINE_H
#include <QDBusArgument>
#include <QDBusMetaType>
#include <QMetaType>
namespace uicommon{
    Q_NAMESPACE
    enum class DRCAgencyRequest: int{
        INVALID_REQUEST = -1,
        DRCAgencyRequest_MIN,
        GET_DRV_VERSION,
        FORMAT_SD_CARD,
        SET_G_SENSOR_CALIBRATION,
        GET_RESOLUTION,
        SET_RESOLUTION,
        GET_G_SENSOR,
        SET_G_SENSOR,
        GET_RECORDER_SOUND,
        SET_RECORDER_SOUND,
        GET_BEEP_SOUND_SENSING,
        SET_BEEP_SOUND_SENSING,
        GET_PARKING_MODE,
        SET_PARKING_MODE,
        GET_PARKING_MODE_NOTIFY_NEW_PARKING,
        SET_PARKING_MODE_NOTIFY_NEW_PARKING,
        GET_PARKING_MODE_G_SENSOR,
        SET_PARKING_MODE_G_SENSOR,
        GET_PARKING_MODE_RECORDING_TIME,
        SET_PARKING_MODE_RECORDING_TIME,
        GET_PARKING_MODE_OFF_PARKING_INVALID_TIME,
        SET_PARKING_MODE_OFF_PARKING_INVALID_TIME,
        GET_BEEP_SOUND_STARTING,
        SET_BEEP_SOUND_STARTING,
        GET_BEEP_SOUND_WARNING,
        SET_BEEP_SOUND_WARNING,
        GET_START_SOUND,
        SET_START_SOUND,
        SET_DISPLAY_CONSTRAST,
        GET_DISPLAY_CONSTRAT,
        SET_DISPLAY_SHADE,
        GET_DISPLAY_SHADE,
        RESET_SETTING,
        DRCAgencyRequest_MAX
    };

    enum class RecordingStatus: int
    {
        PREVIEW_ERROR = 0,
        PREVIEW_NORMAL,
        MANUAL_RECORDING_ERROR,
        MANUAL_RECORDING_NORMAL,
        AUTO_RECORDING_ERROR,
        AUTO_RECORDING_NORMAL,
        NOT_CONNECTED,
        UNKNOWN,
    };
    Q_ENUMS(RecordingStatus)

    enum class DRCInvocationResult: int{
        RESULT_SUCCESS=0,
        RESULT_FAILED,
    };

    template<typename _T>
    _T& operator<<(_T& log, const uicommon::RecordingStatus& val)
    {
        switch(val)
        {
            case uicommon::RecordingStatus::PREVIEW_ERROR:
            {
                log << "[PREVIEW_ERROR]";
                break;
            }
            case uicommon::RecordingStatus::PREVIEW_NORMAL:
            {
                log << "[PREVIEW_NORMAL]";
                break;
            }
            case uicommon::RecordingStatus::MANUAL_RECORDING_ERROR:
            {
                log << "[MANUAL_ERROR]";
                break;
            }
            case uicommon::RecordingStatus::MANUAL_RECORDING_NORMAL:
            {
                log << "[MANUAL_NORMAL]";
                break;
            }
            case uicommon::RecordingStatus::AUTO_RECORDING_ERROR:
            {
                log << "[AUTO_ERROR]";
                break;
            }
            case uicommon::RecordingStatus::AUTO_RECORDING_NORMAL:
            {
                log << "[AUTO_NORMAL]";
                break;
            }
            case uicommon::RecordingStatus::NOT_CONNECTED:
            {
                log << "[NOT_CONNECTED]";
                break;
            }
            default:
            {
                log << "[UNKNOWN]";
                break;
            } 
        }
        return log;
    }
}

Q_DECLARE_METATYPE(uicommon::DRCAgencyRequest)

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::DRCAgencyRequest &req);

const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::DRCAgencyRequest &req);

Q_DECLARE_METATYPE(uicommon::DRCInvocationResult)

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::DRCInvocationResult &req);

const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::DRCInvocationResult &req);

Q_DECLARE_METATYPE(uicommon::RecordingStatus)

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::RecordingStatus &status);

const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::RecordingStatus &status);


#endif
