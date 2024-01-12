#include "VehicleGeneralStateAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
namespace uicommon{
        VehicleGeneralStateAdaptor::VehicleGeneralStateAdaptor(QObject* parent)
            : QDBusAbstractAdaptor{parent}
        {
            setAutoRelaySignals(true);
        }
        bool VehicleGeneralStateAdaptor::getIsDrivingRestriction(){
            return parent()->getIsDrivingRestriction();
        }
        void VehicleGeneralStateAdaptor::playSound(int soundType){
            return parent()->playSound(soundType);
        }
};