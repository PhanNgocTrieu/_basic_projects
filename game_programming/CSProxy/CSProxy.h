#ifndef __CONNECTED_SERVICE_PROXY_H__
#define __CONNECTED_SERVICE_PROXY_H__

#include <QQuickImageProvider>
#include <QDBusArgument>
#include <QObject>
#include <connectedservicewrap/connectedservicewrapper.h>


class ConnectedServiceProxy : public QDBusAbstractInterface {
    Q_OBJECT
    // Q_CLASSINFO("D-Bus Interface", "ese.hmi.connectedservice")

    public:
        Q_PROPERTY(bool teleConFlag READ teleConFlag WRITE setTeleConFlag)
        inline bool teleConFlag() const { return qvariant_cast<bool>( property("teleConFlag")); }
        inline void setTeleConFlag(bool value) { setProperty("teleConFlag", QVariant::fromValue(value)); }

        Q_PROPERTY(bool conSetStt READ conSetStt WRITE setConSetStt)
        inline bool conSetStt() const { return qvariant_cast<bool>( property("conSetStt")); }
        inline void setConSetStt(bool value) { setProperty("conSetStt", QVariant::fromValue(value)); }


    Q_SIGNALS:
        void teleConFlagChanged();

    public:
        static inline const char *staticInterfaceName() { return "ese.hmi.connectedservice"; }
        static ConnectedServiceProxy& getInstance();
        ~ConnectedServiceProxy();

    public:
        srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag requestTelematicFlag() const { return m_flagStatusHolder.m_telematic; }
        
    private:
        ConnectedServiceFlags m_flagStatusHolder;

}

#endif // __CONNECTED_SERVICE_PROXY_H__