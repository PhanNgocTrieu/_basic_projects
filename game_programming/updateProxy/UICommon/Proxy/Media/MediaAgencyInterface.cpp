#include "MediaAgencyInterface.h"
namespace uicommon
{
    static DBusWatcher listener;

    void DBusWatcher::listen()
    {
        static std::once_flag flag;
        std::call_once(flag,[this]() -> void
        {
            QDBusConnectionInterface *dbusInterface = QDBusConnection::sessionBus().interface();
            m_isServiceReady = dbusInterface->isServiceRegistered("ese.hmi.MediaAgency");
            if (m_isServiceReady == false) {
                QDBusServiceWatcher* serviceWatcher = new QDBusServiceWatcher("ese.hmi.MediaAgency", QDBusConnection::sessionBus());
                if (serviceWatcher) {
                    QObject::connect(serviceWatcher, &QDBusServiceWatcher::serviceRegistered, this, [this, serviceWatcher](const QString &serviceName)
                    {
                        m_isServiceReady = true;
                        serviceWatcher->deleteLater();
                    }
                    );
                }
            } else {
                qInfo() << "Service ese.hmi.MediaAgency is ready";
            }
        });
    }

    void MediaAgencyInterface::initialize()
    {
        static std::once_flag flag;
        std::call_once(flag,[=]() -> void
        {
            listener.listen();
        });
    }

    bool MediaAgencyInterface::isServiceReady()
    {
        return listener.isServiceReady();
    }


    MediaAgencyInterface* MediaAgencyInterface::getInstance()
    {
        if (listener.isServiceReady())
        {
            static MediaAgencyInterface instance("ese.hmi.MediaAgency","/MediaAgency",QDBusConnection::sessionBus());
            return &instance;
        }
        return nullptr;
    }
    
    MediaAgencyInterface::MediaAgencyInterface(const QString& service, const QString& path, const QDBusConnection& connection, QObject* parent)
        :QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
        
    }

    MediaAgencyInterface::~MediaAgencyInterface(){
        
    }
};
