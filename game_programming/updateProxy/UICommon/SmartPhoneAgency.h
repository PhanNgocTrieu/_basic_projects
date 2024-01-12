#ifndef SMART_PHONE_AGENCY_H
#define SMART_PHONE_AGENCY_H

#include <QObject>
#include <QVariant>
#include <QList>
#include <QString>
#include <QDBusVariant>
#include <QDBusArgument>

namespace uicommon
{
    class SmartPhoneAgency : public QObject
    {
        Q_OBJECT
        Q_CLASSINFO("D-Bus Interface", "ese.hmi.smartphoneagency")
        Q_ENUMS(SesssionType)
        Q_ENUMS(DeviceType)
        Q_ENUMS(ConnectionType)
        Q_ENUMS(SessionEntrance)
        Q_ENUMS(SessionStatus)       

    public:
        enum SessionType
        {
            SessionTypeWire = 1,
            SessionTypeWireless = 2
        };

        enum DeviceType
        {
            DeviceTypeUnknown = 0,
            DeviceTypeCarPlay = 1,
            DeviceTypeAndroidAuto = 2,
            DeviceTypeBT = 3
        };        

        enum ConnectionType
        {
            ConnectionTypeNone = 0,
            ConnectionTypeWire = 1,
            ConnectionTypeWireless = 2,
            ConnectionTypeBoth = 3
        };
        
        enum SessionStatus
        {
            SessionStatusSetup,
            SessionStatusSuccess,
            SessionStatusEnd
        };

        enum SessionEntrance {
            FromSystemSetting = 1,
            FromSetting = 2,
            FromAddUSBDevice  = 3
        };
        
        struct DeviceInfo
        {
            // fix klocwork UNINIT.CTOR.MUST
            QString serialNum = QString(""); // device serial number
            QString btAddr = QString("");    // device bt address
            QString devName = QString("");   // device name
            bool supportFlg = false;   // device support status
            DeviceType deviceType = DeviceType::DeviceTypeUnknown;
            ConnectionType connectionType = ConnectionType::ConnectionTypeNone;
            SessionType sessionType = SessionType::SessionTypeWire;
            SessionStatus sessionStatus = SessionStatus::SessionStatusEnd;            
            bool isHFPConnect = false;
            bool isMAPConnect = false;
            bool isAVPConnect = false;
            bool isSPPConnect = false;
            bool isHFPUsedConnect = false;
            bool isMAPUsedConnect = false;
            bool isAVPUsedConnect = false;
            bool isSPPUsedConnect = false;
            
            DeviceInfo()
            {
                // fix klocwork UNINIT.CTOR.MUST
                serialNum = QString(""); // device serial number
                btAddr = QString("");    // device bt address
                devName = QString("");   // device name
            }
            DeviceInfo(const DeviceInfo& other):serialNum(other.serialNum),
                                               btAddr(other.btAddr),
                                               devName(other.devName),
                                               supportFlg(other.supportFlg),
                                               deviceType(other.deviceType),
                                               connectionType(other.connectionType),
                                               sessionType(other.sessionType),
                                               sessionStatus(other.sessionStatus),
                                               isHFPConnect(other.isHFPConnect),
                                               isMAPConnect(other.isMAPConnect),
                                               isAVPConnect(other.isAVPConnect),
                                               isSPPConnect(other.isSPPConnect),
                                               isHFPUsedConnect(other.isHFPUsedConnect),
                                               isMAPUsedConnect(other.isMAPUsedConnect),
                                               isAVPUsedConnect(other.isAVPUsedConnect),
                                               isSPPUsedConnect(other.isSPPUsedConnect)

            {}
            DeviceInfo& operator=(const DeviceInfo& other) {
                serialNum = other.serialNum;
                btAddr = other.btAddr;
                devName = other.devName;
                supportFlg = other.supportFlg;
                deviceType = other.deviceType;
                connectionType = other.connectionType;
                sessionType = other.sessionType;
                sessionStatus = other.sessionStatus;
                isHFPConnect = (other.isHFPConnect);
                isMAPConnect = (other.isMAPConnect);
                isAVPConnect = (other.isAVPConnect);
                isSPPConnect = (other.isSPPConnect);
                isHFPUsedConnect = (other.isHFPUsedConnect);
                isMAPUsedConnect = (other.isMAPUsedConnect);
                isAVPUsedConnect = (other.isAVPUsedConnect);
                isSPPUsedConnect = (other.isSPPUsedConnect);

                return *this;
            }
        };

        virtual ~SmartPhoneAgency() {}

    public slots:
        virtual bool isExisting(const QString &serialNum, const QString &btAddr) const = 0;
        virtual QList<uicommon::SmartPhoneAgency::DeviceInfo> getDeviceList() const = 0;
        virtual int startSession(const QString& btAddr, int devType, int type, int entrance) = 0;
        virtual int stopSession(const QString& btAddr, int devType, int type, int entrance) = 0;
        virtual bool getCurrentSession(uicommon::SmartPhoneAgency::DeviceInfo &retValue) = 0;
        virtual bool getUSBDevice(uicommon::SmartPhoneAgency::DeviceInfo &retValue) = 0;
        virtual bool devListRequest() = 0;
    signals:
        void onDeviceListUpdateSignal();
        void onDeviceListReplySignal();

    protected:
        SmartPhoneAgency(){};
    };
}

Q_DECLARE_METATYPE(uicommon::SmartPhoneAgency::DeviceInfo)

QDBusArgument& operator<<(QDBusArgument &argument, const uicommon::SmartPhoneAgency::DeviceInfo& devInfo);
const QDBusArgument& operator>>(const QDBusArgument &argument, uicommon::SmartPhoneAgency::DeviceInfo& devInfo);

QDBusArgument& operator<<(QDBusArgument &argument, const QList<uicommon::SmartPhoneAgency::DeviceInfo>& listDevInfo);
const QDBusArgument& operator>>(const QDBusArgument &argument, const QList<uicommon::SmartPhoneAgency::DeviceInfo>& listDevInfo);

#endif
