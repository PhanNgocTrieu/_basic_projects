#include "VehicleGeneralStateInterface.h"
namespace uicommon{
    VehicleGeneralStateInterface::VehicleGeneralStateInterface(const QString& service,
                                                               const QString& objectPath,
                                                               const QDBusConnection& connection,
                                                               QObject* parent)
    : QDBusAbstractInterface(service, objectPath, interfaceName(), connection, parent)
    {

    }   
    VehicleGeneralStateInterface::~VehicleGeneralStateInterface()
    {

    }       

    VehicleGeneralStateInterface& VehicleGeneralStateInterface::getInstance(){
        static VehicleGeneralStateInterface instance("ese.hmi.VehicleGeneralState","/vehicleStates",QDBusConnection::sessionBus());
        return instance;
    }                                                  
};