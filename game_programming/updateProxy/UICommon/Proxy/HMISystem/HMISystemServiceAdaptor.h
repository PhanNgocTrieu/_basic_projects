#ifndef HMISYSTEMSERVICEADAPTOR_H
#define HMISYSTEMSERVICEADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "HMISystemService.h"
#include "UICommon_global.h"
#include "Proxy/HMISystem/HMISystemServiceDefines.h"
namespace uicommon {
    /*
     * Adaptor class for interface ese.hmi.sys
     */
    class UICOMMON_EXPORT HMISystemServiceAdaptor: public QDBusAbstractAdaptor
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.sys")
        Q_CLASSINFO("D-Bus Introspection", ""
                                            "  <interface name=\"ese.hmi.sys\">\n"
                                           "       <method name=\"probeTransitionRule\">\n"
                                           "           <arg direction=\"in\" type=\"s\" name=\"appId\"/>\n"
                                           "           <arg direction=\"in\" type=\"s\" name=\"screenId\"/>\n"
                                           "           <arg direction=\"out\" type=\"i\"/>\n"
                                           "       </method>\n"
                                            "       <signal name=\"onChangeLanguage\">\n"
                                            "           <arg direction=\"out\" type=\"u\" name=\"id\"/>\n"
                                            "       </signal>\n"
                                            "       <method name=\"changeLanguage\">\n"
                                            "           <arg direction=\"in\" type=\"u\" name=\"id\"/>\n"
                                            "       </method>\n"
                                           "       <signal name=\"onShowCMN04\">\n"
                                           "           <arg direction=\"out\" type=\"u\" name=\"id\"/>\n"
                                           "       </signal>\n"
                                           "       <method name=\"showCMN04\">\n"
                                           "           <arg direction=\"in\" type=\"u\" name=\"id\"/>\n"
                                           "       </method>\n"
                                            "       <signal name=\"onShowDiagScreen\">\n"
                                            "           <arg direction=\"out\" type=\"s\" name=\"appId\"/>\n"
                                            "       </signal>\n"
                                            "       <method name=\"showDiagScreen\">\n"
                                            "           <arg direction=\"in\" type=\"s\" name=\"appId\"/>\n"
                                            "       </method>\n"
                                            "       <signal name=\"onChangeGlobalSetting\">\n"
                                            "           <arg direction=\"out\" type=\"s\" name=\"name\"/>\n"
                                            "           <arg direction=\"out\" type=\"v\" name=\"value\"/>\n"
                                            "       </signal>\n"
                                            "       <method name=\"changeGlobalSetting\">\n"
                                            "           <arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
                                            "           <arg direction=\"in\" type=\"v\" name=\"value\"/>\n"
                                            "       </method>\n"
                                            "       <signal name=\"onScreenCaptureMode\">\n"
                                            "           <arg direction=\"out\" type=\"s\" name=\"name\"/>\n"
                                            "           <arg direction=\"out\" type=\"v\" name=\"value\"/>\n"
                                            "       </signal>\n"
                                            "       <method name=\"screenCaptureMode\">\n"
                                            "           <arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
                                            "           <arg direction=\"in\" type=\"v\" name=\"value\"/>\n"
                                            "       </method>\n"
                                            "       <signal name=\"onRequestSetPrintOverFlowTextLog\">\n"
                                            "           <arg direction=\"out\" type=\"u\" name=\"status\"/>\n"
                                            "       </signal>\n"
                                            "       <method name=\"requestSetPrintOverFlowTextLog\">\n"
                                            "           <arg direction=\"in\" type=\"s\" name=\"status\"/>\n"
                                            "       </method>\n"
                                            "       <signal name=\"onPressOnApplicationChanged\">                                                                                                      \n"
                                            "           <arg direction=\"out\" type=\"(i)\">                                                                      \n"
                                            "           <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::HMIApplication\">             \n"
                                            "           <arg direction=\"out\" type=\"(i)\">                                                                      \n"
                                            "           <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out1\" value=\"uicommon::HMIUserInteractiveStatus\">   \n"
                                            "       </signal>                                                                                                     \n"
                                            "       <signal name =\"onRequestShowRecorderStreamer\">                         \n"              
                                            "           <arg direction=\"out\" type=\"b\">                                   \n"
                                            "       </signal>                                                                \n"
                                            "       <method name=\"enableCamera\">                                           \n"
                                            "           <arg type=\"b\" direction=\"out\">                                   \n"
                                            "       </method>                                                                \n"
                                            "       <signal name=\"onEnableCameraChanged\">                                  \n"
                                            "           <arg type=\"b\" direction=\"out\">                                   \n"
                                            "       </signal>                                                                \n"
                                            "       <signal name =\"onRequestShowRecorderStreamer\">                                                              \n"
                                            "           <arg direction=\"out\" type=\"b\">                                                                        \n"
                                            "       </signal>                                                                                                     \n"
                                            "           <arg type=\"b\" direction=\"out\">                                                                        \n"
                                            "       </method>                                                                                                     \n"
                                            "           <arg type=\"b\" direction=\"out\">                                                                        \n"
                                            "       </signal>                                                                                                     \n"
                                           "       <method name=\"isHandlePosition\">                                                                             \n"
                                           "           <arg type=\"b\" direction=\"out\">                                                                         \n"
                                           "       </method>                                                                                                      \n"
                                           "       <signal name=\"onIsHandlePosition\">                                                                           \n"
                                           "           <arg type=\"b\" direction=\"out\">                                                                         \n"
                                           "       </signal>                                                                                                      \n"
                                           "      <method name=\"popupEmerged\">                                                                                  \n"                     
                                           "           <arg type=\"b\" direction=\"out\">                                                                         \n"
                                           "      </method>                                                                                                       \n"
                                           "      <method name=\"getPopupPathOfAApllication\">                                                                    \n"                     
                                           "           <arg type=\"s\" direction=\"out\">                                                                         \n"
                                           "           <arg type=\"s\" direction=\"out\">                                                                         \n"
                                           "      </method>                                                                                                       \n"
                                           "      <method name=\"setPopupStateOfApplication\">                                                                    \n"                     
                                           "           <arg type=\"s\" direction=\"out\">                                                                         \n"
                                           "           <arg type=\"s\" direction=\"out\">                                                                         \n"
                                           "      </method>                                                                                                       \n"
                                           " <method name=\"setLayoutDisplay\">             \n"
                                           " <arg direction=\"out\" type=\"(i)\">           \n"
                                           " <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::LayoutDisplay\"> \n"
                                           " </method> \n"
                                           " <signal name=\"onLayoutDisplayChanged\">             \n"
                                           " <arg direction=\"out\" type=\"(i)\">           \n"
                                           " <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::LayoutDisplay\"> \n"
                                           " </method> \n"
                                            " <method name=\"getLayoutDisplay\">      \n"
                                            " <arg direction=\"out\" type=\"(i)\">\n"
                                            " <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::LayoutDisplay\">\n"
                                           " </method>\n"
                                           "       <method name=\"requestCPNaviMeter\">       \n"
                                           "           <arg type=\"b\" direction=\"in\">      \n"
                                           "           <arg type=\"b\" direction=\"out\">     \n"
                                           "       </method>                                  \n"
                                           "       <method name=\"requestAANaviMeter\">       \n"
                                           "           <arg type=\"b\" direction=\"in\">      \n"
                                           "           <arg type=\"b\" direction=\"out\">     \n"
                                           "       </method>                                  \n"
                                           "       <signal name=\"requestGetTempUnit\">\n"
                                           "       </signal>\n"
                                           "       <signal name =\"onRequestStreamerFullScreen\">           \n"
                                           "           <arg direction=\"out\" type=\"b\">                   \n"
                                           "       </signal>                                                \n"
                                           "       <method name=\"requestStreamerFullScreen\">              \n"
                                           "           <arg type=\"b\" direction=\"in\">                    \n"
                                           "       </method>                                                \n"
                                           "       <signal name=\"onRequestFullScreenDone\">                \n"
                                           "       </signal>                                                \n"
                                           "       <method name=\"requestFullScreenDone\">                  \n"
                                           "       </method>                                                \n"
                                            "  </interface>\n"
                                            "")
    public:
        HMISystemServiceAdaptor(uicommon::HMISystemService *parent);
        virtual ~HMISystemServiceAdaptor();

