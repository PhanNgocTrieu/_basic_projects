#ifndef UICOMMON_IDSAPP_DEF_H
#define UICOMMON_IDSAPP_DEF_H

#include <QString>

namespace uicommon
{
    enum AppID
    {
        AppHome     = 0,
        AppSetting  = 1,
        AppAC       = 2,
        AppEV       = 3,
        AppPhone    = 4,
        AppCarplay  = 5,
        AppNavi     = 6,
        AppMedia    = 7,
        AppPicture  = 8,
        AppAndroid  = 9,
        AppCamera   = 10,
        AppFactory  = 11,
        AppPopup    = 12,
        AppCS       = 13,
        AppVA       = 14,
        AppDriveRecorder = 15,
        AppUnknown = 16,
    };
    QString getAppName(uicommon::AppID appID);
    uicommon::AppID getAppID(const QString& appName);
}
#endif //UICOMMON_IDSAPP_DEF_H