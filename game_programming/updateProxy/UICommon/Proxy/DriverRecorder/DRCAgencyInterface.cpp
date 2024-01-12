#include "DRCAgencyInterface.h"

namespace uicommon{
    DRCAgencyInterface& DRCAgencyInterface::getInstance(){
        static DRCAgencyInterface singleton("ese.hmi.DRCAgency","/DRCAgency",QDBusConnection::sessionBus());
        return singleton;
    }
    
    DRCAgencyInterface::DRCAgencyInterface(const QString& service, const QString& path, const QDBusConnection& connection, QObject* parent)
        :QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
        
    }
    DRCAgencyInterface::~DRCAgencyInterface(){
        
    }
};