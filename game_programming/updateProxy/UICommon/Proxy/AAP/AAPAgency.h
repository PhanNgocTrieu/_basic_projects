#ifndef AAP_AGENCY_H
#define AAP_AGENCY_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QDBusVariant>
#include <QDBusArgument>

namespace uicommon {
	class AAPAgency: public QObject {
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "ese.hmi.aapagency")
	public:
        virtual ~AAPAgency() {}
        struct MediaMetaData {
            QString song;
            QString artist;
            QString album_art;
            QString albumName;
            int32_t durationSeconds = 0;

            MediaMetaData() = default;
            MediaMetaData(const MediaMetaData& other):song(other.song),
                artist(other.artist),
                album_art(other.album_art),
                albumName(other.albumName),
                durationSeconds(other.durationSeconds)
            {}
            MediaMetaData& operator =(const MediaMetaData& other) {
                song        = other.song ;
                artist      = other.artist ;
                album_art   = other.album_art ;
                albumName   = other.albumName;
                durationSeconds  = other.durationSeconds;
                return *this;
            }
        };

        struct MediaStatus {
            int state = 0;
            bool shuffle =false;
            bool repeat = false;
            bool repeat_one = false;
            int32_t playbackSeconds = 0;

            MediaStatus() = default;
            MediaStatus(const MediaStatus& other):state(other.state),
                shuffle(other.shuffle),
                repeat(other.repeat),
                repeat_one(other.repeat_one),
                playbackSeconds(other.playbackSeconds)
            {}
            MediaStatus& operator =(const MediaStatus& other) {
                state    = other.state ;
                shuffle  = other.shuffle ;
                repeat  = other.repeat ;
                repeat_one   = other.repeat_one ;
                playbackSeconds = other.playbackSeconds;
                return *this;
            }
        };

        typedef enum {
            ReleaseStatus,
            PressStatus,
            ShortPressStatus,
            LongPressStatus
        } MediaKeyStatus;

        typedef enum {
            VoiceKey = 3,
            PlayPauseKey = 4,
            NextKey = 5,
            PreviousKey = 6,
            PlayKey = 7,
            PauseKey = 8
        } MediaKeyCode;

        typedef enum {
            UnknownPlayerStatus = 0,
            StoppedStatus,
            PlayingStatus,
            PausedStatus
        } MediaPlayerStatus;

        typedef enum {
            UnknownAudioStatus = -1,
            ActiveStatus,
            DeactiveStatus,
            SuspendStatus,
            ResumeStatus,
            MuteOffStatus,
            ErrorStatus,
            DeniedStatus,
            ActiveApplyStatus,
            DeactiveApplyStatus,
        } AudioStatus;

	public slots:
	    virtual int getCurrentState() = 0;
	    virtual bool setOperationMode(int mode) = 0;
        virtual bool setSourceOn(bool isSourceOn) = 0;
        virtual bool enjectKeyEvent(int keyCode, int keyStatus) = 0;
        virtual MediaMetaData getMediaMetaData() = 0;
        virtual MediaStatus getMediaStatus() = 0;
        virtual bool setContrastStepValue(QString detail) = 0;
        virtual bool setColorStepValue(QString detail) = 0;
        virtual QString getContrastStepValue() = 0;
        virtual QString getColorStepValue() = 0;

        virtual bool setDayContrastValue(int value) = 0;
        virtual bool setDayColorValue(int value) = 0;
        virtual int getDayContrastValue() = 0;
        virtual int getDayColorValue() = 0;

        virtual bool setNightContrastValue(int value) = 0;
        virtual bool setNightColorValue(int value) = 0;
        virtual int getNightContrastValue() = 0;
        virtual int getNightColorValue() = 0;
		
	signals:
	    void onStateChanged(int oldState, int newState);
        void onAudioMediaStatusChangeSignal(int oldState,int newState);
        void onMediaMetaDataChanged(uicommon::AAPAgency::MediaMetaData metaData);
        void onMediaStatusChanged(uicommon::AAPAgency::MediaStatus mediaStatus);
        void onNotifySetAAPDayColorValue(int value);
        void onNotifySetAAPDayContrastValue(int value);
        void onNotifySetAAPNightColorValue(int value);
        void onNotifySetAAPNightContrastValue(int value);
        void onNotifyAAPVRStatus(int vrStatus);

	protected:
	    AAPAgency() {};

	};
}

Q_DECLARE_METATYPE(uicommon::AAPAgency::MediaMetaData)

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::AAPAgency::MediaMetaData& metaData);
const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::AAPAgency::MediaMetaData& metaData);

Q_DECLARE_METATYPE(uicommon::AAPAgency::MediaStatus)

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::AAPAgency::MediaStatus& mediaStatus);
const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::AAPAgency::MediaStatus& mediaStatus);
#endif
