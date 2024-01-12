#ifndef HMIHEADERSERVICEADAPTOR_H
#define HMIHEADERSERVICEADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "HMIHeaderService.h"
#include "UICommon_global.h"

namespace uicommon {
    /*
     * Adaptor class for interface ese.hmi.sys
     */
    class UICOMMON_EXPORT HMIHeaderServiceAdaptor: public QDBusAbstractAdaptor
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.header")
        Q_CLASSINFO("D-Bus Introspection", ""
        "  <interface name=\"ese.hmi.header\">\n"
        "    <signal name=\"onOTAErrInfo\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"errInfo\"/>\n"
        "    </signal>\n"
        "    <method name=\"OTAErrInfo\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"errInfo\"/>\n"
        "    </method>\n"
        "    <signal name=\"onWifiStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"wifiStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onBluetoothStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"bluetoothStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onBluetoothPowerStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"bluetoothPowerStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onWifiPowerStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"wifiPowerStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onGetWifiAndBluePowerStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <signal name=\"onSetIs12hFormat\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIs12hFormat\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsTAfromSMD\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsTAfromSMD\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsAccount\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsAccount\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsDownload\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsDownload\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsStatusOTA\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsStatusOTA\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsNotify\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsNotify\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"

        "    <signal name=\"onSetIsActive\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsActive\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsError\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsError\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsCancel\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsCancel\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetTemperature\">\n"
        "      <arg direction=\"out\" type=\"d\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setTemperature\">\n"
        "      <arg direction=\"in\" type=\"d\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onChangeTemperature\">\n"
        "      <arg direction=\"out\" type=\"d\" name=\"newTemperature\"/>\n"
        "      <arg direction=\"out\" type=\"b\" name=\"isEurope\"/>\n"
        "      <arg direction=\"out\" type=\"b\" name=\"isTemperatureUnitC\"/>\n"
        "    </signal>\n"
        "    <method name=\"changeTemperature\">\n"
        "      <arg direction=\"in\" type=\"d\" name=\"newTemperature\"/>\n"
        "      <arg direction=\"in\" type=\"b\" name=\"isEurope\"/>\n"
        "      <arg direction=\"in\" type=\"b\" name=\"isTemperatureUnitC\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetSttOff\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setSttOff\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetHeaterLeftLevel\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setHeaterLeftLevel\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetHeaterRightLevel\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setHeaterRightLevel\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetWindLeftAC\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setWindLeftAC\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetWindRightAC\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setWindRightAC\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetWarmLeftAC\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setWarmLeftAC\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetWarmRightAC\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setWarmRightAC\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetValueFan\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setValueFan\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsAcMark\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsAcMark\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSendSysTime\">\n"
        "      <arg direction=\"out\" type=\"s\" name=\"time\"/>\n"
        "      <arg direction=\"out\" type=\"s\" name=\"mediran\"/>\n"
        "    </signal>\n"
        "    <method name=\"sendSysTime\">\n"
        "      <arg direction=\"in\" type=\"s\" name=\"time\"/>\n"
        "      <arg direction=\"in\" type=\"s\" name=\"mediran\"/>\n"
        "    </method>\n"
        "    <signal name=\"onShowUpdateDisableIcon\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"showUpdateDisableIcon\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"    
        "    <signal name=\"onSetIsAndroidSet\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsAndroidSet\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsHFPAvailable\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsHFPAvailable\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetBatteryLevel\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setBatteryLevel\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetSignalStrength\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"value\"/>\n"
        "    </signal>\n"
        "    <method name=\"setSignalStrength\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"value\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsFrontSeatECUFailureSts\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsFrontSeatECUFailureSts\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsFeedbackSignalStrengthHFP\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsFeedbackSignalStrengthHFP\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsIGACCStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsIGACCStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsACFailureStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsACFailureStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetRdsStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setRdsStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onsSetTelematicsSrvState\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setTelematicsSrvState\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetCntdSrvStgState\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setCntdSrvStgState\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetMuteStatus\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setMuteStatus\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsVolumeChanging\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsVolumeChanging\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetRadioWaveIntensity\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setRadioWaveIntensity\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsFeedbackBatterLevelHFP\">\n"
        "      <arg direction=\"out\" type=\"i\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsFeedbackBatterLevelHFP\">\n"
        "      <arg direction=\"in\" type=\"i\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsHeaterSeatEquipped\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsHeaterSeatEquipped\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsSteeringWheelHeaterEquipped\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsSteeringWheelHeaterEquipped\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetResultTemperatureFromAC\">\n"
        "      <arg direction=\"in\" type=\"s\" name=\"interger\"/>\n"
        "      <arg direction=\"in\" type=\"s\" name=\"decimal\"/>\n"
        "    </signal>\n"
        "    <method name=\"setResultTemperatureFromAC\">\n"
        "      <arg direction=\"in\" type=\"s\" name=\"interger\"/>\n"
        "      <arg direction=\"in\" type=\"s\" name=\"decimal\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsInteruptCan3E8\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsInteruptCan3E8\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetIsInteruptCan478\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setIsInteruptCan478\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetLowTemperature\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setLowTemperature\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <signal name=\"onSetHighTemperature\">\n"
        "      <arg direction=\"out\" type=\"b\" name=\"status\"/>\n"
        "    </signal>\n"
        "    <method name=\"setHighTemperature\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"status\"/>\n"
        "    </method>\n"
        "    <method name=\"setBlackScreenCPAA\">\n"
        "      <arg direction=\"in\" type=\"b\" name=\"isShow\"/>\n"
        "    </method>\n"
        "    <method name=\"sendCmdCPAAHandle\">\n"
        "    </method>\n"
        "  </interface>\n"
                "")

