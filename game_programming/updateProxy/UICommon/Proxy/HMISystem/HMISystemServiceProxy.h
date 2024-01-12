#ifndef HMISYSTEMSERVICEPROXY_H
#define HMISYSTEMSERVICEPROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "UICommon_global.h"
#include "Proxy/HMISystem/HMISystemServiceDefines.h"
namespace uicommon {
    /*
     * Proxy class for interface ese.hmi.sys
     */
    class UICOMMON_EXPORT HMISystemServiceProxy: public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        { return "ese.hmi.sys"; }

    public:
        static HMISystemServiceProxy& getInstance();

        virtual ~HMISystemServiceProxy();

    protected:
         HMISystemServiceProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    public Q_SLOTS: // METHODS
        inline int probeTransitionRule(const QString& appId, const QString& screenId)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(appId) << QVariant::fromValue(screenId);
            QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("probeTransitionRule"), argumentList);
            if (reply.type() == QDBusMessage::ReplyMessage)
            {
                return qdbus_cast<int>(reply.arguments().at(0));
            }
            else {
                return 0;
            }
        }
        inline QDBusPendingReply<> changeLanguage(uint id)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(id);
            return asyncCallWithArgumentList(QStringLiteral("changeLanguage"), argumentList);
        }
        
        inline QDBusPendingReply<> showDiagScreen(QString appId)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(appId);
            return asyncCallWithArgumentList(QStringLiteral("showDiagScreen"), argumentList);
        }

        inline QDBusPendingReply<> changeGlobalSetting(const QString &name, const QDBusVariant &value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(name) << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("changeGlobalSetting"), argumentList);
        }

        inline QDBusPendingReply<> screenCaptureMode(const QString &name, const QDBusVariant &value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(name) << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("screenCaptureMode"), argumentList);
        }

        inline QDBusPendingReply<> requestSetPrintOverFlowTextLog(const bool& isPrint)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(isPrint);
            return asyncCallWithArgumentList(QStringLiteral("requestSetPrintOverFlowTextLog"), argumentList);
        }

        inline QDBusPendingReply<> enableCamera(bool enable){
            QList<QVariant> argumentList;
            argumentList << enable;
            return asyncCallWithArgumentList(QStringLiteral("enableCamera"), argumentList);
        }

        inline QDBusPendingReply<> isHandlePosition(bool requestStatus){
            QList<QVariant> argumentList;
            argumentList << requestStatus;
            return asyncCallWithArgumentList(QStringLiteral("isHandlePosition"), argumentList);
        }
        inline QDBusPendingReply<bool> popupEmerged(){
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("popupEmerged"), argumentList);
        }
        inline QDBusPendingReply<QString> getPopupPathOfAApllication(const QString& app){
            QList<QVariant> argumentList;
            argumentList << app;
            return asyncCallWithArgumentList(QStringLiteral("getPopupPathOfAApllication"), argumentList);
        }

        inline QDBusPendingReply<> setPopupStateOfApplication(const QString& app, const QString& popupPath){
            QList<QVariant> argumentList;
            argumentList << app;
            argumentList << popupPath;
            return asyncCallWithArgumentList(QStringLiteral("setPopupStateOfApplication"), argumentList);
        }

        inline QDBusPendingReply<> setLayoutDisplay(LayoutDisplay display){
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(display);
            return asyncCallWithArgumentList(QStringLiteral("setLayoutDisplay"), argumentList);
        }

        inline QDBusPendingReply<LayoutDisplay> getLayoutDisplay(){
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getLayoutDisplay"), argumentList);
        }

        inline QDBusPendingReply<LayoutDisplay> showCMN04(uint id){
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(id);
            return asyncCallWithArgumentList(QStringLiteral("showCMN04"), argumentList);
        }
        inline QDBusPendingReply<bool> requestCPNaviMeter(bool requestType)
        {
            QList<QVariant> argumentList;
            argumentList << requestType;
            return asyncCallWithArgumentList("requestCPNaviMeter", argumentList);
        }

        inline QDBusPendingReply<bool> requestAANaviMeter(bool requestType)
        {
            QList<QVariant> argumentList;
            argumentList << requestType;
            return asyncCallWithArgumentList("requestAANaviMeter", argumentList);
        }

        inline QDBusPendingReply<> requestStreamerFullScreen(bool isFullScreen)
        {
            QList<QVariant> argumentList;
            argumentList << isFullScreen;
            return asyncCallWithArgumentList("requestStreamerFullScreen", argumentList);
        }

        inline QDBusPendingReply<> requestFullScreenDone()
        {
            return asyncCall("requestFullScreenDone");
        }

    Q_SIGNALS: // SIGNALS
        void onChangeLanguage(uint id);
        void onShowDiagScreen(QString appId);
        void onPressOnApplicationChanged(uicommon::HMIApplication, uicommon::HMIUserInteractiveStatus);
        void onChangeGlobalSetting(const QString &name, const QDBusVariant &value);
        void onScreenCaptureMode(const QString &name, const QDBusVariant &value);
        void onRequestShowRecorderStreamer(bool);
        void onEnableCameraChanged(bool);
        void onIsHandlePosition(bool);
        void onLayoutDisplayChanged(LayoutDisplay);
        void onShowCMN04(uint id);
        void requestGetTempUnit();
        void onRequestSetPrintOverFlowTextLog(bool isPrint);
        void onRequestStreamerFullScreen(bool isFullScreen);
        void onRequestFullScreenDone();
    };
}

#endif
