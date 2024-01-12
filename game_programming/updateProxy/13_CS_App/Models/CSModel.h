#ifndef CSMODEL_H
#define CSMODEL_H

#include <QObject>
#include <common/Logger.h>
#include <vector>
#include <map>
#include <connectedservicewrap/connectedservicewrapper.h>
#include <SysUI/SysUIInterface.h>
#include <PopupViewsEnums.h>
#include "Common/cscommon.h"
#include <ids_variantservice.h>
#include "Common/util.h"
#include <QSettings>
#include <QTimer>
#include <vehiclefuncwrap/vehicleservicewrapper.h>
#include <aisinsdkwrap/aisinsdkwrapper.h>
#include <QDate>
#include <HMIHeaderServiceProxy.h>
#include <UISetting.h>
#include "../UICommunication/UICommunication.h"
//Klocwork-Fix rule MISRA.NS.GLOBAL-START
namespace CsApp {
class CSModel : public QObject
{
    Q_OBJECT
    WLOG_DEF
public:
    //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
    explicit CSModel(QObject *_parent = nullptr);
    //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
    virtual ~CSModel();
    struct ConnectedStateHolder
    {
        bool isDisplay{false};
        bool isReminder{false};
//        uint32_t isKind{0};
//        uint32_t isDay{0};
//        uint32_t isMonth{0};
//        uint32_t isYear{0};
    };

    void setIsHome(const bool&);
    void setIsCanOpen(const bool&);
    void startOpening();
    void requestStartCall();

#ifdef HMI_SHOW_TEST_APP
    void StartWriting();
    void showPopupCS(const QString& idPopup);
    void cleanIniFile();
    void setIsDisplayWithIdScreen(const QString& idPopup);

#endif
    bool getHighDrivingRestrictionState();
    bool getTelematicsServiceState();
    bool getConnectedServiceSettingState();
    void receivePopupInfoFromSetting(const QString& screenIDMsg);
//    void receivePopupInfoFromSetting(const int& screenIDMsg);
    void requestShowPopup(const QString& idScreenName);

    void setConnectedInfomationRemindexOff(const QString& idScreenName);
    void setSuzukiInitCompleted(const bool val);
    //Klocwork-Fix rule MISRA.LINKAGE.EXTERN-START
    static std::string _pretty(const srvwrp::ConnectedServiceWrapper::ConnectedInformationKind& _kind);
    //Klocwork-Fix rule MISRA.LINKAGE.EXTERN-END
    //Klocwork-Fix rule CL.FFM.COPY, CL.FFM.ASSIGN-START
    CSModel(const CSModel&) = delete;
    CSModel& operator=(const CSModel&) = delete;
    //Klocwork-Fix rule CL.FFM.COPY, CL.FFM.ASSIGN-END
    void setPopupStateReady(const bool val);

protected:
    void initialize();
    void collectingData();
    bool isInRangeDriving(const QString&);


    // callback function definitions
    void statusHandleCallback();

public slots:
    void requestNetworkConnectionReset();
    void deleteConnectedInformation(const QString& listIndexDelete);
    bool requestOEMStatus();
    void onConnectedSrvUpdated();

private slots:
    //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-START
    static bool onDealerOEMChangedHandleCs(uint8_t dealeroem);
    //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-END
    
private:
    void connectedServiceInforCb(srvwrp::ConnectedServiceWrapper::Event, const srvwrp::ConnectedServiceWrapper::ConnectedServiceInfo &);
    void handleConnectedSerivceList(const std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation>& serviceList);
    void handleNetworkResetResult(const srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult& result);
    void handleConnectedServiceSettingList(const std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation>& serviceList);

protected: // Shotting methods
    //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
    QVariant readMemory(const QString &groupKey, const QString &_key);
    void writingMemory(const QString &groupKey, const QString &_key, const QVariant &_value);
    //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
    void handleToWriting();
    void openConnectedServiceInfor();
    void onCarSpeedChanged(const srvwrp::VehicleServiceInfo &info);

signals:
    void signalStartPopup(int);
    void needCompletedStatus();

private:
    // Creating a variable for service
    std::map<QString, ConnectedStateHolder>::iterator m_curPopup;
    std::map<QString, ConnectedStateHolder> m_displayScreen;
    static std::unordered_map<QString, POPUPENUM::E::EVT_STATE_ID_ROOT> m_displayScreenID;
    std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation> m_connectInfor;
    srvwrp::ConnectedServiceWrapper *m_connectedSrvWrap = nullptr;
    std::vector<srvwrp::signalsrv::Connect> m_connectedSrvConnections;
    aisinlbssdk::VariantService* m_variantService = nullptr;
    hmi::service::sysifapps *m_SysIF = nullptr;
    bool m_isHome{true};
    bool m_isCanOpenScreen{true};
    bool m_isPopupNotExpiredTimer{false};
    bool m_isCompletedOpening{false};
    bool m_isCompletedInitSuzuki{false};
    bool m_isFromSetting{false};
    QTimer* m_timer;
    bool m_isDriving{false};
    std::shared_ptr<srvwrp::VehicleServiceWrapper> m_variantVehicleSvwrp = nullptr;
    srvwrp::handle_t m_variantSvID = srvwrp::invalid_handle;
    srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult m_networkConnectionResetResult = srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Failure;
    QStringList m_infoList;
    uicommon::HMIHeaderServiceProxy& headerIF;
    uicommon::UISetting m_setting;
    CsApp::UICommunication& m_UIComCtrl;
    bool m_isPriority{true};
    bool m_checkIsDeteled{false};
    bool m_isRunFirstTime{true};
    bool m_isFinishPassingCS{true}; // temp true -> actual: false, true when Finish Passing
    bool m_isPopupReady{false};
    bool m_isNotCompletedFormCS18_23{true};
};
}
//Klocwork-Fix rule MISRA.NS.GLOBAL-END
#endif // CSMODEL_H