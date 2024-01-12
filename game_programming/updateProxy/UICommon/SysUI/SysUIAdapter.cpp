/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i systemifapps_adaptor.h -a :systemifapps_adaptor.cpp ../../../native/HOME_App/IPC/systemifapps.xml
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "SysUIAdapter.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class SysifappsAdaptor
 */

SysifappsAdaptor::SysifappsAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

SysifappsAdaptor::~SysifappsAdaptor()
{
    // destructor
}

QStringList SysifappsAdaptor::sERVICE_SURFACE() const
{
    // get the value of property SERVICE_SURFACE
    return qvariant_cast< QStringList >(parent()->property("SERVICE_SURFACE"));
}

QString SysifappsAdaptor::appID() const
{
    // get the value of property appID
    return qvariant_cast< QString >(parent()->property("appID"));
}

void SysifappsAdaptor::setAppID(const QString &value)
{
    // set the value of property appID
    parent()->setProperty("appID", QVariant::fromValue(value));
}

QString SysifappsAdaptor::appIdTiel() const
{
    // get the value of property appIdTiel
    return qvariant_cast< QString >(parent()->property("appIdTiel"));
}

void SysifappsAdaptor::setAppIdTiel(const QString &value)
{
    // set the value of property appIdTiel
    parent()->setProperty("appIdTiel", QVariant::fromValue(value));
}

bool SysifappsAdaptor::cameraIsOn() const
{
    // get the value of property cameraIsOn
    return qvariant_cast< bool >(parent()->property("cameraIsOn"));
}

void SysifappsAdaptor::setCameraIsOn(bool value)
{
    // set the value of property cameraIsOn
    parent()->setProperty("cameraIsOn", QVariant::fromValue(value));
}

QString SysifappsAdaptor::childAppActive() const
{
    // get the value of property childAppActive
    return qvariant_cast< QString >(parent()->property("childAppActive"));
}

void SysifappsAdaptor::setChildAppActive(const QString &value)
{
    // set the value of property childAppActive
    parent()->setProperty("childAppActive", QVariant::fromValue(value));
}

QString SysifappsAdaptor::currentApplication() const
{
    // get the value of property currentApplication
    return qvariant_cast< QString >(parent()->property("currentApplication"));
}

void SysifappsAdaptor::setCurrentApplication(const QString &value)
{
    // set the value of property currentApplication
    parent()->setProperty("currentApplication", QVariant::fromValue(value));
}

QString SysifappsAdaptor::currentMediaType() const
{
    // get the value of property currentMediaType
    return qvariant_cast< QString >(parent()->property("currentMediaType"));
}

void SysifappsAdaptor::setCurrentMediaType(const QString &value)
{
    // set the value of property currentMediaType
    parent()->setProperty("currentMediaType", QVariant::fromValue(value));
}

int SysifappsAdaptor::currentMeterType() const
{
    // get the value of property currentMeterType
    return qvariant_cast< int >(parent()->property("currentMeterType"));
}

void SysifappsAdaptor::setCurrentMeterType(int value)
{
    // set the value of property currentMeterType
    parent()->setProperty("currentMeterType", QVariant::fromValue(value));
}

QString SysifappsAdaptor::currentPopupPath() const
{
    // get the value of property currentPopupPath
    return qvariant_cast< QString >(parent()->property("currentPopupPath"));
}

void SysifappsAdaptor::setCurrentPopupPath(const QString &value)
{
    // set the value of property currentPopupPath
    parent()->setProperty("currentPopupPath", QVariant::fromValue(value));
}

QString SysifappsAdaptor::currentScreenPath() const
{
    // get the value of property currentScreenPath
    return qvariant_cast< QString >(parent()->property("currentScreenPath"));
}

void SysifappsAdaptor::setCurrentScreenPath(const QString &value)
{
    // set the value of property currentScreenPath
    parent()->setProperty("currentScreenPath", QVariant::fromValue(value));
}

QVariantList SysifappsAdaptor::defaultApps() const
{
    // get the value of property defaultApps
    return qvariant_cast< QVariantList >(parent()->property("defaultApps"));
}

