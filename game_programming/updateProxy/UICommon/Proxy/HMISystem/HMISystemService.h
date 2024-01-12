#ifndef HMISYSTEMSERVICE_H
#define HMISYSTEMSERVICE_H

#include <QObject>
#include "UICommon_global.h"
#include <Proxy/HMISystem/HMISystemServiceDefines.h>
namespace uicommon {
    class UICOMMON_EXPORT HMISystemService:public QObject{
     Q_OBJECT
     Q_CLASSINFO("D-Bus Interface", "ese.hmi.sys")
    public:
        virtual ~HMISystemService();

    public slots:
        virtual int probeTransitionRule(const QString& appId, const QString& screenId) = 0;
        virtual void changeLanguage(quint32 idx) = 0;
        virtual void showDiagScreen(QString appId) = 0;
        virtual void pressOnApplication(QString application, quint32 userEvent = 0, bool isBar = false) = 0;
        virtual void changeGlobalSetting(const QString &name, const QDBusVariant &value) = 0;
        virtual void screenCaptureMode(const QString &name, const QDBusVariant &value) = 0;
        virtual void requestSetPrintOverFlowTextLog(const bool & isPrint) = 0;
        virtual void enableCamera(bool enable) = 0;
        virtual void isHandlePosition(bool status) = 0;
        virtual void setLayoutDisplay(LayoutDisplay) = 0;
        virtual LayoutDisplay getLayoutDisplay() = 0;
        virtual bool popupEmerged() = 0;
        virtual QString getPopupPathOfAApllication(const QString&) = 0;
        virtual void setPopupStateOfApplication(const QString&, const QString&) = 0;
        virtual void showCMN04(quint32 id) = 0;
        virtual bool requestCPNaviMeter(bool requestType) = 0;
        virtual bool requestAANaviMeter(bool requestType) = 0;
        virtual void requestStreamerFullScreen(bool isFullScreen) = 0;
        virtual void requestFullScreenDone() = 0;

    signals:
        void onChangeLanguage(quint32 id);
        void onShowDiagScreen(QString appId);
        /**
         * @brief Send the press the status on the application
         *        1. The press Status can be one of the following:
         *          - HMIUserInteractiveStatus::Release:           User doesn't interface with the screen
         *          - HMIUserInteractiveStatus::PRESSED:           User presses On the screen at the specific application
         *          - HMIUserInteractiveStatus::HOVER:             User dragging the application into the region which can be dropped
         *        2. In case Pressed And Hover, the targetted application would be sent through the first param uicommon::HMIApplication
         *        3. Especially, If the Application is uicommon::HMIApplication::NONE, don't consume the uicommon::HMIUserInteractiveStatus
         *           Because this is the release signal
         * 
         */
        void onPressOnApplicationChanged(uicommon::HMIApplication, uicommon::HMIUserInteractiveStatus);
        void onChangeGlobalSetting(const QString &name, const QDBusVariant &value);
        void onScreenCaptureMode(const QString &name, const QDBusVariant &value);
        void onRequestShowRecorderStreamer(bool);
        void onEnableCameraChanged(bool);
        void onIsHandlePosition(bool);
        void onLayoutDisplayChanged(LayoutDisplay);
        void onShowCMN04(quint32 id);
        void requestGetTempUnit();
        void onRequestSetPrintOverFlowTextLog(bool isPrint);
        void onRequestStreamerFullScreen(bool isFullScreen);
        void onRequestFullScreenDone();
    };
}

#endif
