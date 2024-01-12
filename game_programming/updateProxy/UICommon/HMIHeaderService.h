#ifndef HMIHEADERSERVICE_H
#define HMIHEADERSERVICE_H

#include <QObject>
#include "UICommon_global.h"

namespace uicommon {
    class UICOMMON_EXPORT HMIHeaderService:public QObject {
     Q_OBJECT
     Q_CLASSINFO("D-Bus Interface", "ese.hmi.header")
    public:
        virtual ~HMIHeaderService();
    
    public slots:
        virtual void OTAErrInfo(bool errInfo) = 0;
        virtual void bluetoothPowerStatus(bool status) = 0;
        virtual void bluetoothStatus(bool status) = 0;
        virtual void changeTemperature(double newTemperature, bool isEurope, bool isTemperatureUnitC) = 0;
        virtual void setHeaterLeftLevel(int value) = 0;
        virtual void setHeaterRightLevel(int value) = 0;
        virtual void setIs12hFormat(bool status) = 0;
        virtual void setIsAcMark(bool status) = 0;
        virtual void setIsAccount(bool status) = 0;
        virtual void setIsActive(bool status) = 0;
        virtual void setIsCancel(bool status) = 0;
        virtual void setIsDownload(bool status) = 0;
        virtual void setIsStatusOTA(int status) = 0;
        virtual void setIsNotify(bool status) = 0;
        virtual void setIsError(bool status) = 0;
        virtual void setIsTAfromSMD(bool status) = 0;
        virtual void setSttOff(int value) = 0;
        virtual void setTemperature(double value) = 0;
        virtual void setValueFan(int value) = 0;
        virtual void setWarmLeftAC(int value) = 0;
        virtual void setWarmRightAC(int value) = 0;
        virtual void setWindLeftAC(int value) = 0;
        virtual void setWindRightAC(int value) = 0;
        virtual void wifiPowerStatus(bool status) = 0;
        virtual void wifiStatus(bool status) = 0;
        virtual void sendSysTime(const QString &timeSys, const QString &mediran) = 0;
        virtual void showUpdateDisableIcon(bool status) = 0;
        virtual void setIsAndroidSet(bool status) = 0;
        virtual void setIsHFPAvailable(bool status) = 0;
        virtual void setBatteryLevel(int value) = 0;
        virtual void setSignalStrength(int value) = 0;
        virtual void setIsFrontSeatECUFailureSts(bool status) = 0;
        virtual void setRdsStatus(bool status) = 0;
        virtual void setTelematicsSrvState(bool status) = 0;
        virtual void setCntdSrvStgState(bool status) = 0;
        virtual void setMuteStatus(bool status) = 0;
        virtual void setIsVolumeChanging(bool status) = 0;
        virtual void setRadioWaveIntensity(int status) = 0;
        virtual void setIsFeedbackSignalStrengthHFP(bool status) = 0;
        virtual void setIsIGACCStatus(bool status) = 0;
        virtual void setIsACFailureStatus(bool status) = 0;
        virtual void setIsFeedbackBatterLevelHFP(bool status) = 0;
        virtual void setIsHeaterSeatEquipped(bool status) = 0;
        virtual void setIsSteeringWheelHeaterEquipped(bool status) = 0;
        virtual void setResultTemperatureFromAC(QString interger, QString decimal) = 0;
        virtual void setIsInteruptCan478(bool status) = 0;
        virtual void setIsInteruptCan3E8(bool status) = 0;
        virtual void setLowTemperature(bool status) = 0;
        virtual void setHighTemperature(bool status) = 0;
        virtual void setBlackScreenCPAA(bool isShow) = 0;
        virtual void sendCmdCPAAHandle() = 0;
        
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
