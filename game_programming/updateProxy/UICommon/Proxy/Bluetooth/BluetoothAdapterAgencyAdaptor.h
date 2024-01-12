#ifndef BLUETOOTHADAPTERAGENCYADAPTOR_H
#define BLUETOOTHADAPTERAGENCYADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "BluetoothAdapterAgency.h"

namespace uicommon
{

    class BluetoothAdapterAgencyAdaptor : public QDBusAbstractAdaptor
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.btadapter")
        Q_CLASSINFO("D-Bus Introspection", ""
                                           "  <interface name=\"ese.hmi.btadapter\">\n"
                                           "    <signal name=\"onPowerChangedSignal\">\n"
                                           "      <arg direction=\"out\" type=\"i\" name=\"status\"/>\n"
                                           "    </signal>\n"
                                           "    <signal name=\"onPairFinishedSignal\">\n"
                                           "      <arg direction=\"out\" type=\"b\" name=\"successFlag\"/>\n"
                                           "    </signal>\n"
                                           "    <method name=\"getPower\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"setPower\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"status\"/>\n"
                                           "    </method>\n"
                                           "  </interface>\n"
                                           "")
    public:
        BluetoothAdapterAgencyAdaptor(BluetoothAdapterAgency *parent);
        virtual ~BluetoothAdapterAgencyAdaptor();

        inline BluetoothAdapterAgency *parent() const
        {
            return static_cast<BluetoothAdapterAgency *>(QObject::parent());
        }

    public:         // PROPERTIES
    public Q_SLOTS: // METHODS
        int getPower();
        bool setPower(int status);
    Q_SIGNALS: // SIGNALS
        void onPowerChangedSignal(int status);
        void onPairFinishedSignal(bool successFlag);
    };

}

#endif