void SysifappsAdaptor::setDefaultApps(const QVariantList &value)
{
    // set the value of property defaultApps
    parent()->setProperty("defaultApps", QVariant::fromValue(value));
}

QVariantList SysifappsAdaptor::defaultBarApps() const
{
    // get the value of property defaultBarApps
    return qvariant_cast< QVariantList >(parent()->property("defaultBarApps"));
}

void SysifappsAdaptor::setDefaultBarApps(const QVariantList &value)
{
    // set the value of property defaultBarApps
    parent()->setProperty("defaultBarApps", QVariant::fromValue(value));
}

QVariantList SysifappsAdaptor::defaultLayout() const
{
    // get the value of property defaultLayout
    return qvariant_cast< QVariantList >(parent()->property("defaultLayout"));
}

void SysifappsAdaptor::setDefaultLayout(const QVariantList &value)
{
    // set the value of property defaultLayout
    parent()->setProperty("defaultLayout", QVariant::fromValue(value));
}

int SysifappsAdaptor::layoutType() const
{
    // get the value of property layoutType
    return qvariant_cast< int >(parent()->property("layoutType"));
}

void SysifappsAdaptor::setLayoutType(int value)
{
    // set the value of property layoutType
    parent()->setProperty("layoutType", QVariant::fromValue(value));
}

bool SysifappsAdaptor::showTestApp() const
{
    // get the value of property showTestApp
    return qvariant_cast< bool >(parent()->property("showTestApp"));
}

void SysifappsAdaptor::setShowTestApp(bool value)
{
    // set the value of property showTestApp
    parent()->setProperty("showTestApp", QVariant::fromValue(value));
}

bool SysifappsAdaptor::showUSBheader() const
{
    // get the value of property showUSBheader
    return qvariant_cast< bool >(parent()->property("showUSBheader"));
}

void SysifappsAdaptor::setShowUSBheader(bool value)
{
    // set the value of property showUSBheader
    parent()->setProperty("showUSBheader", QVariant::fromValue(value));
}


void SysifappsAdaptor::backToHomeScreen()
{
    // handle method call hmi.service.sysifapps.backToHomeScreen
    QMetaObject::invokeMethod(parent(), "backToHomeScreen");
}

void SysifappsAdaptor::backToPreviousScreen()
{
    // handle method call hmi.service.sysifapps.backToPreviousScreen
    QMetaObject::invokeMethod(parent(), "backToPreviousScreen");
}

void SysifappsAdaptor::callToExpandMaxsize(const QString &appId)
{
    // handle method call hmi.service.sysifapps.callToExpandMaxsize
    QMetaObject::invokeMethod(parent(), "callToExpandMaxsize", Q_ARG(QString, appId));
}

void SysifappsAdaptor::callToExpandMaxsize(const QString &appId, bool isFullExpand)
{
    // handle method call hmi.service.sysifapps.callToExpandMaxsize
    QMetaObject::invokeMethod(parent(), "callToExpandMaxsize", Q_ARG(QString, appId), Q_ARG(bool, isFullExpand));
}

void SysifappsAdaptor::callToExpandMaxsize(const QString &appId, bool isFullExpand, int screenType)
{
    // handle method call hmi.service.sysifapps.callToExpandMaxsize
    QMetaObject::invokeMethod(parent(), "callToExpandMaxsize", Q_ARG(QString, appId), Q_ARG(bool, isFullExpand), Q_ARG(int, screenType));
}

void SysifappsAdaptor::callToExpandMaxsize(const QString &appId, bool isFullExpand, int screenType, bool enableHeader)
{
    // handle method call hmi.service.sysifapps.callToExpandMaxsize
    QMetaObject::invokeMethod(parent(), "callToExpandMaxsize", Q_ARG(QString, appId), Q_ARG(bool, isFullExpand), Q_ARG(int, screenType), Q_ARG(bool, enableHeader));
}

void SysifappsAdaptor::callToShowInternalPopup(const QString &appId)
{
    // handle method call hmi.service.sysifapps.callToShowInternalPopup
    QMetaObject::invokeMethod(parent(), "callToShowInternalPopup", Q_ARG(QString, appId));
}

