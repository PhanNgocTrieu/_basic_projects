#include "IDSAppDef.h"
#include <QHash>
namespace uicommon 
{
    QString getAppName(uicommon::AppID appID)
    {
        switch(appID)
        {
            case uicommon::AppID::AppHome: 
                return "HOME";
            case uicommon::AppID::AppSetting:
                return "1_SETTING_App";
            case uicommon::AppID::AppAC:
                return "2_AC_App";
            case uicommon::AppID::AppEV:
                return "3_EV_App";
            case uicommon::AppID::AppPhone:
                return "4_PHONE_App";
            case uicommon::AppID::AppCarplay:
                return "5_CARPLAY_App";
            case uicommon::AppID::AppNavi:
                return "7_NAVI_App";
            case uicommon::AppID::AppMedia:
                return "8_MEDIA_App";
            case uicommon::AppID::AppPicture:
                return "9_PICTURE_App";
            case uicommon::AppID::AppAndroid:
                return "10_ANDR_App";
            case uicommon::AppID::AppCamera:
                return "11_CAMERA_App";
            case uicommon::AppID::AppFactory:
                return "FACTORY_App";
            case uicommon::AppID::AppPopup:
                return "System_Popup";
            case uicommon::AppID::AppCS:
                return "13_CS_App";
            case uicommon::AppID::AppVA:
                return "12_VA_App";
            case uicommon::AppID::AppDriveRecorder:
                return "Driver_Recorder";
            default:break;
        }
        return "unknown";
    }
    uicommon::AppID getAppID(const QString& appName)
    {
        static QHash<QString, uicommon::AppID> _name_map = 
        {
            {"HOME",            uicommon::AppID::AppHome},
            {"1_SETTING_App",   uicommon::AppID::AppSetting},
            {"2_AC_App",        uicommon::AppID::AppAC},
            {"3_EV_App",        uicommon::AppID::AppEV},
            {"4_PHONE_App",     uicommon::AppID::AppPhone},
            {"5_CARPLAY_App",   uicommon::AppID::AppCarplay},
            {"7_NAVI_App",      uicommon::AppID::AppNavi},
            {"8_MEDIA_App",     uicommon::AppID::AppMedia},
            {"9_PICTURE_App",   uicommon::AppID::AppPicture},
            {"10_ANDR_App",     uicommon::AppID::AppAndroid},
            {"11_CAMERA_App",   uicommon::AppID::AppCamera},
            {"12_VA_App",       uicommon::AppID::AppVA},
            {"13_CS_App",       uicommon::AppID::AppCS},
            {"Driver_Recorder", uicommon::AppID::AppDriveRecorder},
            {"System_Popup",    uicommon::AppID::AppPopup},
            {"FACTORY_App",     uicommon::AppID::AppFactory},
        };
        
        if(auto it = _name_map.find(appName); it != _name_map.end())
        {
            return it.value();
        }
        return uicommon::AppID::AppUnknown;
    }
}