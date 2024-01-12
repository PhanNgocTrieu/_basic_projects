#ifndef UICOMMON_MEDIA_ADAPTOR_H
#define UICOMMON_MEDIA_ADAPTOR_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>
#include "MediaAgency.h"

namespace uicommon 
{
    class MediaAgencyAdaptor : public QDBusAbstractAdaptor 
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.MediaAgency")
        Q_CLASSINFO("D-Bus Introspection", " "
            " <interface name=\"ese.hmi.MediaAgency\">                                              \n"
            "   <method name=\"getCurrentService\">                                                 \n"  
            "       <arg  direction=\"out\" type=\"s\">                                             \n" 
            "   </method>                                                                           \n" 
            "   <method name=\"requestService\">                                                    \n"
            "       <arg  direction=\"in\" type=\"s\">                                              \n"
            "       <arg  direction=\"in\" type=\"b\">                                              \n"
            "   </method>                                                                           \n"
            "   <signal name=\"onServiceChanged\">                                                  \n"
            "       <arg type=\"s\" direction=\"out\">                                              \n"
            "       <arg type=\"s\" direction=\"out\">                                              \n"
            "   </signal>                                                                           \n"
            "   <method name=\"muteAllMediaSource\">                                                \n"   
            "   <method name=\"unMuteAllMediaSource\">                                              \n"
            " </interface>                                                                          \n"
            " ")
        protected:
            MediaAgencyAdaptor(MediaAgency* parent);

            MediaAgency* parent() const;

        public:
            static void initialize(MediaAgency* parent);

            static MediaAgencyAdaptor* getInstance();

            virtual ~MediaAgencyAdaptor();

        public Q_SLOTS:
            void requestService(const QString& servicename, bool force = false);

            QString getCurrentService();

            void muteAllMediaSource();

            void unMuteAllMediaSource();
            
        Q_SIGNALS:
            void onServiceChanged(const QString& oldService, const QString& newService);
    };
}
#endif //UICOMMON_MEDIA_ADAPTOR_H