void SysifappsAdaptor::callToShowInternalPopup(const QString &appId, bool isShowPopup)
{
    // handle method call hmi.service.sysifapps.callToShowInternalPopup
    QMetaObject::invokeMethod(parent(), "callToShowInternalPopup", Q_ARG(QString, appId), Q_ARG(bool, isShowPopup));
}

void SysifappsAdaptor::callToShowTopScreen(const QString &appId)
{
    // handle method call hmi.service.sysifapps.callToShowTopScreen
    QMetaObject::invokeMethod(parent(), "callToShowTopScreen", Q_ARG(QString, appId));
}

void SysifappsAdaptor::callToShowTopScreen(const QString &appId, bool isShowTop)
{
    // handle method call hmi.service.sysifapps.callToShowTopScreen
    QMetaObject::invokeMethod(parent(), "callToShowTopScreen", Q_ARG(QString, appId), Q_ARG(bool, isShowTop));
}

void SysifappsAdaptor::changeDisplayOnOff()
{
    // handle method call hmi.service.sysifapps.changeDisplayOnOff
    QMetaObject::invokeMethod(parent(), "changeDisplayOnOff");
}

void SysifappsAdaptor::changeScreenSize(const QString &Apps)
{
    // handle method call hmi.service.sysifapps.changeScreenSize
    QMetaObject::invokeMethod(parent(), "changeScreenSize", Q_ARG(QString, Apps));
}

void SysifappsAdaptor::checkCurrentScreen()
{
    // handle method call hmi.service.sysifapps.checkCurrentScreen
    QMetaObject::invokeMethod(parent(), "checkCurrentScreen");
}

void SysifappsAdaptor::collectApp(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4, const QString &in5, const QString &in6)
{
    // handle method call hmi.service.sysifapps.collectApp
    QMetaObject::invokeMethod(parent(), "collectApp", Q_ARG(QString, in0), Q_ARG(QString, in1), Q_ARG(QString, in2), Q_ARG(QString, in3), Q_ARG(QString, in4), Q_ARG(QString, in5), Q_ARG(QString, in6));
}

void SysifappsAdaptor::enableMultitouchSettingScreen(bool isEnable)
{
    // handle method call hmi.service.sysifapps.enableMultitouchSettingScreen
    QMetaObject::invokeMethod(parent(), "enableMultitouchSettingScreen", Q_ARG(bool, isEnable));
}

void SysifappsAdaptor::getAppIDForSignalReturnToTopScreen(const QString &appID)
{
    // handle method call hmi.service.sysifapps.getAppIDForSignalReturnToTopScreen
    QMetaObject::invokeMethod(parent(), "getAppIDForSignalReturnToTopScreen", Q_ARG(QString, appID));
}

void SysifappsAdaptor::getAppIdForHeader(const QString &appId)
{
    // handle method call hmi.service.sysifapps.getAppIdForHeader
    QMetaObject::invokeMethod(parent(), "getAppIdForHeader", Q_ARG(QString, appId));
}

void SysifappsAdaptor::getCurrentMeterType()
{
    // handle method call hmi.service.sysifapps.getCurrentMeterType
    QMetaObject::invokeMethod(parent(), "getCurrentMeterType");
}

void SysifappsAdaptor::getDataThroughSys(const QString &in0, const QDBusVariant &var)
{
    // handle method call hmi.service.sysifapps.getDataThroughSys
    QMetaObject::invokeMethod(parent(), "getDataThroughSys", Q_ARG(QString, in0), Q_ARG(QDBusVariant, var));
}

void SysifappsAdaptor::getErrorCodeForTest(const QString &appId, const QString &errorCode)
{
    // handle method call hmi.service.sysifapps.getErrorCodeForTest
    QMetaObject::invokeMethod(parent(), "getErrorCodeForTest", Q_ARG(QString, appId), Q_ARG(QString, errorCode));
}

void SysifappsAdaptor::getFavoriteFromApps(const QString &appId, int eventId)
{
    // handle method call hmi.service.sysifapps.getFavoriteFromApps
    QMetaObject::invokeMethod(parent(), "getFavoriteFromApps", Q_ARG(QString, appId), Q_ARG(int, eventId));
}