        inline uicommon::HMISystemService *parent() const
        { return static_cast<uicommon::HMISystemService *>(QObject::parent()); }

    public: // PROPERTIES
    public Q_SLOTS: // METHODS
        int probeTransitionRule(const QString& appId, const QString& screenId);
        void changeLanguage(uint id);
        void showDiagScreen(QString appId);
        void changeGlobalSetting(const QString &name, const QDBusVariant &value);
        void screenCaptureMode(const QString &name, const QDBusVariant &value);
        void requestSetPrintOverFlowTextLog(const bool& isPrint);
        void enableCamera(bool);
        void isHandlePosition(bool);
        bool popupEmerged();
        QString getPopupPathOfAApllication(const QString&);
        void setPopupStateOfApplication(const QString&, const QString&);
        void setLayoutDisplay(LayoutDisplay);
        LayoutDisplay getLayoutDisplay();
        void showCMN04(quint32 id);
        bool requestCPNaviMeter(bool);
        bool requestAANaviMeter(bool);
        void requestStreamerFullScreen(bool isFullScreen);
        void requestFullScreenDone();

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
        void onShowCMN04(quint32 id);
        void requestGetTempUnit();
        void onRequestSetPrintOverFlowTextLog(const bool& isPrint);
        void onRequestStreamerFullScreen(bool isFullScreen);
        void onRequestFullScreenDone();
    };
}

#endif
