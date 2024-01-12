#ifndef UICOMMON_MEDIA_AGENCY_H
#define UICOMMON_MEDIA_AGENCY_H

#include <QObject>

namespace uicommon 
{
    class MediaAgency : public QObject 
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.MediaAgency")
    public:
        virtual ~MediaAgency() {}

    public slots:
        virtual QString getCurrentService() = 0;

        virtual void requestService(const QString& serviceName, bool force) = 0;

        virtual void muteAllMediaSource() = 0;

        virtual void unMuteAllMediaSource() = 0;
        
    signals:
        void onServiceChanged(const QString& oldService, const QString& newService);
    protected:
        MediaAgency() = default;
    };
}

#endif //UICOMMON_MEDIA_AGENCY_H