void SysifappsAdaptor::getNewDefaultBarApps(const QString &first, const QString &second, const QString &third, const QString &fourth, const QString &fifth)
{
    // handle method call hmi.service.sysifapps.getNewDefaultBarApps
    QMetaObject::invokeMethod(parent(), "getNewDefaultBarApps", Q_ARG(QString, first), Q_ARG(QString, second), Q_ARG(QString, third), Q_ARG(QString, fourth), Q_ARG(QString, fifth));
}

void SysifappsAdaptor::getNewSettingInfo(const QString &first, const QString &second, const QString &third)
{
    // handle method call hmi.service.sysifapps.getNewSettingInfo
    QMetaObject::invokeMethod(parent(), "getNewSettingInfo", Q_ARG(QString, first), Q_ARG(QString, second), Q_ARG(QString, third));
}

void SysifappsAdaptor::getPositionToTransfer(double x, double y, const QString &tempId)
{
    // handle method call hmi.service.sysifapps.getPositionToTransfer
    QMetaObject::invokeMethod(parent(), "getPositionToTransfer", Q_ARG(double, x), Q_ARG(double, y), Q_ARG(QString, tempId));
}

void SysifappsAdaptor::getPositionToTransfer(double x, double y, const QString &tempId, bool dbClick)
{
    // handle method call hmi.service.sysifapps.getPositionToTransfer
    QMetaObject::invokeMethod(parent(), "getPositionToTransfer", Q_ARG(double, x), Q_ARG(double, y), Q_ARG(QString, tempId), Q_ARG(bool, dbClick));
}

void SysifappsAdaptor::getPositionToTransfer(double x, double y, const QString &tempId, bool dbClick, bool onlyAcceptRelease)
{
    // handle method call hmi.service.sysifapps.getPositionToTransfer
    QMetaObject::invokeMethod(parent(), "getPositionToTransfer", Q_ARG(double, x), Q_ARG(double, y), Q_ARG(QString, tempId), Q_ARG(bool, dbClick), Q_ARG(bool, onlyAcceptRelease));
}

QString SysifappsAdaptor::getPreviousApplication()
{
    // handle method call hmi.service.sysifapps.getPreviousApplication
    QString out0;
    QMetaObject::invokeMethod(parent(), "getPreviousApplication", Q_RETURN_ARG(QString, out0));
    return out0;
}

void SysifappsAdaptor::getSettingTileAppId()
{
    // handle method call hmi.service.sysifapps.getSettingTileAppId
    QMetaObject::invokeMethod(parent(), "getSettingTileAppId");
}

void SysifappsAdaptor::getSettingTileType()
{
    // handle method call hmi.service.sysifapps.getSettingTileType
    QMetaObject::invokeMethod(parent(), "getSettingTileType");
}

QString SysifappsAdaptor::getTopMostSurfaceView()
{
    // handle method call hmi.service.sysifapps.getTopMostSurfaceView
    QString out0;
    QMetaObject::invokeMethod(parent(), "getTopMostSurfaceView", Q_RETURN_ARG(QString, out0));
    return out0;
}

void SysifappsAdaptor::gotoAndroidApp()
{
    // handle method call hmi.service.sysifapps.gotoAndroidApp
    QMetaObject::invokeMethod(parent(), "gotoAndroidApp");
}

bool SysifappsAdaptor::isFullSizeSurfaceViewTheTop()
{
    // handle method call hmi.service.sysifapps.isFullSizeSurfaceViewTheTop
    // START - Fix klocwork UNINIT.STACK.MUST
    bool out0 = false;
    // END - Fix klocwork UNINIT.STACK.MUST
    QMetaObject::invokeMethod(parent(), "isFullSizeSurfaceViewTheTop", Q_RETURN_ARG(bool, out0));
    return out0;
}

bool SysifappsAdaptor::isLeftDriverPosition()
{
    // handle method call hmi.service.sysifapps.isLeftDriverPosition
    // START - Fix klocwork UNINIT.STACK.MUST
    bool out0 = false;
    // END - Fix klocwork UNINIT.STACK.MUST
    QMetaObject::invokeMethod(parent(), "isLeftDriverPosition", Q_RETURN_ARG(bool, out0));
    return out0;
}

