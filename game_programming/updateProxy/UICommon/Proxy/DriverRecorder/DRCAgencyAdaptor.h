#ifndef DRC_ADAPTER_H
#define DRC_ADAPTER_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "DRCAgency.h"
#include "DRCAgencyDefine.h"
namespace uicommon{
    class DRCAgencyAdaptor: public QDBusAbstractAdaptor{
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.DRCAgency")
        Q_CLASSINFO("D-Bus Introspection", " "
                                          " <interface name=\"ese.hmi.DRCAgency\">                                                                \n"                                          
                                          "     <signal name=\"onSetCalibrationResultChanged\">                                                   \n" 
                                          "         <arg direction=\"out\" type=\"i\" name=\"result\">                                            \n"                                               
                                          "     </signal>                                                                                         \n" 
                                          " <method name=\"requestDRCService\">                                                                   \n"  
                                          "   <arg  direction=\"out\" type=\"(i)\">                                                               \n"  
                                          "   <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::DRCAgencyRequest\">     \n"  
                                          "   <arg name=\"reqValue\" direction=\"out\" type=\"i\">                                                \n"
                                          " </method>                                                                                             \n" 
                                          " <signal name=\"onDRCServiceResponse\">                                                                \n"                              
                                          "   <arg type=\"(i)\" direction=\"out\">                                                                \n"                            
                                          "   <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::DRCInvocationResult\">  \n"                                                                                          
                                          "   <arg type=\"(i)\" direction=\"out\">                                                                \n"                            
                                          "   <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out1\" value=\"uicommon::DRCAgencyRequest\">     \n"                                                                                       
                                          "   <arg type=\"i\" direction=\"out\">                                                                  \n"                          
                                          " </signal>                                                                                             \n"   
                                          " <signal name=\"onRecordingStatusChanged\">                                                       \n"                                
                                          "   <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::RecordingStatus\"> \n"                                                                                          
                                          "   <arg type=\"(i)\" direction=\"out\">                                                                \n"                                                     
                                          " </signal>                                                                                             \n"   
                                          " <method name=\"getRecordingStatus\">                                                       \n"                                
                                          "   <annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"uicommon::RecordingStatus\"> \n"                                                                                          
                                          "   <arg type=\"(i)\" direction=\"out\">                                                                \n"                                                     
                                          " </method>                                                                                             \n"   
                                          " <method name=\"toPreviewMode\">                                                                                              \n"   
                                          " <method name=\"outPreviewMode\">                                                                                              \n"   
                                          " <method name=\"getDVRVersion\">                                                                       \n"
                                          "   <arg direction=\"out\" type=\"s\">                                                                  \n"        
                                          " </method>                                                                                             \n"   
                                          " <method name=\"isSDCardPlugIn\">                                                                       \n"
                                          "   <arg direction=\"out\" type=\"b\">                                                                  \n"        
                                          " </method>                                                                                             \n"   
                                          " <method name=\"stopRecordingForTransition\">                                                           \n"              
                                          " <method name=\"confirmDisconnectionWithAllowanceToAppearAgain\">\n"              
                                          "<arg type=\"b\" direction=\"out\">\n"
                                          "</method> \n"
                                          " <method name=\"confirmHighTemperature\">                                                                 \n"              
                                          " <method name=\"confirmUpdating\">                                                                 \n"              
                                          " <method name=\"confirmStopRecoding\">                                                                  \n"              
                                          " <method name=\"confirmDropSDCard\">                                                                  \n"            
                                          " <method name=\"confirmResumesRecording\">                                                                  \n"  
                                          " <method name=\"confirmFileAccessError\">                                                                  \n"              
                                          " <method name=\"indicateEmptyStorage\">                                                                  \n"              
                                          " <signal name=\"onDRVConnectStatusChanged\">    \n"
                                          " <signal name=\"onSDCardPlugInOutStatusChanged\" type=\"b\" direction=\"out\">    \n"
                                          " <signal name=\"requestStopRecordingSuccessfully\">    \n"
                                          " <arg direction=\"out\" type=\"b\">             \n"
                                          " </signal>                                      \n"
                                          " </interface>                                                                                          \n"   
                                          " ")
        public:
            DRCAgencyAdaptor(DRCAgency* parent);
            inline DRCAgency* parent() const{
                return static_cast<DRCAgency*>(QObject::parent());
            }
            virtual ~DRCAgencyAdaptor();
        public Q_SLOTS:
            void requestDRCService(uicommon::DRCAgencyRequest req, int reqValue);
            QString getDVRVersion();
            void stopRecordingForTransition();
            void confirmStopRecoding();
            void indicateEmptyStorage();
            uicommon::RecordingStatus getRecordingStatus();
            void toPreviewMode();

            void outPreviewMode();

            bool isSDCardPlugIn();

            void confirmHighTemperature();

            void confirmDisconnectionWithAllowanceToAppearAgain(bool);

            void confirmUpdating();

            void confirmDropSDCard();

            void confirmFileAccessError();

            void confirmResumesRecording();

        Q_SIGNALS:
            void onSetCalibrationResultChanged(int);

            void onDRCServiceResponse(uicommon::DRCInvocationResult, uicommon::DRCAgencyRequest, int);

            void onDRVConnectStatusChanged(bool);

            void requestStopRecordingSuccessfully();
            
            void onRecordingStatusChanged(uicommon::RecordingStatus);

            void onSDCardPlugInOutStatusChanged(bool);
    };
};

#endif //DRC_ADAPTER_H
