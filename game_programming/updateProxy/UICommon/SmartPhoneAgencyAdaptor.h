/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -l SmartPhoneAgency -c SmartPhoneAgencyAdaptor -a SmartPhoneAgencyAdaptor SmartPhoneAgency.xml
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef SMARTPHONEAGENCYADAPTOR_H
#define SMARTPHONEAGENCYADAPTOR_H

#include "SmartPhoneAgency.h"
#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>

namespace uicommon
{
    /*
     * Adaptor class for interface ese.hmi.smartphoneagency
     */
    class SmartPhoneAgencyAdaptor : public QDBusAbstractAdaptor
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.smartphoneagency")
        Q_CLASSINFO("D-Bus Introspection", ""
                                           "  <interface name=\"ese.hmi.smartphoneagency\">\n"
                                           "    <signal name=\"onDeviceListUpdateSignal\"/>\n"
                                           "    <signal name=\"onDeviceListReplySignal\"/>\n"
                                           "    <method name=\"isExisting\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"in\" type=\"s\" name=\"serialNum\"/>\n"
                                           "      <arg direction=\"in\" type=\"s\" name=\"btAddr\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getDeviceList\">\n"
                                           "      <arg direction=\"out\" type=\"a{sssbiiiibbbbbbbb}\"/>\n"
                                           "      <annotation value=\"QList&lt;uicommon::SmartPhoneAgency::DeviceInfo&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"devListRequest\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"startSession\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "      <arg direction=\"in\" type=\"s\" name=\"btAddr\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"devType\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"type\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"entrance\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"stopSession\">\n"
                                           "      <arg direction=\"out\" type=\"i\"/>\n"
                                           "      <arg direction=\"in\" type=\"s\" name=\"btAddr\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"devType\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"type\"/>\n"
                                           "      <arg direction=\"in\" type=\"i\" name=\"entrance\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getCurrentSession\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"out\" type=\"{sssbiiiibbbbbbbb}\" name=\"retValue\"/>\n"
                                           "      <annotation value=\"uicommon::SmartPhoneAgency::DeviceInfo\" name=\"org.qtproject.QtDBus.QtTypeName.Out1\"/>\n"
                                           "    </method>\n"
                                           "    <method name=\"getUSBDevice\">\n"
                                           "      <arg direction=\"out\" type=\"b\"/>\n"
                                           "      <arg direction=\"out\" type=\"{sssbiiiibbbbbbbb}\" name=\"retValue\"/>\n"
                                           "      <annotation value=\"uicommon::SmartPhoneAgency::DeviceInfo\" name=\"org.qtproject.QtDBus.QtTypeName.Out1\"/>\n"
                                           "    </method>\n"
                                           "  </interface>\n"
                                           "")
    public:
        SmartPhoneAgencyAdaptor(SmartPhoneAgency *parent);
        virtual ~SmartPhoneAgencyAdaptor();

        inline SmartPhoneAgency *parent() const
        {
            return static_cast<SmartPhoneAgency *>(QObject::parent());
        }

    public:         // PROPERTIES
    public Q_SLOTS: // METHODS
        bool getCurrentSession(uicommon::SmartPhoneAgency::DeviceInfo &retValue);
        QList<uicommon::SmartPhoneAgency::DeviceInfo> getDeviceList();
        bool getUSBDevice(uicommon::SmartPhoneAgency::DeviceInfo &retValue);
        bool isExisting(const QString &serialNum, const QString &btAddr);
        int startSession(const QString &btAddr, int devType, int type, int entrance);
        int stopSession(const QString &btAddr, int devType, int type, int entrance);
        bool devListRequest();
    Q_SIGNALS: // SIGNALS
        void onDeviceListUpdateSignal();
        void onDeviceListReplySignal();
    };
}

#endif