void SysifappsAdaptor::manualDriverPicture()
{
    // handle method call hmi.service.sysifapps.manualDriverPicture
    QMetaObject::invokeMethod(parent(), "manualDriverPicture");
}

void SysifappsAdaptor::manualDriverRecord()
{
    // handle method call hmi.service.sysifapps.manualDriverRecord
    QMetaObject::invokeMethod(parent(), "manualDriverRecord");
}

QString SysifappsAdaptor::mediaType()
{
    // handle method call hmi.service.sysifapps.mediaType
    QString out0;
    QMetaObject::invokeMethod(parent(), "mediaType", Q_RETURN_ARG(QString, out0));
    return out0;
}

void SysifappsAdaptor::notifySettingChanged(const QString &str)
{
    // handle method call hmi.service.sysifapps.notifySettingChanged
    QMetaObject::invokeMethod(parent(), "notifySettingChanged", Q_ARG(QString, str));
}

void SysifappsAdaptor::popupRequestShow(bool isShow)
{
    // handle method call hmi.service.sysifapps.popupRequestShow
    QMetaObject::invokeMethod(parent(), "popupRequestShow", Q_ARG(bool, isShow));
}

void SysifappsAdaptor::rePositionWindowItem(const QString &SURFACE_ID, int x, int y)
{
    // handle method call hmi.service.sysifapps.rePositionWindowItem
    QMetaObject::invokeMethod(parent(), "rePositionWindowItem", Q_ARG(QString, SURFACE_ID), Q_ARG(int, x), Q_ARG(int, y));
}

void SysifappsAdaptor::rePositionWindownItemback(const QString &SURFACE_ID)
{
    // handle method call hmi.service.sysifapps.rePositionWindownItemback
    QMetaObject::invokeMethod(parent(), "rePositionWindownItemback", Q_ARG(QString, SURFACE_ID));
}

void SysifappsAdaptor::receiveAppToCallOut(const QString &appID, int screenID)
{
    // handle method call hmi.service.sysifapps.receiveAppToCallOut
    QMetaObject::invokeMethod(parent(), "receiveAppToCallOut", Q_ARG(QString, appID), Q_ARG(int, screenID));
}

void SysifappsAdaptor::receivePhoneApp(const QString &appID, int screenID)
{
    // handle method call hmi.service.sysifapps.receivePhoneApp
    QMetaObject::invokeMethod(parent(), "receivePhoneApp", Q_ARG(QString, appID), Q_ARG(int, screenID));
}

void SysifappsAdaptor::receiverForMediaType(const QString &type)
{
    // handle method call hmi.service.sysifapps.receiverForMediaType
    QMetaObject::invokeMethod(parent(), "receiverForMediaType", Q_ARG(QString, type));
}

void SysifappsAdaptor::replyResultPopup(const QString &title, const QDBusVariant &data)
{
    // handle method call hmi.service.sysifapps.replyResultPopup
    QMetaObject::invokeMethod(parent(), "replyResultPopup", Q_ARG(QString, title), Q_ARG(QDBusVariant, data));
}

void SysifappsAdaptor::requestShowFullApp(const QString &in0)
{
    // handle method call hmi.service.sysifapps.requestShowFullApp
    QMetaObject::invokeMethod(parent(), "requestShowFullApp", Q_ARG(QString, in0));
}


void SysifappsAdaptor::requestToHome()
{
    // handle method call hmi.service.sysifapps.requestToHome
    QMetaObject::invokeMethod(parent(), "requestToHome");
}

void SysifappsAdaptor::resizeWindowItem(const QString &SURFACE_ID, int width, int height)
{
    // handle method call hmi.service.sysifapps.resizeWindowItem
    QMetaObject::invokeMethod(parent(), "resizeWindowItem", Q_ARG(QString, SURFACE_ID), Q_ARG(int, width), Q_ARG(int, height));
}

void SysifappsAdaptor::sendDataThroughSys(const QString &in0, const QDBusVariant &var)
{
    // handle method call hmi.service.sysifapps.sendDataThroughSys
    QMetaObject::invokeMethod(parent(), "sendDataThroughSys", Q_ARG(QString, in0), Q_ARG(QDBusVariant, var));
}

