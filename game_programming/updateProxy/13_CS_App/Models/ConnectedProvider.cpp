#include "ConnectedProvider.h" 
#include "ConnectedProviderPretty.cpp"
#include "Common/util.h"

inline const char* MODULE_NAME = "ConnectedServiceProvider";
inline const char* POPUP_CS_03 = "CS_03";
inline const char* POPUP_CS_04 = "CS_04";
inline const char* POPUP_CS_05 = "CS_05";
inline const char* POPUP_CS_06 = "CS_06";
inline const char* POPUP_CS_07 = "CS_07";
inline const char* POPUP_CS_08 = "CS_08";
inline const char* POPUP_CS_09 = "CS_09";
inline const char* POPUP_CS_10 = "CS_10";
inline const char* POPUP_CS_11 = "CS_11";
inline const char* POPUP_CS_12 = "CS_12";
inline const char* POPUP_CS_13 = "CS_13";
inline const char* POPUP_CS_14 = "CS_14";
inline const char* POPUP_CS_15 = "CS_15";
inline const char* POPUP_CS_16 = "CS_16";
inline const char* POPUP_CS_17 = "CS_17";
inline const char* POPUP_CS_18 = "CS_18";
inline const char* POPUP_CS_19 = "CS_19";
inline const char* POPUP_CS_20 = "CS_20";
inline const char* POPUP_CS_21 = "CS_21";
inline const char* POPUP_CS_22 = "CS_22";
inline const char* POPUP_CS_23 = "CS_23";
inline const char* POPUP_CS_24 = "CS_24";
inline const char* POPUP_CS_25 = "CS_25";

#define STD_OPTION_HAS_VALUE(OPT) (OPT != std::nullopt && OPT.has_value())
#ifndef BUILD_BOARD
inline const int START_OPENING_TIMER = 8000;
#else
inline const int START_OPENING_TIMER = 8000;
#endif
namespace CsApp {
    ConnectedServiceProvider* ConnectedServiceProvider::getInstance() {
        static ConnectedServiceProvider ins;
        return &ins;
    }

    ConnectedServiceProvider::ConnectedServiceProvider()
    : m_connectedSrvWrap(srvwrp::ConnectedServiceWrapper::instance()) 
    , m_variantService(aisinlbssdk::VariantService::getInstance())
    , m_variantVehicleSvwrp(srvwrp::VehicleServiceWrapper::instance())
    , headerIF(uicommon::HMIHeaderServiceProxy::getInstance())
    , m_UIComCtrl(CsApp::UICommunication::getInstance())
    {
        WLOG_INFO(MODULE_NAME << " ConnectedServiceProvider constructor! ");
        m_connectedServiceAdaptor = new uicommon::ConnectedServiceAdaptor(this);
        QDBusConnection::sessionBus().registerObject("/ConnectedServiceAgency", this);
        QDBusConnection::sessionBus().registerService("ese.hmi.csif");
    }

    ConnectedServiceProvider::~ConnectedServiceProvider() {
        // SafeDEL(m_timer);
    }

    void ConnectedServiceProvider::completePreStartOpening() {
        // Complete the process of pre-start opening
        m_sttHolder.m_isPreStartOpeningCompleted = true;
        // Start the process of start opening
        this->processPreStartOpening();
    }

    void ConnectedServiceProvider::popupIsReady() {
        if (m_sttHolder.m_isPopupReady) return;
        m_sttHolder.m_isPopupReady = true;
        this->requestStartOpening();
    }

    void ConnectedServiceProvider::homeIsReady() {
        if (m_sttHolder.m_isHomeAppReady) return;
        m_sttHolder.m_isHomeAppReady = true;
        this->requestStartOpening();
    }

