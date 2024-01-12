#ifndef ACP_AGENCY_H
#define ACP_AGENCY_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QDBusVariant>
#include <QDBusArgument>

namespace uicommon {
    class ACPAgency: public QObject {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.acpagency")
        public:
            virtual ~ACPAgency() {}
            struct SongInfo {
                QString songName;
                QString artistName;
                QString albumName;
                int32_t trackNum = 0;

                SongInfo() = default;
                SongInfo(const SongInfo& other):songName(other.songName),
                    artistName(other.artistName),
                    albumName(other.albumName),
                    trackNum(other.trackNum)
                {}
                SongInfo& operator =(const SongInfo& other) {
                    songName    = other.songName ;
                    artistName  = other.artistName ;
                    albumName   = other.albumName ;
                    trackNum    = other.trackNum ;
                    return *this;
                }
            };
            struct ArtworkData {
                int32_t formatCode = 0;     // image format
                int32_t imageWidth = 0;     // image width
                int32_t imageHeight = 0;    // image height
                int32_t rowSize = 0;        // row size
                QString buf;        // artwork data

                ArtworkData() = default;
                ArtworkData(const ArtworkData& other):formatCode(other.formatCode),
                    imageWidth(other.imageWidth),
                    imageHeight(other.imageHeight),
                    rowSize(other.rowSize),
                    buf(other.buf)
                {}

                ArtworkData& operator =(const ArtworkData& other) {
                    formatCode    = other.formatCode ;
                    imageWidth  = other.imageWidth ;
                    imageHeight   = other.imageHeight ;
                    rowSize    = other.rowSize ;
                    buf    = other.buf ;
                    return *this;
                }
            };

            typedef enum {
                ShuffleModeOff,
                ShuffleModeTracks,
                ShuffleModeAlbums
            } ShuffleMode;

            typedef enum {
                NoneSts,
                StopSts,
                PlayingSts,
                PausedSts,
                PlayPauseSts,
                FastForwardSts,
                FastRewindSts,
            } PlayingStatus;

            typedef enum {
                AlertChannel        = 0, // Channel is Ringtones, alarms, and other high-prioritysounds
                MediaChannel        = 1, // Channel is Entertainment,default (e.g.: music playback)
                TelephoneChannel    = 2, // Channel is Telephone
                SiriChannel         = 3, // Channel is Siri
                AlternateChannel    = 4, // Channel is Maps , UI Sounds, Notifications etc.
                VideoChannel        = 5, // Channel is video
                EnhencedSiriChannel = 6, //Channel is Enhenced Siri
                MaxChannel          = 7  // channel max number
            } ChannelTypeCarplay;

            typedef enum {
                Active = 0,         // ChannelStatus is Active
                Deactive = 1,       // ChannelStatus is Deactive
                Resumed = 2,        // ChannelStatus is Resumed
                Suspended = 3,      // ChannelStatus is Suspended
                Denied = 4,         // ChannelStatus is Denied
                ActiveApply = 5,    // ChannelStatus is channel activing
                DeactiveApply = 6,  // ChannelStatus is channel deactiving
                Max = 7             // Channel Status Num Max
            } ChannelStatusCarplay;

        public slots:
            virtual int getSessionState() = 0;
            virtual bool setOperationMode(int mode) = 0;

            virtual int getBrightness() = 0;

            virtual bool setBrightness(int value) = 0;
            virtual bool setSourceOn(bool value) = 0;
            virtual bool trackSongCommand(int value) = 0;
            virtual bool previousSong() = 0;
            virtual bool nextSong() = 0;
            virtual bool ipodKeyRelease() = 0;
            virtual bool enjectKeyEvent(int keyCode, int keyStatus) = 0;

            virtual bool switchApplication(int appId, int cpAppId = 0, bool isSessionEnd = false,bool isExitCam = false ,QString phoneNum = "") = 0;
            virtual bool reqCarPlayImageQuality() = 0;
            virtual bool interruptArbitration(int type, bool normalSource = false, bool isEnter = false) = 0;
            virtual bool setContrastStepValue(QString detail) = 0;
            virtual bool setColorStepValue(QString detail) = 0;
            virtual QString getContrastStepValue() = 0;
            virtual QString getColorStepValue() = 0;
            virtual bool setVAStatus(int status) = 0;

            virtual bool setDayContrastValue(int value) = 0;
            virtual bool setDayColorValue(int value) = 0;
            virtual int getDayContrastValue() = 0;
            virtual int getDayColorValue() = 0;

            virtual bool setNightContrastValue(int value) = 0;
            virtual bool setNightColorValue(int value) = 0;
            virtual int getNightContrastValue() = 0;
            virtual int getNightColorValue() = 0;

        signals:
            void onSessionStateChanged(int oldState, int newState);
            void onUSBConnectionStateChanged(int oldState, int newState);
            void onWifiConnectionStateChanged(int oldState, int newState);
            void onBrightnessChanged(int value);
            void onColorChanged(int value);
            void onConstractChanged(int value);
            void onChannelActive(int channelType, int channelStatus);
            void onSongInfoChanged(uicommon::ACPAgency::SongInfo songInfo);
            void onArtworkInfoChanged(uicommon::ACPAgency::ArtworkData artworkData);
            void onShuffleModeChanged(int value);
            void onRepeatModeChanged(int value);
            void onPlayingStatusChanged(int value);
            void onSiriStateChanged(int siriState);
            void onSongPlayTimeChanged(int value);
            void onSongTotalTimeChanged(int value);
            void onNotifyCarPlayColorValue(int value, bool isDay);
            void onNotifyCarPlayContrastValue(int value, bool isDay);
        protected:
            ACPAgency() {};
        
    };
}

Q_DECLARE_METATYPE(uicommon::ACPAgency::SongInfo)

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::ACPAgency::SongInfo& songInfo);
const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::ACPAgency::SongInfo& songInfo);

Q_DECLARE_METATYPE(uicommon::ACPAgency::ArtworkData)

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::ACPAgency::ArtworkData& artworkData);
const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::ACPAgency::ArtworkData& artworkData);

#endif