void SysifappsAdaptor::sendDatatoMedia(const QString &in0, const QString &in1)
{
    // handle method call hmi.service.sysifapps.sendDatatoMedia
    QMetaObject::invokeMethod(parent(), "sendDatatoMedia", Q_ARG(QString, in0), Q_ARG(QString, in1));
}

void SysifappsAdaptor::setCloseScreen()
{
    // handle method call hmi.service.sysifapps.setCloseScreen
    QMetaObject::invokeMethod(parent(), "setCloseScreen");
}

void SysifappsAdaptor::setappIdTiel(const QString &newAppIdTiel)
{
    // handle method call hmi.service.sysifapps.setappIdTiel
    QMetaObject::invokeMethod(parent(), "setappIdTiel", Q_ARG(QString, newAppIdTiel));
}

void SysifappsAdaptor::setchildAppActive(const QString &newChildAppActive)
{
    // handle method call hmi.service.sysifapps.setchildAppActive
    QMetaObject::invokeMethod(parent(), "setchildAppActive", Q_ARG(QString, newChildAppActive));
}

void SysifappsAdaptor::setlayoutType(int newLayoutType)
{
    // handle method call hmi.service.sysifapps.setlayoutType
    QMetaObject::invokeMethod(parent(), "setlayoutType", Q_ARG(int, newLayoutType));
}

void SysifappsAdaptor::settingTileAppId(const QString &appIdTiel)
{
    // handle method call hmi.service.sysifapps.settingTileAppId
    QMetaObject::invokeMethod(parent(), "settingTileAppId", Q_ARG(QString, appIdTiel));
}

void SysifappsAdaptor::showFactorySetting()
{
    // handle method call hmi.service.sysifapps.showFactorySetting
    QMetaObject::invokeMethod(parent(), "showFactorySetting");
}

void SysifappsAdaptor::updateScreenSuccesfully()
{
    // handle method call hmi.service.sysifapps.updateScreenSuccesfully
    QMetaObject::invokeMethod(parent(), "updateScreenSuccesfully");
}

uicommon::SysUI::TransitionRetCode SysifappsAdaptor::callOutToExpand(const QString &app, const QString& screenId , uicommon::SysUI::TransitionType transitionType)
{
    // START - Fix klocwork UNINIT.STACK.MUST
    uicommon::SysUI::TransitionRetCode ret = uicommon::SysUI::TransitionRetCode::FailedRet;
    // END - Fix klocwork UNINIT.STACK.MUST
    QMetaObject::invokeMethod(parent(), "callOutToExpand", Q_RETURN_ARG(uicommon::SysUI::TransitionRetCode, ret)
                                                         , Q_ARG(QString, app)
                                                         , Q_ARG(QString, screenId)
                                                         , Q_ARG(uicommon::SysUI::TransitionType, transitionType));
    return ret;
}

void SysifappsAdaptor::requestAACPSurface(const uicommon::SysUI::ServiceAACP& serviceType, bool isShown, const bool& supportShowHeader){
    QMetaObject::invokeMethod(parent(),"requestAACPSurface", Q_ARG(uicommon::SysUI::ServiceAACP, serviceType)
                                                           , Q_ARG(bool,isShown)
                                                           , Q_ARG(bool, supportShowHeader));
}

bool SysifappsAdaptor::cameraSurfaceIsRunning() const
{
    // get the value of property cameraIsOn
    return qvariant_cast< bool >(parent()->property("cameraSurfaceIsRunning"));
}

void SysifappsAdaptor::setCameraSurfaceIsRunning(bool value)
{
    // set the value of property cameraIsOn
    parent()->setProperty("cameraSurfaceIsRunning", QVariant::fromValue(value));
}

void SysifappsAdaptor::isReady(QString app)
{
    QMetaObject::invokeMethod(parent(),"isReady", Q_ARG(QString, app));
}

void SysifappsAdaptor::acknowledgeAppReady(QString app)
{
    QMetaObject::invokeMethod(parent(),"acknowledgeAppReady", Q_ARG(QString, app));
}

void SysifappsAdaptor::requestHideSurface(QString app)
{
    QMetaObject::invokeMethod(parent(),"requestHideSurface", Q_ARG(QString, app));
}
