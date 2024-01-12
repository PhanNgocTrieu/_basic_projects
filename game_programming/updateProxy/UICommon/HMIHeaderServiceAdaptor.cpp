#include "HMIHeaderServiceAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

namespace uicommon {
    /*
     * Implementation of adaptor class SysAdaptor
     */

    HMIHeaderService::~HMIHeaderService()
    {
    }

    HMIHeaderServiceAdaptor::HMIHeaderServiceAdaptor(uicommon::HMIHeaderService *parent)
        : QDBusAbstractAdaptor(parent)
    {
        // constructor
        setAutoRelaySignals(true);
    }

    HMIHeaderServiceAdaptor::~HMIHeaderServiceAdaptor()
    {
        // destructor
    }

    void HMIHeaderServiceAdaptor::OTAErrInfo(bool errInfo){
        parent()->OTAErrInfo(errInfo);
    }
    void HMIHeaderServiceAdaptor::bluetoothPowerStatus(bool status){
        parent()->bluetoothPowerStatus(status);
    }
    void HMIHeaderServiceAdaptor::bluetoothStatus(bool status){
        parent()->bluetoothStatus(status);
    }
    void HMIHeaderServiceAdaptor::changeTemperature(double newTemperature, bool isEurope, bool isTemperatureUnitC){
        parent()->changeTemperature(newTemperature,isEurope,isTemperatureUnitC);
    }
    void HMIHeaderServiceAdaptor::setHeaterLeftLevel(int value){
        parent()->setHeaterLeftLevel(value);
    }
    void HMIHeaderServiceAdaptor::setHeaterRightLevel(int value){
        parent()->setHeaterRightLevel(value);
    }
    void HMIHeaderServiceAdaptor::setIs12hFormat(bool status){
        parent()->setIs12hFormat(status);
    }
    void HMIHeaderServiceAdaptor::setIsAcMark(bool status){
        parent()->setIsAcMark(status);
    }
    void HMIHeaderServiceAdaptor::setIsAccount(bool status){
        parent()->setIsAccount(status);
    }
    void HMIHeaderServiceAdaptor::setIsActive(bool status){
        parent()->setIsActive(status);
    }
    void HMIHeaderServiceAdaptor::setIsCancel(bool status){
        parent()->setIsCancel(status);
    }
    void HMIHeaderServiceAdaptor::setIsDownload(bool status){
        parent()->setIsDownload(status);
    }
    void HMIHeaderServiceAdaptor::setIsStatusOTA(int status){
        parent()->setIsStatusOTA(status);
    }
    void HMIHeaderServiceAdaptor::setIsNotify(bool status){
        parent()->setIsNotify(status);
    }
    void HMIHeaderServiceAdaptor::setIsError(bool status){
        parent()->setIsError(status);
    }
    void HMIHeaderServiceAdaptor::setIsTAfromSMD(bool status){
        parent()->setIsTAfromSMD(status);
    }
    void HMIHeaderServiceAdaptor::setSttOff(int value){
        parent()->setSttOff(value);
    }
    void HMIHeaderServiceAdaptor::setTemperature(double value){
        parent()->setTemperature(value);
    }
    void HMIHeaderServiceAdaptor::setValueFan(int value){
        parent()->setValueFan(value);
    }
    void HMIHeaderServiceAdaptor::setWarmLeftAC(int value){
        parent()->setWarmLeftAC(value);
    }
    void HMIHeaderServiceAdaptor::setWarmRightAC(int value){
        parent()->setWarmRightAC(value);
    }
    void HMIHeaderServiceAdaptor::setWindLeftAC(int value){
        parent()->setWindLeftAC(value);
    }
    void HMIHeaderServiceAdaptor::setWindRightAC(int value){
        parent()->setWindRightAC(value);
    }
    void HMIHeaderServiceAdaptor::wifiPowerStatus(bool status){
        parent()->wifiPowerStatus(status);
    }
    void HMIHeaderServiceAdaptor::wifiStatus(bool status){
        parent()->wifiStatus(status);
    }
    void HMIHeaderServiceAdaptor::sendSysTime(const QString &timeSys, const QString &mediran) {
        parent()->sendSysTime(timeSys, mediran);
    }
    void HMIHeaderServiceAdaptor::showUpdateDisableIcon(bool status) {
        parent()->showUpdateDisableIcon(status);
    }
    void HMIHeaderServiceAdaptor::setIsAndroidSet(bool status) {
        parent()->setIsAndroidSet(status);
    }
    void HMIHeaderServiceAdaptor::setIsHFPAvailable(bool status) {
        parent()->setIsHFPAvailable(status);
    }
    void HMIHeaderServiceAdaptor::setBatteryLevel(int value) {
        parent()->setBatteryLevel(value);
    }
    void HMIHeaderServiceAdaptor::setSignalStrength(int value) {
        parent()->setSignalStrength(value);
    }
    void HMIHeaderServiceAdaptor::setIsFrontSeatECUFailureSts(bool status) {
        parent()->setIsFrontSeatECUFailureSts(status);
    }
    void HMIHeaderServiceAdaptor::setIsFeedbackSignalStrengthHFP(bool status){
        parent()->setIsFeedbackSignalStrengthHFP(status);
    }
    void HMIHeaderServiceAdaptor::setIsIGACCStatus(bool status) {
        parent()->setIsIGACCStatus(status);
    }
    void HMIHeaderServiceAdaptor::setIsACFailureStatus(bool status){
        parent()->setIsACFailureStatus(status);
    }
    void HMIHeaderServiceAdaptor::setRdsStatus(bool status){
        parent()->setRdsStatus(status);
    }
    void HMIHeaderServiceAdaptor::setTelematicsSrvState(bool status){
        parent()->setTelematicsSrvState(status);
    }
    void HMIHeaderServiceAdaptor::setCntdSrvStgState(bool status){
        parent()->setCntdSrvStgState(status);
    }
    void HMIHeaderServiceAdaptor::setMuteStatus(bool status){
        parent()->setMuteStatus(status);
    }
    void HMIHeaderServiceAdaptor::setRadioWaveIntensity(int status){
        parent()->setRadioWaveIntensity(status);
    }
    void HMIHeaderServiceAdaptor::setIsVolumeChanging(bool status){
        parent()->setIsVolumeChanging(status);
    }
    void HMIHeaderServiceAdaptor::setIsFeedbackBatterLevelHFP(bool status) {
        parent()->setIsFeedbackBatterLevelHFP(status);
    }
    void HMIHeaderServiceAdaptor::setIsHeaterSeatEquipped(bool status) {
        parent()->setIsHeaterSeatEquipped(status);
    }
    void HMIHeaderServiceAdaptor::setIsSteeringWheelHeaterEquipped(bool status){
        parent()->setIsSteeringWheelHeaterEquipped(status);
    }
    void HMIHeaderServiceAdaptor::setResultTemperatureFromAC(QString interger, QString decimal) {
        parent()->setResultTemperatureFromAC(interger, decimal);
    }
    void HMIHeaderServiceAdaptor::setIsInteruptCan478(bool status) {
        parent()->setIsInteruptCan478(status);
    }
    void HMIHeaderServiceAdaptor::setIsInteruptCan3E8(bool status) {
        parent()->setIsInteruptCan3E8(status);
    }
    void HMIHeaderServiceAdaptor::setLowTemperature(bool status) {
        parent()->setLowTemperature(status);
    }
    void HMIHeaderServiceAdaptor::setHighTemperature(bool status) {
        parent()->setHighTemperature(status);
    }
    void HMIHeaderServiceAdaptor::setBlackScreenCPAA(bool isShow) {
        parent()->setBlackScreenCPAA(isShow);
    }
    void HMIHeaderServiceAdaptor::sendCmdCPAAHandle() {
        parent()->sendCmdCPAAHandle();
    }
}
