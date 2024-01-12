#ifndef WIFIADAPTERAGENCYADAPTOR_H
#define WIFIADAPTERAGENCYADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "WifiAdapterAgency.h"

namespace uicommon
{
    /*
     * Adaptor class for interface ese.hmi.wifiadapter
     */
    class WifiAdapterAgencyAdaptor : public QDBusAbstractAdaptor
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.wifiadapter")
        Q_CLASSINFO("D-Bus Introspection", ""
                                           "  <interface name=\"ese.hmi.wifiadapter\">\n"
                                           "    <signal name=\"onPowerChangedSignal\">\n"
                                           "      <arg direction=\"out\" type=\"i\" name=\"status\"/>\n"
                                           "    </signal>\n"
                                           "    <method name=\"getPower\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setPower\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"status\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getSSID\">\n"
                                           "      <arg direction=\"out\" type=\"s\"/>\n"
                                           "    </method>\n"
                                           "  </interface>\n"
                                           "")
    public:
        WifiAdapterAgencyAdaptor(WifiAdapterAgency *parent);
        virtual ~WifiAdapterAgencyAdaptor();

        inline WifiAdapterAgency *parent() const
        {
            return static_cast<WifiAdapterAgency *>(QObject::parent());
        }

    public:         // PROPERTIES
    public Q_SLOTS: // METHODS
        int getPower();
        QString getSSID();
        bool setPower(int status);
    Q_SIGNALS: // SIGNALS
        void onPowerChangedSignal(int status);
    };

}

#endif
