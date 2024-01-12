/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c SmartPhoneAgencyProxy -p SmartPhoneAgencyProxy SmartPhoneAgency.xml
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef SMARTPHONEAGENCYPROXY_H
#define SMARTPHONEAGENCYPROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "SmartPhoneAgency.h"

namespace uicommon
{
    /*
     * Proxy class for interface ese.hmi.smartphoneagency
     */
    class SmartPhoneAgencyProxy : public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        {
            return "ese.hmi.smartphoneagency";
        }
        static SmartPhoneAgencyProxy &getInstance();

    public:
        ~SmartPhoneAgencyProxy();

    public Q_SLOTS: // METHODS
        inline QDBusPendingReply<bool, uicommon::SmartPhoneAgency::DeviceInfo> getCurrentSession()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getCurrentSession"), argumentList);
        }
        inline QDBusReply<bool> getCurrentSession(uicommon::SmartPhoneAgency::DeviceInfo &retValue)
        {
            QList<QVariant> argumentList;
            QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("getCurrentSession"), argumentList);
            if ((reply.type() == QDBusMessage::ReplyMessage) && (reply.arguments().count() == 2))
            {
                retValue = qdbus_cast<uicommon::SmartPhoneAgency::DeviceInfo>(reply.arguments().at(1));
            }
            return reply;
        }

        inline QDBusPendingReply<QList<uicommon::SmartPhoneAgency::DeviceInfo>> getDeviceList()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getDeviceList"), argumentList);
        }

        inline QDBusPendingReply<bool> devListRequest()
        {
            return asyncCall(QStringLiteral("devListRequest"));
        }

        inline QDBusPendingReply<bool, uicommon::SmartPhoneAgency::DeviceInfo> getUSBDevice()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getUSBDevice"), argumentList);
        }

        inline QDBusReply<bool> getUSBDevice(uicommon::SmartPhoneAgency::DeviceInfo &retValue)
        {
            QList<QVariant> argumentList;
            QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("getUSBDevice"), argumentList);
            if ((reply.type() == QDBusMessage::ReplyMessage) && (reply.arguments().count() == 2))
            {
                retValue = qdbus_cast<uicommon::SmartPhoneAgency::DeviceInfo>(reply.arguments().at(1));
            }
            return reply;
        }

        inline QDBusPendingReply<bool> isExisting(const QString &serialNum, const QString &btAddr)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(serialNum) << QVariant::fromValue(btAddr);
            return asyncCallWithArgumentList(QStringLiteral("isExisting"), argumentList);
        }

        inline QDBusPendingReply<int> startSession(const QString &btAddr, int devType, int type, int entrance)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(btAddr) << QVariant::fromValue(devType) << QVariant::fromValue(type) << QVariant::fromValue(entrance);
            return asyncCallWithArgumentList(QStringLiteral("startSession"), argumentList);
        }

        inline QDBusPendingReply<int> stopSession(const QString &btAddr, int devType, int type, int entrance)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(btAddr) << QVariant::fromValue(devType) << QVariant::fromValue(type) << QVariant::fromValue(entrance);
            return asyncCallWithArgumentList(QStringLiteral("stopSession"), argumentList);
        }


    Q_SIGNALS: // SIGNALS
        void onDeviceListUpdateSignal();
        void onDeviceListReplySignal();

    public:
        void getDeviceList(const std::function<void(uint, const QList<uicommon::SmartPhoneAgency::DeviceInfo>&)>& confirmCallback);
        void getCurrentSession(const std::function<void(bool, const uicommon::SmartPhoneAgency::DeviceInfo&)>& confirmCallback);
    protected:
        SmartPhoneAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);
        
    };

}

#endif
