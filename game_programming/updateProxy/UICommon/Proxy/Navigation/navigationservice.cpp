#include <QDBusArgument>
#include <QDBusMetaType>
#include "navigationservice.h"
#include "NavigationServiceAdaptor.h"
#include "NavigationServiceProxy.h"

#define DBUS_SERVICE_NAME   "ese.hmi.navigationservice"
#define DBUS_OBJECT_NAME   "/navigationservice"

// START - Fix klocwork MLK.MUST
NavigationserviceAdaptor* NavigationService::m_navigationserviceAdaptor = nullptr;
// END - Fix klocwork MLK.MUST

NavigationService::NavigationService(): QQuickImageProvider(QQuickImageProvider::Image)
{
}

NavigationService::~NavigationService()
{
    // START - Fix klocwork MLK.MUST
    if (m_navigationserviceAdaptor != nullptr) {
        delete m_navigationserviceAdaptor;
        m_navigationserviceAdaptor = nullptr;
    }
    // END - Fix klocwork MLK.MUST
}

void NavigationService::initializeAdaptor(NavigationService *service)
{
    qRegisterMetaType<HMIScreenType>("HMIScreenType");
    qDBusRegisterMetaType<HMIScreenType>();

    qRegisterMetaType<NaviboxDisplayType>("NaviboxDisplayType");
    qDBusRegisterMetaType<NaviboxDisplayType>();

    qRegisterMetaType<PopupInfo>("PopupInfo");
    qDBusRegisterMetaType<PopupInfo>();

    qRegisterMetaType<PopupResult>("PopupResult");
    qDBusRegisterMetaType<PopupResult>();

    // START - Fix klocwork MLK.MUST
    if (m_navigationserviceAdaptor != nullptr) {
        delete m_navigationserviceAdaptor;
        m_navigationserviceAdaptor = nullptr;
    }
    m_navigationserviceAdaptor = new NavigationserviceAdaptor(service);
    // END - Fix klocwork MLK.MUST

    QDBusConnection::sessionBus().registerObject(DBUS_OBJECT_NAME, service);
    QDBusConnection::sessionBus().registerService(DBUS_SERVICE_NAME);
}

NavigationServiceProxy *NavigationService::createProxy(QObject *parent)
{
    qRegisterMetaType<HMIScreenType>("HMIScreenType");
    qDBusRegisterMetaType<HMIScreenType>();

    qRegisterMetaType<NavigationIPCType>("NavigationIPCType");
    qDBusRegisterMetaType<NavigationIPCType>();

    qRegisterMetaType<NavigationProxyType>("NavigationProxyType");
    qDBusRegisterMetaType<NavigationProxyType>();

    qRegisterMetaType<NaviboxDisplayType>("NaviboxDisplayType");
    qDBusRegisterMetaType<NaviboxDisplayType>();

    qRegisterMetaType<PopupInfo>("PopupInfo");
    qDBusRegisterMetaType<PopupInfo>();

    qRegisterMetaType<PopupResult>("PopupResult");
    qDBusRegisterMetaType<PopupResult>();

    NavigationServiceProxy *proxy = new NavigationServiceProxy(DBUS_SERVICE_NAME, DBUS_OBJECT_NAME, QDBusConnection::sessionBus(), parent);
    return proxy;
}

void NavigationService::sendDataToProxy(const NavigationIPCType type, const QDBusVariant &var)
{
    emit adaptorNotified(type, var);
}

void NavigationService::sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type)
{
    emit proxyPrivateNotifed(0, proxyType, type, QDBusVariant(-1));
}

void NavigationService::sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type, const QDBusVariant &var)
{
    emit proxyPrivateNotifed(0, proxyType, type, var);
}

void NavigationService::sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type, const PopupInfo &info)
{
    emit popupInfoPrivateNotified(0, proxyType, type, info);
}

void NavigationService::sendDataToProxy(const NavigationProxyType proxyType, const NavigationIPCType type, const PopupResult &result)
{
    emit popupResultPrivateNotified(0, proxyType, type, result);
}

void NavigationService::sendDataToAdaptor(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const QDBusVariant &var)
{
    emit proxyPrivateNotifed(id, proxyType, type, var);
}

void NavigationService::sendDataToAdaptor(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const PopupInfo &info)
{
    emit popupInfoPrivateNotified(id, proxyType, type, info);
}

void NavigationService::sendNaviPositionOnMeter(const QString& naviType, const int& position,const bool& statusLDD)
{
    emit naviShowOnMeter(naviType, position,statusLDD);
}

void NavigationService::sendMeterTypeOnMeter(const int& type)
{
    emit meterTypeChanged(type);
}

void NavigationService::sendDataToAdaptor(const uint id, const NavigationProxyType proxyType, const NavigationIPCType type, const PopupResult &result)
{
    if ((id == 0) && (proxyType == NavigationProxyType::Other)) {
        emit popupResultNotified(type, result, {});
    } else {
        emit popupResultPrivateNotified(id, proxyType, type, result);
    }
}

