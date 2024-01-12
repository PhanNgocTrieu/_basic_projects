
#ifndef AAPAGENCYADAPTOR_H
#define AAPAGENCYADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "AAPAgency.h"

namespace uicommon
{
    /*
    * Adaptor class for interface ese.hmi.aapagency
    */
    class AAPAgencyAdaptor: public QDBusAbstractAdaptor
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.aapagency")
        Q_CLASSINFO("D-Bus Introspection", ""
                                            "  <interface name=\"ese.hmi.aapagency\">\n"
                                            "    <signal name=\"onStateChanged\">\n"
                                            "      <arg direction=\"out\" type=\"i\" name=\"oldState\"/>\n"
                                            "      <arg direction=\"out\" type=\"i\" name=\"newState\"/>\n"
                                            "    </signal>\n"
                                            "    <signal name=\"onAudioMediaStatusChangeSignal\">\n"
                                            "      <arg direction=\"out\" type=\"i\" name=\"oldState\"/>\n"
                                            "      <arg direction=\"out\" type=\"i\" name=\"newState\"/>\n"
                                            "    </signal>\n"
                                           "    <signal name=\"onMediaMetaDataChanged\">\n"
                                           "      <arg direction=\"out\" type=\"{ssssi}\" name=\"metaData\"/>\n"
                                           "    </signal>\n"
                                           "    <signal name=\"onMediaStatusChanged\">\n"
                                           "      <arg direction=\"out\" type=\"{ibbbi}\" name=\"mediaStatus\"/>\n"
                                           "    </signal>\n"
                                           "    <signal name=\"onNotifySetAAPDayColorValue\">\n"
                                           "      <arg direction=\"out\" type=\"{i}\" name=\"value\"/>\n"
                                           "    </signal>\n"
                                           "    <signal name=\"onNotifySetAAPDayContrastValue\">\n"
                                           "      <arg direction=\"out\" type=\"{i}\" name=\"value\"/>\n"
                                           "    </signal>\n"
                                           "    <signal name=\"onNotifySetAAPNightColorValue\">\n"
                                           "      <arg direction=\"out\" type=\"{i}\" name=\"value\"/>\n"
                                           "    </signal>\n"
                                           "    <signal name=\"onNotifySetAAPNightContrastValue\">\n"
                                           "      <arg direction=\"out\" type=\"{i}\" name=\"value\"/>\n"
                                           "    <signal name=\"onNotifyAAPVRStatus\">\n"
                                           "      <arg direction=\"out\" type=\"{i}\" name=\"vrStatus\"/>\n"
                                           "    </signal>\n"
                                            "    <method name=\"getCurrentState\">\n"
                                            "      <arg direction=\"out\" type=\"i\"/>\n"
                                            "    </method>\n"
                                            "    <method name=\"setOperationMode\">\n"
                                            "      <arg direction=\"out\" type=\"b\"/>\n"
                                            "      <arg direction=\"in\" type=\"i\" name=\"mode\"/>\n"
                                            "    </method>\n"
                                            "    <method name=\"setSourceOn\">\n"
                                            "      <arg direction=\"out\" type=\"b\"/>\n"
                                            "      <arg direction=\"in\" type=\"b\" name=\"isSourceOn\"/>\n"
                                            "    </method>\n"
                                           "    <method name=\"enjectKeyEvent\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"keyCode\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"keyStatus\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getMediaMetaData\">\n"
                                           "      <arg direction=\"out\" type=\"{ssssi}\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getMediaStatus\">\n"
                                           "      <arg direction=\"out\" type=\"{ibbbi}\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setAAPContrastStepValue\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"s\" name=\"detail\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setAAPColorStepValue\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"s\" name=\"detail\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getAAPContrastStepValue\">\n"
                                           "      <arg direction=\"out\" type=\"s\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getAAPColorStepValue\">\n"
                                           "      <arg direction=\"out\" type=\"s\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getAAPDayContrastValue\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setAAPDayContrastValue\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getAAPDayColorValue\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setAAPDayColorValue\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getAAPNightContrastValue\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setAAPNightContrastValue\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getAAPNightColorValue\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setAAPNightColorValue\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
                                           "    </method>\n"
                                            "  </interface>\n"
                                                    "")
    public:
        AAPAgencyAdaptor(AAPAgency *parent);
        virtual ~AAPAgencyAdaptor();

        inline AAPAgency *parent() const
        { return static_cast<AAPAgency *>(QObject::parent()); }

    public: // PROPERTIES
    public Q_SLOTS: // METHODS
        int getCurrentState();
        bool setOperationMode(int mode);        
        bool setSourceOn(bool isSourceOn);
        bool enjectKeyEvent(int keyCode, int keyStatus);
        uicommon::AAPAgency::MediaMetaData getMediaMetaData();
        uicommon::AAPAgency::MediaStatus getMediaStatus();
        bool setAAPContrastStepValue(QString detail);
        bool setAAPColorStepValue(QString detail);
        QString getAAPContrastStepValue();
        QString getAAPColorStepValue();

        int  getAAPDayContrastValue();
        bool setAAPDayContrastValue(int value);
        int  getAAPDayColorValue();
        bool setAAPDayColorValue(int value);
        int  getAAPNightContrastValue();
        bool setAAPNightContrastValue(int value);
        int  getAAPNightColorValue();
        bool setAAPNightColorValue(int value);


    Q_SIGNALS: // SIGNALS
        void onStateChanged(int oldState, int newState);
        void onAudioMediaStatusChangeSignal(int oldState, int newState);
        void onMediaMetaDataChanged(uicommon::AAPAgency::MediaMetaData metaData);
        void onMediaStatusChanged(uicommon::AAPAgency::MediaStatus mediaStatus);
        void onNotifySetAAPDayColorValue(int value);
        void onNotifySetAAPDayContrastValue(int value);
        void onNotifySetAAPNightColorValue(int value);
        void onNotifySetAAPNightContrastValue(int value);
        void onNotifyAAPVRStatus(int vrStatus);
    };
}
#endif
