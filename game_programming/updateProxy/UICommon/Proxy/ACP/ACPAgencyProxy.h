#ifndef ACP_AGENCY_PROXY_H
#define ACP_AGENCY_PROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "ACPAgency.h"

namespace uicommon
{
    class ACPAgencyProxy : public QDBusAbstractInterface
    {
        Q_OBJECT
    public:
        static inline const char *staticInterfaceName()
        {
            return "ese.hmi.acpagency";
        }

        static ACPAgencyProxy &getInstance();
        virtual ~ACPAgencyProxy();

    protected:
        ACPAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    public Q_SLOTS:
        inline QDBusPendingReply<int> getBrightness()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getBrightness"), argumentList);
        }

        inline QDBusPendingReply<int> getSessionState()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("getSessionState"), argumentList);
        }

        inline QDBusPendingReply<bool> setBrightness(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setBrightness"), argumentList);
        }

        inline QDBusPendingReply<bool> setOperationMode(int mode)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(mode);
            return asyncCallWithArgumentList(QStringLiteral("setOperationMode"), argumentList);
        }

        inline QDBusPendingReply<bool> setSourceOn(bool value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("setSourceOn"), argumentList);
        }

        inline QDBusPendingReply<bool> trackSongCommand(int value)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(value);
            return asyncCallWithArgumentList(QStringLiteral("trackSongCommand"), argumentList);
        }

        inline QDBusPendingReply<bool> previousSong()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("previousSong"), argumentList);
        }

        inline QDBusPendingReply<bool> nextSong()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("nextSong"), argumentList);
        }

        inline QDBusPendingReply<bool> ipodKeyRelease()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("ipodKeyRelease"), argumentList);
        }

        inline QDBusPendingReply<bool> enjectKeyEvent(int keyCode, int keyStatus)
        {
            QList<QVariant> argumentList;
            argumentList << QVariant::fromValue(keyCode) << QVariant::fromValue(keyStatus);
            return asyncCallWithArgumentList(QStringLiteral("enjectKeyEvent"), argumentList);
        }
        
        inline QDBusPendingReply<bool> switchApplication(int appId, int cpAppId = 0,bool isSessionEnd = false,bool isExitCam  = false,QString phoneNum = "")
        {
            QList<QVariant> argumentList;
            argumentList << appId;
            argumentList << cpAppId;
            argumentList << isSessionEnd;
            argumentList << isExitCam;
            argumentList << phoneNum;
            return asyncCallWithArgumentList(QStringLiteral("switchApplication"), argumentList);
        }

        inline QDBusPendingReply<bool> reqCarPlayImageQuality()
        {
            QList<QVariant> argumentList;
            return asyncCallWithArgumentList(QStringLiteral("reqCarPlayImageQuality"),argumentList);
        }

        inline QDBusPendingReply<bool> interruptArbitration(int type, bool normalSource = false, bool isEnter = false)
        {
            QList<QVariant> argumentList;
            argumentList << type;
            argumentList << normalSource;
            argumentList << isEnter;
            return asyncCallWithArgumentList(QStringLiteral("interruptArbitration"), argumentList);
        }

        inline QDBusPendingReply<bool> requestSetCarPlayContrastStepValue(QString detail)
        {
            QList<QVariant> argList;
            argList << detail;
            return asyncCallWithArgumentList(QStringLiteral("setACPContrastStepValue"), argList);
        }

        inline QDBusPendingReply<bool> requestSetCarPlayColorStepValue(QString detail)
        {
            QList<QVariant> argList;
            argList << detail;
            return asyncCallWithArgumentList(QStringLiteral("setACPColorStepValue"), argList);
        }

        inline QDBusPendingReply<QString> requestGetCarPlayContrastStepValue()
        {
            QList<QVariant> argList;
            return asyncCallWithArgumentList(QStringLiteral("getACPContrastStepValue"), argList);
        }
        
        inline QDBusPendingReply<QString> requestGetCarPlayColorStepValue()
        {
            QList<QVariant> argList;
            return asyncCallWithArgumentList(QStringLiteral("getACPColorStepValue"), argList);
        }

        inline QDBusPendingReply<bool> setVAStatus(int status)
        {
            QList<QVariant> argumentList;
            argumentList << status;
            return asyncCallWithArgumentList(QStringLiteral("setVAStatus"), argumentList);
        }

        inline QDBusPendingReply<int>   requestGetACPDayColorValue()
        {
            QList<QVariant> argList;
            return asyncCallWithArgumentList(QStringLiteral("getACPDayColorValue"), argList);
        }

        inline QDBusPendingReply<int>   requestGetACPDayContrastValue()
        {
            QList<QVariant> argList;
            return asyncCallWithArgumentList(QStringLiteral("getACPDayContrastValue"), argList);
        }

        inline QDBusPendingReply<int>   requestGetACPNightColorValue()
        {
            QList<QVariant> argList;
            return asyncCallWithArgumentList(QStringLiteral("getACPNightColorValue"), argList);
        }

        inline QDBusPendingReply<int>   requestGetACPNightContrastValue()
        {
            QList<QVariant> argList;
            return asyncCallWithArgumentList(QStringLiteral("getACPNightContrastValue"), argList);
        }

        inline QDBusPendingReply<bool>   requestSetACPDayColorValue(int value)
        {
            QList<QVariant> argList;
            argList << value;
            return asyncCallWithArgumentList(QStringLiteral("setACPDayColorValue"), argList);
        }

        inline QDBusPendingReply<bool>   requestSetACPDayContrastValue(int value)
        {
            QList<QVariant> argList;
            argList << value;
            return asyncCallWithArgumentList(QStringLiteral("setACPDayContrastValue"), argList);
        }

        inline QDBusPendingReply<bool>   requestSetACPNightColorValue(int value)
        {
            QList<QVariant> argList;
            argList << value;
            return asyncCallWithArgumentList(QStringLiteral("setACPNightColorValue"), argList);
        }

        inline QDBusPendingReply<bool>   requestSetACPNightContrastValue(int value)
        {
            QList<QVariant> argList;
            argList << value;
            return asyncCallWithArgumentList(QStringLiteral("setACPNightContrastValue"), argList);
        }
    Q_SIGNALS:
        void onBrightnessChanged(int value);
        void onColorChanged(int value);
        void onConstractChanged(int value);
        void onSessionStateChanged(int oldState, int newState);
        void onUSBConnectionStateChanged(int oldState, int newState);
        void onWifiConnectionStateChanged(int oldState, int newState);
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
    };

}

#endif
