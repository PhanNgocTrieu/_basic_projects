#include "VehicleGeneralStateModel.h"
#include "VehicleGeneralStateInterface.h"
#include <Proxy/HMISystem/HMISystemServiceProxy.h>
namespace uicommon{
    QString VehicleGeneralStateModel::application = QCoreApplication::applicationName();
    VehicleGeneralStateModel& VehicleGeneralStateModel::getInstance(){
        static VehicleGeneralStateModel instance;
        return instance;
    }
    VehicleGeneralStateModel* VehicleGeneralStateModel::create(QQmlEngine *qmlEngine, QJSEngine *jsEngine){
        VehicleGeneralStateModel& instance = VehicleGeneralStateModel::getInstance();
        QJSEngine::setObjectOwnership(&instance,QJSEngine::CppOwnership);
        return &instance;
    }
    VehicleGeneralStateModel::VehicleGeneralStateModel(){
        QObject::connect(&uicommon::VehicleGeneralStateInterface::getInstance(), 
                         &uicommon::VehicleGeneralStateInterface::onIsDrivingRestrictionChanged,
                         this,
                         &VehicleGeneralStateModel::setIsDrivingRestriction);
        QObject::connect(&uicommon::VehicleGeneralStateInterface::getInstance(), 
                         &uicommon::VehicleGeneralStateInterface::onCarTypeChanged,
                         this,
                         &VehicleGeneralStateModel::setCarType);

    };
    void VehicleGeneralStateModel::setIsDrivingRestriction(bool status){
        if (m_isDriving != status){
            m_isDriving = status;
            emit isDrivingChanged();
        }
    }
    bool VehicleGeneralStateModel::getIsDrivingRestriction() const{
        return VehicleGeneralStateInterface::getInstance().getIsDrivingRestriction();
    }
    void VehicleGeneralStateModel::setCarType(const int& type){
        if (m_carType != type){
            m_carType = type;
            emit carTypeChanged();
        }
    }
    void VehicleGeneralStateModel::playSound(int soundType){
        VehicleGeneralStateInterface::getInstance().playSound(soundType);
    }
    void VehicleGeneralStateModel::popupStatus(const QString& popupStatus){
        uicommon::HMISystemServiceProxy::getInstance().setPopupStateOfApplication(application, popupStatus);
    }
};