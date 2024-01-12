#ifndef VEHICLE_GENERAL_ADAPTOR_H
#define VEHICLE_GENERAL_ADAPTOR_H
#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "VehicleGeneralStateAgency.h"
namespace uicommon{
    /**
     * @brief The adaptor to control the DBus service and manage the Interfaces which are dependent
     * 
     */
    class VehicleGeneralStateAdaptor: public QDBusAbstractAdaptor{
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface","ese.hmi.VehicleGeneralState")
        Q_CLASSINFO("D-Bus Introspection", ""
                                           " <interface name=\"ese.hmi.VehicleGeneralState\">               \n"
                                           "      <signal name=\"onIsDrivingRestrictionChanged\">           \n"                                
                                           "           <arg direction=\"out\" type=\"b\">                   \n"                                
                                           "      </signal>                                                 \n"       
                                           "     <method name=\"getIsDrivingRestriction\">                  \n"                
                                           "           <arg direction=\"in\" type=\"b\">                    \n"   
                                           "     </method>                                                  \n"       
                                           "     <signal name=\"onCarTypeChanged\">                         \n"    
                                           "           <arg direction=\"in\" type=\"i\">                    \n"           
                                           "     </signal>                                                  \n" 
                                           "     <method name=\"playSound\">                                \n"
                                           "            <arg direction=\"out\" type=\"i\">                  \n"                      
                                           "     </method>                                                  \n" 
                                           " </interface>                                                   \n"
                                           ""
        )   
        private:
            inline VehicleGeneralStateAgency* parent(){
                return static_cast<VehicleGeneralStateAgency*>(QObject::parent());
            }
        public:
            VehicleGeneralStateAdaptor(QObject* parent);
        public slots:
            bool getIsDrivingRestriction();
            void playSound(int soundType);
        signals:
            void onIsDrivingRestrictionChanged(bool);
            void onCarTypeChanged(int);
    };
};
#endif //VEHICLE_GENERAL_ADAPTOR_H