    void ConnectedServiceProvider::initialize() {
        WLOG_INFO(MODULE_NAME << "Initializing");
        auto insert_func = [this](const QString& name, bool isDisp, bool isReminder) {
            m_displayScreen[name].isDisplay = isDisp;
            m_displayScreen[name].isReminder = isReminder;
        };
        insert_func("CS_03", false, false);
        insert_func("CS_04", false, false);
        insert_func("CS_05", false, false);
        insert_func("CS_06", false, false);
        insert_func("CS_07", false, false);
        insert_func("CS_08", false, false);

        // Initialize the start position of curPopup;
        m_curPopup = m_displayScreen.begin();
        m_variantSvID = m_variantVehicleSvwrp->init();
        m_connectedSrvConnections = m_connectedSrvWrap->registerCallback(srvwrp::ConnectedServiceWrapper::Event::MAX, std::bind(&ConnectedServiceProvider::connectedServiceCallbackReceived, this, std::placeholders::_1, std::placeholders::_2));
        m_variantVehicleSvwrp->registerVehicleServiceInfo(m_variantSvID, std::bind(&ConnectedServiceProvider::drivingCallback, this, std::placeholders::_1));
        m_variantService->onDealerOEMChanged.regEventFunc([this](){
            m_sttHolder.m_isHighDrvResState = m_variantService->isHighDrivingRestriction();
        });
        m_connectedSrvWrap->init();
        // m_timer = new QTimer(this);

        // QObject::connect(m_timer, &QTimer::timeout, this, [this](){
        //     WLOG_INFO(MODULE_NAME << " Timeout to trigger ");
            // m_timer->stop();
        //     this->requestStartOpening();
        // });
        
        /* If this model always complete before HOME and POPUP, no need to send the request */
        // m_UIComCtrl.sendDataThroughSys("REQUEST_HOME_STATE", QDBusVariant(QVariant("")));
        // m_UIComCtrl.sendDataThroughSys("REQUEST_POPUP_STATE", QDBusVariant(QVariant("")));
    }

