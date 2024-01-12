#ifndef NAVIGATIONSERVICE_H
#define NAVIGATIONSERVICE_H

#include <QQuickImageProvider>
#include <QDBusArgument>
#include <QObject>
#include <navicommwrap/popupfeature.h>

#define NOTIFI_SETTING_CHANGED      "NOTIFI_SETTING_CHANGED"
#define NAVI_ALERT_PREPARE_WINDOW   (0)
#define NAVI_ALERT_DISPLAY_WINDOW   (1)
#define NAVI_ALERT_CLOSE_WINDOW     (2)
#define NAVI_ALERT_REQUEST_CLOSE    (3)

enum HMIScreenType : unsigned char
{
    CenterDisplay,
    MeterDisplay
};

enum NaviboxDisplayType : unsigned short int
{
    NaviFull        = 0,
    NaviLeft_1_3    = 3,
    NaviCenter_1_3  = 4,
    NaviRight_1_3   = 5,
    NaviLeft_2_3    = 1,
    NaviRight_2_3   = 2,
};

enum class NaviEngineState {
    Other,
    RequestDisplayNavi,
    DisplayNavi,
    RequestDisplayProjector,
    DisplayProjector,
    RequestEndNavi,
    EndNavi,
    RequestEndProjector,
    EndProjector,
};

enum class NavigationIPCType : unsigned short int
{
    NotifyMediaStatus,
    MeterRequestDisplay,
    MeterRequestStop,
    NaviReady,
    MediaReady,
    ControlCamera,
    NotifyAlertRequest,
    NotifyAlertInstruction,
	NaviSettingProjector,
    HDMISettingProjector,
    DTVSettingProjector,
    NaviFactoryProjector,
    HDMIFactoryProjector,
    DTVFactoryProjector,
    NaviComponentProjector,
    PopupNotify,
    DTVPopupNotify,
    ChangeNaviTouch,
    HideBlackBackground,
    DTVRequestEnd,
    DTVRequestStart,
    DTVEnd,
    HDMIRequestEnd,
    HDMIRequestStart,
    HDMIEnd,
    ReqDispMTV013,
    ExitMTV013,
    ReqDispDIAG18,
    ExitDIAG18,
    DeleteFuncTouch,
    SyncState,
    ScreenPriority,
    CarplayState,
    AndroidState,
    MaxIPC,
};

enum class NavigationProxyType : unsigned char
{
    Other,
    Media,
    Navi,
    NaviboxCamera,
    MeterCamera,
    Setting,
    Factory,
    SystemPopup,
    NaviboxTouch,
    NaviComponent,
};

enum MeterIndexType : signed char
{
    Invisible = -1,
    Left_1_3  =  0,
    Right_1_3 =  1,
    Left_2_3  =  2,
};

struct PopupInfo {
    int featureId;
    int popupId;
    int hmiMode;
    int timeOut;
    int position;
    int bgdBehaviour;
    int scrBehaviour;
    QString str1;
    QString str2;
    QString str3;
    bool hasIcon;
    int numberSwitch;
    QString swStr1;
    QString swStr2;
    bool hasCheckbox;
    bool isDataMissed;
    bool hasOtherError;

    PopupInfo() = default;
    PopupInfo(const PopupInfo &inst);
    PopupInfo(const DispPopupInstruction &inst);
};

struct PopupResult {
    int featureId;
    int popupId;
    int result;
    int isPressSw1;
    int isPressSw2;
    int isChecked;
    int dummy;
};

class NavigationserviceAdaptor;
class NavigationServiceProxy;

class NavigationService : public QQuickImageProvider
{
    Q_OBJECT
public:
    explicit NavigationService();
    virtual ~NavigationService();
    static void initializeAdaptor(NavigationService *service);
    static NavigationServiceProxy *createProxy(QObject *parent = nullptr);

    void sendDataToProxy(const NavigationIPCType type, const QDBusVariant& var);
    void sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type);
    void sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type, const QDBusVariant& var);
    void sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type, const PopupInfo& info);
    void sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type, const PopupResult& result);
signals:
    void screenLayoutChanged(const QString& config);
    void adaptorDataReceived(const QString& str, const QDBusVariant& var);
    void adaptorNotified(const NavigationIPCType type, const QDBusVariant& var);
    void proxyPrivateNotifed(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const QDBusVariant& var);
    void popupInfoPrivateNotified(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const PopupInfo& info);
    void popupResultPrivateNotified(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const PopupResult& result);
    void onSendPopupRespDisp(const int& featureId, const int& popupId, const int& status, QPrivateSignal);
    void popupResultNotified(const NavigationIPCType type, const PopupResult& result, QPrivateSignal);
    void naviShowOnMeter(const QString& naviType, const int& indexOnMeter,const bool& statusLDD);
    void meterTypeChanged(const int& type);

public slots:
    virtual void showNaviApp(const QString& appId, int dispType) = 0;
    virtual void hideNaviApp(const QString& appId) = 0;
    virtual void sendPopupRespDisp(const int& featureId, const int& popupId, const int& status) = 0;
    //Temporary
    virtual void sendDtvPopupRespDisp(const int& featureId, const int& popupId, const int& status) = 0;
    //
    virtual void sendProxyData(const QString& str, const QDBusVariant& var) = 0;
    virtual void sendDataToAdaptor(const NavigationIPCType type, const QDBusVariant& var) = 0;
    void sendNaviPositionOnMeter(const QString& naviType, const int& position,const bool& statusLDD);
    void sendMeterTypeOnMeter(const int& type);
    void sendDataToAdaptor(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const QDBusVariant& var);
    void sendDataToAdaptor(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const PopupInfo& info);
    void sendDataToAdaptor(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const PopupResult& result);

private:
    static NavigationserviceAdaptor* m_navigationserviceAdaptor;
};

Q_DECLARE_METATYPE(HMIScreenType)
Q_DECLARE_METATYPE(NavigationIPCType)
Q_DECLARE_METATYPE(NavigationProxyType)
Q_DECLARE_METATYPE(NaviboxDisplayType)
Q_DECLARE_METATYPE(PopupInfo)
Q_DECLARE_METATYPE(PopupResult)


QDBusArgument &operator<<(QDBusArgument &argument, const HMIScreenType &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, HMIScreenType &type);

QDBusArgument &operator<<(QDBusArgument &argument, const NavigationIPCType &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, NavigationIPCType &type);

QDBusArgument &operator<<(QDBusArgument &argument, const NavigationProxyType &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, NavigationProxyType &type);

QDBusArgument &operator<<(QDBusArgument &argument, const NaviboxDisplayType &type);
const QDBusArgument &operator>>(const QDBusArgument &argument, NaviboxDisplayType &type);

QDBusArgument &operator<<(QDBusArgument &argument, const PopupInfo& info);
const QDBusArgument &operator>>(const QDBusArgument &argument, PopupInfo &info);

QDBusArgument &operator<<(QDBusArgument &argument, const PopupResult& result);
const QDBusArgument &operator>>(const QDBusArgument &argument, PopupResult &result);

QDebug &operator<<(QDebug &logger, const NavigationIPCType type);
#endif // NAVIGATIONSERVICE_H
