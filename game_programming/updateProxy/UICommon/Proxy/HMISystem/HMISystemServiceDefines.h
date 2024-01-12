#ifndef HMI_SYSTEM_SERVICE_H
#define HMI_SYSTEM_SERVICE_H
#include <QDBusArgument>
#include <QDBusMetaType>
#include <QMetaType>
namespace uicommon{
    enum class HMIApplication : unsigned char
    {
        SETTING_APP=0,
        AC_APP,
        EV_APP,
        PHONE_APP,
        CARPLAY_APP,
        ALEXA_APP,
        NAVI_APP,
        MEDIA_APP,
        PICTURE_APP,
        ALL_APPS,
        HMIApplication_MAX,
    };
    enum class HMIUserInteractiveStatus : unsigned char
    {
        NORMAL=0,
        PRESSED,
        ACTIVE,
        HOVER,
        USER_STATUS_MAX,
    };

    enum class LayoutDisplay : unsigned char
    {
        LEFT_DISPLAY=0,         // Left layout
        RIGHT_DISPLAY,          // Right layout
        INVALID_LAYOUT_DISPLAY = __UINT8_MAX__,
    };
};
Q_DECLARE_METATYPE(uicommon::HMIApplication)
Q_DECLARE_METATYPE(uicommon::HMIUserInteractiveStatus)
Q_DECLARE_METATYPE(uicommon::LayoutDisplay)

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::HMIApplication &app);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::HMIApplication &app);

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::HMIUserInteractiveStatus &userStatus);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::HMIUserInteractiveStatus &userStatus);

QDBusArgument &operator<<(QDBusArgument &argument, const uicommon::LayoutDisplay &userStatus);
const QDBusArgument &operator>>(const QDBusArgument &argument, uicommon::LayoutDisplay &userStatus);

#endif //HMI_SYSTEM_SERVICE_H