    void ConnectedServiceProvider::requestStartCall() {
        /* Update as spect 2.70 */
        WLOG_INFO(MODULE_NAME << "requestStartCall");
        if (m_connectedSrvWrap != nullptr) {
            if ( m_connectedSrvWrap->requestStartCall() ) {
                /* Request start call successful */
                WLOG_INFO(MODULE_NAME << " Request start call successful ");
                
                auto reqCallState = m_connectedSrvWrap->getCallState();

                if (reqCallState.has_value()) {
                    /* Handle when callState got value */
                    WLOG_INFO(MODULE_NAME << " Call State has value: " << _pretty(reqCallState.value()));
                    switch (reqCallState.value())
                    {
                        case srvwrp::ConnectedServiceWrapper::CallState::Voice: {
                            /* Received CallState with value of */
#if 0
                            this->requestShowPopup(POPUP_CS_25);
#endif
                            break;
                        }
                        case srvwrp::ConnectedServiceWrapper::CallState::Calling: {
                            this->requestShowPopup(POPUP_CS_12);
                            break;
                        }
                        case srvwrp::ConnectedServiceWrapper::CallState::Impossible: {
                            this->requestShowPopup(POPUP_CS_13);
                            break;
                        }
                        case srvwrp::ConnectedServiceWrapper::CallState::None: {
                            this->requestShowPopup(POPUP_CS_13);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
                else {
                    /* Outrange value or could not receive value from callState => show CS_13*/
                    WLOG_INFO(MODULE_NAME << " CallState has no value ");
                    this->requestShowPopup(POPUP_CS_13);
                }

            }
            else {
                /* Request start call failed => show popup 13*/
                WLOG_INFO(MODULE_NAME << " Request start call failed ");
                this->requestShowPopup(POPUP_CS_13);
            }
        }
    }

    void ConnectedServiceProvider::requestEndCall() {
        WLOG_INFO(MODULE_NAME << "requestEndCall");
    }

    void ConnectedServiceProvider::requestDeleteDigitalKey() {
        WLOG_INFO(MODULE_NAME << "requestDeleteDigitalKey");
        if (m_connectedSrvWrap->deleteDigitalKey()) {
            WLOG_INFO(MODULE_NAME << " Request delete digital key successful ");
        }
        else {
            WLOG_INFO(MODULE_NAME << " Request delete digital key failed ");
        }
    }

    void ConnectedServiceProvider::requestResetNetwork() {
        WLOG_INFO(MODULE_NAME << "requestResetNetwork");
        if (m_connectedSrvWrap->requestNetworkConnectionReset()) {
            WLOG_INFO(MODULE_NAME << " Request reset network connection successful ");
        }
        else {
            WLOG_INFO(MODULE_NAME << " Request reset network connection failed ");
        }
    }

    bool  ConnectedServiceProvider::requestGetDigitalKeyActiveStatus() {
        WLOG_INFO(MODULE_NAME << "requestGetDigitalKeyActiveStatus");
        auto _keySetStt = m_connectedSrvWrap->getDigitalKeyActiveStatus();
        if (STD_OPTION_HAS_VALUE(_keySetStt)) {
            return _keySetStt.value() == srvwrp::ConnectedServiceWrapper::DigitalKeyActiveStatus::Active ? true : false;
        }
        return false;
    }

    void ConnectedServiceProvider::requestSetDigitalKeySettingStatus(bool active) {
        WLOG_INFO(MODULE_NAME << "requestSetDigitalKeySettingStatus");
        m_connectedSrvWrap->setDigitalKeySettingStatus(
            active ? srvwrp::ConnectedServiceWrapper::DigitalKeySettingStatus::On
                :   srvwrp::ConnectedServiceWrapper::DigitalKeySettingStatus::Off
        );
    }
    
    bool  ConnectedServiceProvider::requestGetDigitalKeySettingStatus() {
        WLOG_INFO(MODULE_NAME << "requestGetDigitalKeySettingStatus");
        auto _keySetStt = m_connectedSrvWrap->getDigitalKeySettingStatus();
        if (STD_OPTION_HAS_VALUE(_keySetStt)) {
            return _keySetStt.value() == srvwrp::ConnectedServiceWrapper::DigitalKeySettingStatus::On ? true : false;
        }
        return false;
    }

    void ConnectedServiceProvider::requestShowPopup(const QString& popup) {
        std::unordered_map<QString, POPUPENUM::E::EVT_STATE_ID_ROOT> popupScreenTable = {
                {"CS_03", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_03}
            ,   {"CS_04", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_04}
            ,   {"CS_05", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_05}
            ,   {"CS_06", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_06}
            ,   {"CS_07", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_07}
            ,   {"CS_08", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_08}
            ,   {"CS_12", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_12}
            ,   {"CS_13", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_13}
            ,   {"CS_16", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_16}
            ,   {"CS_17", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_17}
            ,   {"CS_18", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_18}
            ,   {"CS_19", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_19}
            ,   {"CS_20", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_20}
            ,   {"CS_21", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_21}
            ,   {"CS_22", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_22}
            ,   {"CS_23", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_23}
            ,   {"CS_24", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_24}
#if 0
            ,   {"CS_25", POPUPENUM::E::EVT_STATE_ID_ROOT::EVT_TO_POPUP_CS_25}
#endif
        };

        auto foundIt = popupScreenTable.find(popup);
        if (foundIt != popupScreenTable.end()) {
            m_UIComCtrl.receiveAppToCallOut("System_Popup", foundIt->second);
        }
    }



    void ConnectedServiceProvider::connectedServiceCallbackReceived(srvwrp::ConnectedServiceWrapper::Event _event, const srvwrp::ConnectedServiceWrapper::ConnectedServiceInfo & _info) {
        WLOG_INFO(MODULE_NAME << " received _event: " << _pretty(_event));
        switch (_event)
        {
            case srvwrp::ConnectedServiceWrapper::Event::INIT: {
                WLOG_INFO(MODULE_NAME << " INIT state ");
                // Handle Init Callback
                // m_timer->start(START_OPENING_TIMER);
                break;
            }

            case srvwrp::ConnectedServiceWrapper::Event::INFO_CHANGED: {
                // Handle Info Changed Callback
                this->processInformationChanged(_info.infoList);
                break;
            }
            
            case srvwrp::ConnectedServiceWrapper::Event::CONNECTED_CHANGED: {
                // Handle Connected Changed Callback
                /* This would send */
                emit onConnectedChanged(
                    _info.teleContractFlag == srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::On,
                    _info.connectedSetupFlag == srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::On
                );
                break;
            }

            case srvwrp::ConnectedServiceWrapper::Event::NETWORK_RESET_RESULT: {
                /* Process of handling when receiving the network result */
                this->processNetworkResetResultCallback(_info.networkConnResetResult);
                break;
            }

            case srvwrp::ConnectedServiceWrapper::Event::DCM_WAVE_STATUS: {
                /* Received DCM Wave status -> notify to all process */
                std::optional<srvwrp::ConnectedServiceWrapper::DcmWaveStatus> dcmWaveStatus = _info.dcmWaveStatus;
                emit onDCMWaveStatusChanged(static_cast<int>(dcmWaveStatus.value()));
                break;
            }

            case srvwrp::ConnectedServiceWrapper::Event::DIGITAL_KEY_ACTIVE_STATUS: {
                /* Received digital key active status -> notify to all process */
                std::optional<srvwrp::ConnectedServiceWrapper::DigitalKeyActiveStatus> digitalKeyActiveStatus = _info.digitalKeyActiveStatus;
                if (STD_OPTION_HAS_VALUE(digitalKeyActiveStatus)) {
                    emit onDigitalKeyActiveStatusChanged(digitalKeyActiveStatus.value() == srvwrp::ConnectedServiceWrapper::DigitalKeyActiveStatus::Active);
                }
                break;
            }

            case srvwrp::ConnectedServiceWrapper::Event::DIGITAL_KEY_SETTING_CHANGE_RESULT: {
                /* Received digital key setting change result -> notify to all process */
                emit onDigitalKeyResponseResult(static_cast<int>(_info.digitalKeySettingChangeResult));
            }

            case srvwrp::ConnectedServiceWrapper::Event::DIGITAL_KEY_SETTING_STATUS: {
                std::optional<srvwrp::ConnectedServiceWrapper::DigitalKeySettingStatus> digitalKeySettingStatus = _info.digitalKeySettingStatus;
                if (STD_OPTION_HAS_VALUE(digitalKeySettingStatus)) {
                    emit onDigitalKeySettingStatusChanged(digitalKeySettingStatus.value() == srvwrp::ConnectedServiceWrapper::DigitalKeySettingStatus::On);
                }
                break;
            }

            default: {
                break;
            }
        }
    }
    
    void ConnectedServiceProvider::requestStartOpening() {
        WLOG_INFO(MODULE_NAME << " request to start opening ");
#if 0
        if (m_connectedSrvWrap->isReady()) {
#endif
            // if (m_sttHolder.m_isPopupReady && m_sttHolder.m_isHomeAppReady) {
                m_curPopup = m_displayScreen.begin();
                this->processPreStartOpening();
            // }
            // else {
                // m_timer->start(START_OPENING_TIMER);
            // }
#if 0
        }
#endif
    }

    void ConnectedServiceProvider::processPreStartOpening() {
        if (m_sttHolder.m_isPreStartOpeningCompleted) {
            WLOG_INFO(MODULE_NAME << " Already completed pre-start opening");
            return;
        }
        WLOG_INFO(MODULE_NAME << " Handle Pre Start Opening ");

        auto infor = m_connectedSrvWrap->getInfo();
        auto _teleFlag = infor.teleContractFlag;
        auto _conSetFlag = infor.connectedSetupFlag;
        WLOG_INFO(MODULE_NAME << " getTelematicsServiceState: " << _pretty(_teleFlag));
        WLOG_INFO(MODULE_NAME << " getConnectedServiceSettingState: " << _pretty(_conSetFlag));
        WLOG_INFO(MODULE_NAME << " getHighDrivingRestrictionState: " << m_sttHolder.m_isHighDrvResState);
        if (_teleFlag != srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::On) { 
            if (m_sttHolder.m_isHighDrvResState) {
                WLOG_INFO(MODULE_NAME << " Request Show Popup CS 19 ");
                this->requestShowPopup(POPUP_CS_19);
            }
            else {
                WLOG_INFO(MODULE_NAME << " Request Show Popup CS 18 ");
                this->requestShowPopup(POPUP_CS_18);
            }
        }
        else {
            if (_conSetFlag == srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::On) {
                if (m_sttHolder.m_isHighDrvResState) {
                    WLOG_INFO(MODULE_NAME << " Request Show Popup CS 21 ");
                    this->requestShowPopup(POPUP_CS_21);
                }
                else {
                    WLOG_INFO(MODULE_NAME << " Request Show Popup CS 20 ");
                    this->requestShowPopup(POPUP_CS_20);
                }
            } 
            else {
                if (m_sttHolder.m_isHighDrvResState) {
                    WLOG_INFO(MODULE_NAME << " Request Show Popup CS 23 ");
                    this->requestShowPopup(POPUP_CS_23);
                }
                else {
                    WLOG_INFO(MODULE_NAME << " Request Show Popup CS 22 ");
                    this->requestShowPopup(POPUP_CS_22);
                }
            }
        }

// #ifdef BUILD_BOARD
    for (auto itr = m_displayScreen.begin();
        itr != m_displayScreen.end();
        ++itr) {
            WLOG_INFO(MODULE_NAME << "=> Screen: " << itr->first.toStdString() << " - isDisp: " << itr->second.isDisplay);
        }
// #endif

    }
    
    void ConnectedServiceProvider::processStartOpening() {
        /* If we already completed opening, we need to prevent it if someone try to start again */
        if (!m_sttHolder.m_isPreStartOpeningCompleted) {
            WLOG_INFO(MODULE_NAME << " We need to complete pre-start opening first! ");
            return;
        }

        if (m_sttHolder.m_isStartOpeningCompleted) {
            WLOG_INFO(MODULE_NAME << " Already completed start opening");
            return;
        }

        WLOG_INFO(MODULE_NAME << " Handle Start Opening ");

        do {
            /* When traveling to the last element of popup, break the process */
            if (m_curPopup == m_displayScreen.end()) {
                m_curPopup = m_displayScreen.begin();
                m_sttHolder.m_isStartOpeningCompleted = true;
                break;
            }
#if 0
            /* Checking again whether needed of this */
            if (m_isDriving && isInRangeDriving(m_curPopup->first)) {
            }
#endif

            if (m_curPopup->second.isDisplay == true) {
                /* Request show current popup to System popup */
                requestShowPopup(m_curPopup->first);
                    
                /* Turn of the isDisplay status */
                m_curPopup->second.isDisplay = false;
            
                // The flag for prevent continuos opening 
                m_sttHolder.m_isCanOpenScreen = false;
            }

            /* Move to the next popup */
            m_curPopup++;
        } while (m_sttHolder.m_isCanOpenScreen);
    }

    void ConnectedServiceProvider::processNetworkResetResultCallback(const srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult &result) {
        // IDSDEV-27534 Update spect 2.70
        WLOG_INFO(MODULE_NAME << " processNetworkResetResultCallback ");

        /* Process of handling */
        switch (result) {
            /* When receive Success: $1 => show Popup 17 */
            case srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Success: {
                requestShowPopup(POPUP_CS_16);
                break;
            }
            /* When receive Reseting: $3 => The text on  */
            case srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Resetting: {
                // Receive $3 => This text would open
                m_UIComCtrl.sendDataThroughSys("RequestShowResettingText", QDBusVariant(QVariant(true)));
                break;
            }
            /* When receive Failure: $2 => show Popup 17 */
            case srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult::Failure: {
                requestShowPopup(POPUP_CS_17);
                break;
            }
            default: {
                break;
            }
        }
        /* Notify to all process that network result was changed */
        emit onNetworkResultChanged(static_cast<int>(result));
    }

    void ConnectedServiceProvider::processInformationChanged(const std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation>& serviceList) {
        /* Process of handling the receiving connected service information changed */
        WLOG_INFO(MODULE_NAME << "ProcessInformationChanged with size: " << serviceList.size());

        m_infoList.clear();
        QList<QString> m_tempInfoList;
        auto szkTrouble = m_variantService->getSzkTroubleSupportAvailability();

        for (auto msg : serviceList) {
            WLOG_INFO(MODULE_NAME << " msg_kind: " << static_cast<int>(msg.kind) << ", msg_remind: " << static_cast<int>(msg.reminder));
            QString temp = "";
            switch (msg.kind)
            {
                case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Recall: {
                    temp = POPUP_CS_03;
                    m_displayScreen[POPUP_CS_03].isDisplay = true;
                    if (msg.reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) this->m_displayScreen[POPUP_CS_03].isReminder = true;
                    break;
                }

                case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::VehicleInspection: {
                    temp = POPUP_CS_04;
                    m_displayScreen[POPUP_CS_04].isDisplay = true;
                    if (msg.reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) this->m_displayScreen[POPUP_CS_04].isReminder = true;
                    break;
                }

                case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::PeriodicInspection: {
                    temp = POPUP_CS_05;
                    m_displayScreen[POPUP_CS_05].isDisplay = true;
                    if (msg.reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) this->m_displayScreen[POPUP_CS_05].isReminder = true;
                    break;
                }

                case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Inspection: {
                    temp = POPUP_CS_06;
                    m_displayScreen[POPUP_CS_06].isDisplay = true;
                    if (msg.reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) this->m_displayScreen[POPUP_CS_06].isReminder = true;
                    break;
                }

                case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Failure: {    // CS_07 || CS_08 
                    if (szkTrouble == SzkTroubleSupport::Supported) {
                        temp = POPUP_CS_07;
                        m_displayScreen[POPUP_CS_07].isDisplay = true;
                        if (msg.reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) this->m_displayScreen[POPUP_CS_07].isReminder = true;
                    }
                    else{
                        temp = POPUP_CS_08;
                        m_displayScreen[POPUP_CS_08].isDisplay = true;
                        if (msg.reminder == srvwrp::ConnectedServiceWrapper::ReNotificationFlag::Necessary) this->m_displayScreen[POPUP_CS_08].isReminder = true;
                    }
                    break;
                }
                default: { break; }
            }

            if (m_infoList.size() < 6) {
                /* Checking duplicate in saved list */
                bool isDuplicate = false;
                for (auto _msg : m_infoList) {
                    if (isSameCSMesage(msg, _msg.CSInfor)) {
                        isDuplicate = true;
                    }
                }

                /* When message is not duplicated */
                if (!isDuplicate) {
                    /* Pushing the message into saved list */
                    CSInformationWrapper _inf = {
                        .screenName = temp,
                        .CSInfor = msg
                    };

                    m_infoList.push_back(_inf);

                    /* Handle to push message into saved list */
                    int yearTmp = static_cast<int>(msg.year);
                    int monthTmp = static_cast<int>(msg.month);
                    int dayTmp = static_cast<int>(msg.day);
#ifdef BUILD_BOARD
                    QDate date(yearTmp + 2000, (monthTmp <= 0) ? 1 : monthTmp, (dayTmp <= 0) ? 1 : dayTmp);
#else
                    QDate date(yearTmp, (monthTmp <= 0) ? 1 : monthTmp, (dayTmp <= 0) ? 1 : dayTmp);
#endif
                    int yearsDifference = date.daysTo(QDate::currentDate());

                    /* Checking whether the message has time less than 2 years */
                    if( (std::abs(yearsDifference) / 365) < 2 ) {
                        QString item_ = QString(date.toString("yyyy/MM/dd"))
                            .append("#").append(QString::number(static_cast<int>(msg.kind)))
                            .append("#").append(QString::number(static_cast<int>(msg.index)))
                            .append("#").append(temp)
                            .append("#").append(QString::number(m_displayScreen[temp].isReminder))
                            .append("#").append(QString::number(m_displayScreen[temp].isDisplay));

                        
                        WLOG_INFO(MODULE_NAME << " insert message: " << item_.toStdString());
                        m_tempInfoList.push_back(item_);
                    }
                }
                else {
                    WLOG_INFO(MODULE_NAME << " duplicated messages! ");
                }
            }
        }

        m_UIComCtrl.sendDataThroughSys("DataCSList", QDBusVariant(QVariant(m_tempInfoList)));
    }

    bool ConnectedServiceProvider::isSameCSMesage(const srvwrp::ConnectedServiceWrapper::ConnectedInformation& lhs, const srvwrp::ConnectedServiceWrapper::ConnectedInformation& rhs) {
        if ( lhs.kind == rhs.kind
        && lhs.year == rhs.year 
        && lhs.month == rhs.month 
        && lhs.day == rhs.day) {
            return true;
        }
        return false;
    }

    void ConnectedServiceProvider::drivingCallback(const srvwrp::VehicleServiceInfo &info) {
        bool isJapan = info.getIsJapanDestination();
        // Fix klocwork START
        double speedKmh = static_cast<double>(info.getSpeedKmh());
        if(((speedKmh > static_cast<double>(5)) || (fabs(speedKmh - static_cast<double>(5)) < 1e-6)) && (isJapan == true)){
        // Fix klocwork END
            m_sttHolder.m_isDriving = true;
        }
        // Fix klocwork START
        else if((speedKmh < static_cast<double>(3)) && (isJapan == true)){
        // Fix klocwork END
            m_sttHolder.m_isDriving = false;
        }else{
            //
        }
    }
};