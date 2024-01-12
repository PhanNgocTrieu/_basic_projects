#include <QtCore/QString>

#include "MediaAgencyAdaptor.h"

namespace uicommon
{
    static MediaAgencyAdaptor* staticInstance = nullptr;

    static MediaAgency* remoteObject = nullptr;

    void MediaAgencyAdaptor::initialize(MediaAgency* parent)
    {
        if (parent == nullptr) return;
        remoteObject = parent;
    }

    MediaAgencyAdaptor* MediaAgencyAdaptor::getInstance()
    {
        if (remoteObject)
        {
            static std::once_flag init;
            std::call_once(init,[=]
            {
                staticInstance = new MediaAgencyAdaptor(remoteObject);
                (void)QDBusConnection::sessionBus().registerObject("/MediaAgency",remoteObject);
                (void)QDBusConnection::sessionBus().registerService("ese.hmi.MediaAgency");

            });
            return staticInstance;
        }
        return nullptr;
    }

    MediaAgencyAdaptor::MediaAgencyAdaptor(MediaAgency* parent)
        :QDBusAbstractAdaptor(parent)
    {
        setAutoRelaySignals(true);
    }
    MediaAgencyAdaptor::~MediaAgencyAdaptor()
    {

    }
    QString MediaAgencyAdaptor::getCurrentService()
    {
        return parent()->getCurrentService();
    }
    void MediaAgencyAdaptor::requestService(const QString& serviceName, bool force)
    {
        QMetaObject::invokeMethod(parent(),"requestService",Q_ARG(QString, serviceName), Q_ARG(bool, force));
    }

    MediaAgency* MediaAgencyAdaptor::parent() const
    {
        return remoteObject;   
    }

    void MediaAgencyAdaptor::muteAllMediaSource()
    {
        parent()->muteAllMediaSource();
    }

    void MediaAgencyAdaptor::unMuteAllMediaSource()
    {
        parent()->unMuteAllMediaSource();
    }
}