    public:
        HMIHeaderServiceAdaptor(uicommon::HMIHeaderService *parent);
        virtual ~HMIHeaderServiceAdaptor();



        inline uicommon::HMIHeaderService *parent() const
        { return static_cast<uicommon::HMIHeaderService *>(QObject::parent()); }

    public: // PROPERTIES
    public Q_SLOTS: // METHODS
        void OTAErrInfo(bool errInfo);
        void bluetoothPowerStatus(bool status);
        void bluetoothStatus(bool status);
        void changeTemperature(double newTemperature, bool isEurope, bool isTemperatureUnitC);
        void setHeaterLeftLevel(int value);
        void setHeaterRightLevel(int value);
        void setIs12hFormat(bool status);
        void setIsAcMark(bool status);
        void setIsAccount(bool status);
        void setIsActive(bool status);
        void setIsCancel(bool status);
        void setIsDownload(bool status);
        void setIsStatusOTA(int status);
        void setIsNotify(bool status);
        void setIsError(bool status);
        void setIsTAfromSMD(bool status);
        void setSttOff(int value);
        void setTemperature(double value);
        void setValueFan(int value);
        void setWarmLeftAC(int value);
        void setWarmRightAC(int value);
        void setWindLeftAC(int value);
        void setWindRightAC(int value);
        void wifiPowerStatus(bool status);
        void wifiStatus(bool status);
        void sendSysTime(const QString &timeSys, const QString &mediran);
        void showUpdateDisableIcon(bool status);
        void setIsAndroidSet(bool status);
        void setIsHFPAvailable(bool status);
        void setBatteryLevel(int value);
        void setSignalStrength(int value);
        void setIsFrontSeatECUFailureSts(bool status);
        void setRdsStatus(bool status);
        void setTelematicsSrvState(bool status);
        void setCntdSrvStgState(bool status);
        void setMuteStatus(bool status);
        void setIsVolumeChanging(bool status);
        void setRadioWaveIntensity(int status);
        void setIsFeedbackSignalStrengthHFP(bool status);
        void setIsIGACCStatus(bool status);
        void setIsACFailureStatus(bool status);
        void setIsFeedbackBatterLevelHFP(bool status);
        void setIsHeaterSeatEquipped(bool status);
        void setIsSteeringWheelHeaterEquipped(bool status);
        void setResultTemperatureFromAC(QString interger, QString decimal);
        void setIsInteruptCan478(bool status);
        void setIsInteruptCan3E8(bool status);
        void setLowTemperature(bool status);
        void setHighTemperature(bool status);
        void setBlackScreenCPAA(bool isShow);
        void sendCmdCPAAHandle();

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
        void onSetIsVolumeChanging(bool status);
        void onSetRadioWaveIntensity(int status);
        void onSetIsFeedbackSignalStrengthHFP(bool status);
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