QDBusArgument &operator<<(QDBusArgument &argument, const HMIScreenType &type)
{
    argument.beginStructure();
    argument<<static_cast<uint8_t>(type);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, HMIScreenType &type)
{
    uint8_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<HMIScreenType>(resValue);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const NavigationIPCType &type)
{
    argument.beginStructure();
    argument<<static_cast<uint16_t>(type);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, NavigationIPCType &type)
{
    uint16_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<NavigationIPCType>(resValue);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const NavigationProxyType &type)
{
    argument.beginStructure();
    argument<<static_cast<uint8_t>(type);
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, NavigationProxyType &type)
{
    uint8_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<NavigationProxyType>(resValue);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const NaviboxDisplayType &type)
{
    argument.beginStructure();
    argument<<static_cast<uint16_t>(type);
    argument.endStructure();
    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, NaviboxDisplayType &type)
{
    uint16_t resValue = 0;
    argument.beginStructure();
    argument >> resValue;
    argument.endStructure();
    type = static_cast<NaviboxDisplayType>(resValue);
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const PopupInfo& info)
{
    argument.beginStructure();
    argument << info.featureId;
    argument << info.popupId;
    argument << info.hmiMode;
    argument << info.timeOut;
    argument << info.position;
    argument << info.bgdBehaviour;
    argument << info.scrBehaviour;
    argument << info.str1;
    argument << info.str2;
    argument << info.str3;
    argument << info.hasIcon;
    argument << info.numberSwitch;
    argument << info.swStr1;
    argument << info.swStr2;
    argument << info.hasCheckbox;
    argument << info.isDataMissed;
    argument << info.hasOtherError;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, PopupInfo &info)
{
    argument.beginStructure();
    argument >> info.featureId;
    argument >> info.popupId;
    argument >> info.hmiMode;
    argument >> info.timeOut;
    argument >> info.position;
    argument >> info.bgdBehaviour;
    argument >> info.scrBehaviour;
    argument >> info.str1;
    argument >> info.str2;
    argument >> info.str3;
    argument >> info.hasIcon;
    argument >> info.numberSwitch;
    argument >> info.swStr1;
    argument >> info.swStr2;
    argument >> info.hasCheckbox;
    argument >> info.isDataMissed;
    argument >> info.hasOtherError;
    argument.endStructure();

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const PopupResult& result)
{
    argument.beginStructure();
    argument << result.featureId;
    argument << result.popupId;
    argument << result.result;
    argument << result.isPressSw1;
    argument << result.isPressSw2;
    argument << result.isChecked;
    argument << result.dummy;
    argument.endStructure();

    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, PopupResult &result)
{
    argument.beginStructure();
    argument >> result.featureId;
    argument >> result.popupId;
    argument >> result.result;
    argument >> result.isPressSw1;
    argument >> result.isPressSw2;
    argument >> result.isChecked;
    argument >> result.dummy;
    argument.endStructure();

    return argument;
}

PopupInfo::PopupInfo(const PopupInfo &inst)
{
    this->featureId = inst.featureId;
    this->popupId = inst.popupId;
    this->hmiMode = inst.hmiMode;
    this->timeOut = inst.timeOut;
    this->position = inst.position;
    this->bgdBehaviour = inst.bgdBehaviour;
    this->scrBehaviour = inst.scrBehaviour;
    this->str1 = inst.str1;
    this->str2 = inst.str2;
    this->str3 = inst.str3;
    this->hasIcon = inst.hasIcon;
    this->numberSwitch = inst.numberSwitch;
    this->swStr1 = inst.swStr1;
    this->swStr2 = inst.swStr2;
    this->hasCheckbox = inst.hasCheckbox;
    this->isDataMissed = inst.isDataMissed;
    this->hasOtherError = inst.hasOtherError;
}

PopupInfo::PopupInfo(const DispPopupInstruction &inst)
{
    this->featureId = static_cast<int>(inst.featureId);
    this->popupId = static_cast<int>(inst.popupId);
    this->hmiMode = static_cast<int>(inst.hmiMode);
    this->timeOut = static_cast<int>(inst.timeOut);
    this->position = inst.position;
    this->bgdBehaviour = inst.bgdBehaviour;
    this->scrBehaviour = inst.scrBehaviour;
    this->str1 = QString::fromStdString(inst.str1);
    this->str2 = QString::fromStdString(inst.str2);
    this->str3 = QString::fromStdString(inst.str3);
    this->hasIcon = inst.hasIcon;
    this->numberSwitch = static_cast<int>(inst.numberSwitch);
    this->swStr1 = QString::fromStdString(inst.swStr1);
    this->swStr2 = QString::fromStdString(inst.swStr2);
    this->hasCheckbox = inst.hasCheckbox;
    this->isDataMissed = inst.isDataMissed;
    this->hasOtherError = inst.hasOtherError;
}

QDebug &operator<<(QDebug &logger, const NavigationIPCType type)
{
    static const QStringList types = {
        "NotifyMediaStatus",
        "MeterRequestDisplay",
        "MeterRequestStop",
        "NaviReady",
        "MediaReady",
        "ControlCamera",
        "NotifyAlertRequest",
        "NotifyAlertInstruction",
        "NaviSettingProjector",
        "HDMISettingProjector",
        "DTVSettingProjector",
        "NaviFactoryProjector",
        "HDMIFactoryProjector",
        "DTVFactoryProjector",
        "NaviComponentProjector",
        "PopupNotify",
        "DTVPopupNotify",
        "ChangeNaviTouch",
        "HideBlackBackground",
        "DTVRequestEnd",
        "DTVRequestStart",
        "DTVEnd",
        "HDMIRequestEnd",
        "HDMIRequestStart",
        "HDMIEnd",
        "ReqDispMTV013",
        "ExitMTV013",
        "ReqDispDIAG18",
        "ExitDIAG18",
        "DeleteFuncTouch",
        "SyncState",
        "ScreenPriority",
        "CarplayState",
        "AndroidState",
        "MaxIPC",
    };
    uint16_t index = static_cast<uint16_t>(type);

    if (index < types.length()) {
        logger << types[index] << "(" << static_cast<int>(type) << ")";
    } else {
        logger << "Other";
    }

    return logger.maybeSpace();
}
