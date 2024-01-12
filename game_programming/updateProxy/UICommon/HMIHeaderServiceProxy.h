#ifndef HMIHEADERSERVICEPROXY_H
#define HMIHEADERSERVICEPROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "UICommon_global.h"

namespace uicommon {
    /*
     * Proxy class for interface ese.hmi.sys
     */
    class UICOMMON_EXPORT HMIHeaderServiceProxy: public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        { return "ese.hmi.header"; }

    public:
        static HMIHeaderServiceProxy& getInstance();

        ~HMIHeaderServiceProxy();

    protected:
         HMIHeaderServiceProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    public Q_SLOTS: // METHODS
        inline QDBusPendingReply<> OTAErrInfo(bool errInfo)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(errInfo);
            return asyncCallWithArgumentList(QStringLiteral("OTAErrInfo"), argumentList);
        }

        inline QDBusPendingReply<> bluetoothPowerStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("bluetoothPowerStatus"), argumentList);
        }

        inline QDBusPendingReply<> bluetoothStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("bluetoothStatus"), argumentList);
        }

        inline QDBusPendingReply<> changeTemperature(double newTemperature, bool isEurope, bool isTemperatureUnitC)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(newTemperature) << QVariant::fromValue(isEurope) << QVariant::fromValue(isTemperatureUnitC);
            return asyncCallWithArgumentList(QStringLiteral("changeTemperature"), argumentList);
        }

        inline QDBusPendingReply<> setHeaterLeftLevel(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setHeaterLeftLevel"), argumentList);
        }

        inline QDBusPendingReply<> setHeaterRightLevel(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setHeaterRightLevel"), argumentList);
        }

        inline QDBusPendingReply<> setIs12hFormat(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIs12hFormat"), argumentList);
        }

        inline QDBusPendingReply<> setIsAcMark(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsAcMark"), argumentList);
        }

        inline QDBusPendingReply<> setIsAccount(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsAccount"), argumentList);
        }

        inline QDBusPendingReply<> setIsActive(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsActive"), argumentList);
        }

        inline QDBusPendingReply<> setIsCancel(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsCancel"), argumentList);
        }

        inline QDBusPendingReply<> setIsDownload(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsDownload"), argumentList);
        }
        inline QDBusPendingReply<> setIsStatusOTA(int status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsStatusOTA"), argumentList);
        }
        inline QDBusPendingReply<> setIsNotify(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsNotify"), argumentList);
        }

        inline QDBusPendingReply<> setIsError(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsError"), argumentList);
        }

        inline QDBusPendingReply<> setIsTAfromSMD(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsTAfromSMD"), argumentList);
        }

        inline QDBusPendingReply<> setSttOff(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setSttOff"), argumentList);
        }

        inline QDBusPendingReply<> setTemperature(double value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setTemperature"), argumentList);
        }

        inline QDBusPendingReply<> setValueFan(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setValueFan"), argumentList);
        }

        inline QDBusPendingReply<> setWarmLeftAC(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setWarmLeftAC"), argumentList);
        }

        inline QDBusPendingReply<> setWarmRightAC(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setWarmRightAC"), argumentList);
        }

        inline QDBusPendingReply<> setWindLeftAC(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setWindLeftAC"), argumentList);
        }

        inline QDBusPendingReply<> setWindRightAC(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setWindRightAC"), argumentList);
        }

        inline QDBusPendingReply<> wifiPowerStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("wifiPowerStatus"), argumentList);
        }

        inline QDBusPendingReply<> wifiStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("wifiStatus"), argumentList);
        }

        inline QDBusPendingReply<> sendSysTime(const QString &timeSys, const QString &mediran)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(timeSys) << QVariant::fromValue(mediran);
            return asyncCallWithArgumentList(QStringLiteral("sendSysTime"), argumentList);
        }

        inline QDBusPendingReply<> showUpdateDisableIcon(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("showUpdateDisableIcon"), argumentList);
        }
    
        inline QDBusPendingReply<> setIsAndroidSet(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsAndroidSet"), argumentList);
        }

        inline QDBusPendingReply<> setIsHFPAvailable(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsHFPAvailable"), argumentList);
        }

        inline QDBusPendingReply<> setBatteryLevel(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setBatteryLevel"), argumentList);
        }

        inline QDBusPendingReply<> setSignalStrength(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setSignalStrength"), argumentList);
        }

        inline QDBusPendingReply<> setIsFrontSeatECUFailureSts(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsFrontSeatECUFailureSts"), argumentList);
        }
        inline QDBusPendingReply<> setRdsStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setRdsStatus"), argumentList);
        }
        inline QDBusPendingReply<> setTelematicsSrvState(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setTelematicsSrvState"), argumentList);
        }
        inline QDBusPendingReply<> setCntdSrvStgState(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setCntdSrvStgState"), argumentList);
        }
        inline QDBusPendingReply<> setMuteStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setMuteStatus"), argumentList);
        }
        inline QDBusPendingReply<> setIsVolumeChanging(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsVolumeChanging"), argumentList);
        }
        inline QDBusPendingReply<> setRadioWaveIntensity(int status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setRadioWaveIntensity"), argumentList);
        }

        inline QDBusPendingReply<> setIsFeedbackSignalStrengthHFP(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsFeedbackSignalStrengthHFP"), argumentList);
        }

        inline QDBusPendingReply<> setIsIGACCStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsIGACCStatus"), argumentList);
        }

        inline QDBusPendingReply<> setIsACFailureStatus(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsACFailureStatus"), argumentList);
        }

        inline QDBusPendingReply<> setIsFeedbackBatterLevelHFP(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsFeedbackBatterLevelHFP"), argumentList);
        }

        inline QDBusPendingReply<> setIsHeaterSeatEquipped(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsHeaterSeatEquipped"), argumentList);
        }

        inline QDBusPendingReply<> setIsSteeringWheelHeaterEquipped(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsSteeringWheelHeaterEquipped"), argumentList);
        }

        inline QDBusPendingReply<> setResultTemperatureFromAC(QString interger, QString decimal)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(interger) << QVariant::fromValue(decimal);
            return asyncCallWithArgumentList(QStringLiteral("setResultTemperatureFromAC"), argumentList);
        }

        inline QDBusPendingReply<> setIsInteruptCan478(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsInteruptCan478"), argumentList);
        }

        inline QDBusPendingReply<> setIsInteruptCan3E8(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setIsInteruptCan3E8"), argumentList);
        }

        inline QDBusPendingReply<> setLowTemperature(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setLowTemperature"), argumentList);
        }

        inline QDBusPendingReply<> setHighTemperature(bool status)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(status);
            return asyncCallWithArgumentList(QStringLiteral("setHighTemperature"), argumentList);
        }
        
        inline QDBusPendingReply<> setBlackScreenCPAA(bool isShow)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(isShow);
            return asyncCallWithArgumentList(QStringLiteral("setBlackScreenCPAA"), argumentList);
        }

        inline QDBusPendingReply<> sendCmdCPAAHandle()
        {
            return asyncCall(QStringLiteral("sendCmdCPAAHandle"));
        }
    
    Q_SIGNALS: // SIGNALS
        void onBluetoothPowerStatus(bool status);
        void onBluetoothStatus(bool status);
        void onChangeTemperature(double newTemperature, bool isEurope, bool isTemperatureUnitC);
        void onGetWifiAndBluePowerStatus(bool status);
        void onOTAErrInfo(bool errInfo);
        void onSetHeaterLeftLevel(int value);
        void onSetHeaterRightLevel(int value);
        void onSetIs12hFormat(bool status);
        void onSetIsAcMark(bool status);
        void onSetIsAccount(bool status);
        void onSetIsActive(bool status);
        void onSetIsCancel(bool status);
        void onSetIsDownload(bool status);
        void onSetIsStatusOTA(int status);
        void onSetIsNotify(bool status);
        void onSetIsError(bool status);
        void onSetIsTAfromSMD(bool status);
        void onSetSttOff(int value);
        void onSetTemperature(double value);
        void onSetValueFan(int value);
        void onSetWarmLeftAC(int value);
        void onSetWarmRightAC(int value);
        void onSetWindLeftAC(int value);
        void onSetWindRightAC(int value);
        void onWifiPowerStatus(bool status);
        void onWifiStatus(bool status);
        void onSendSysTime(const QString &timeSys, const QString &mediran);
        void onShowUpdateDisableIcon(bool status);
        void onSetIsAndroidSet(bool status);
        void onSetIsHFPAvailable(bool status);
        void onSetBatteryLevel(int value);
        void onSetSignalStrength(int value);
        void onSetIsFrontSeatECUFailureSts(bool status);
        void onSetRdsStatus(bool status);
        void onsSetTelematicsSrvState(bool status);
        void onSetCntdSrvStgState(bool status);
        void onSetMuteStatus(bool status);
        void onSetRadioWaveIntensity(int status);
        void onSetIsFeedbackInfoHFP(bool status);
        void onSetIsIGACCStatus(bool status);
        void onSetIsACFailureStatus(bool status);
        void onSetIsFeedbackBatterLevelHFP(bool status);
        void onSetIsHeaterSeatEquipped(bool status);
        void onSetIsSteeringWheelHeaterEquipped(bool status);
        void onSetResultTemperatureFromAC(QString interger, QString decimal);
        void onSetIsInteruptCan478(bool status);
        void onSetIsInteruptCan3E8(bool status);
        void onSetLowTemperature(bool status);
        void onSetHighTemperature(bool status);
    };
}

#endif
