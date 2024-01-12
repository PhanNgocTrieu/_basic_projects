#ifndef __CONNECTED_PROVIDER_H__
#define __CONNECTED_PROVIDER_H__
#include "../UICommunication/UICommunication.h"
#include <Proxy/CS/ConnectedServiceAgency.h>
#include <Proxy/CS/ConnectedServiceAdaptor.h>
#include <connectedservicewrap/connectedservicewrapper.h>
#include <vehiclefuncwrap/vehicleservicewrapper.h>
#include <aisinsdkwrap/aisinsdkwrapper.h>
#include <common/Logger.h>
#include <PopupViewsEnums.h>
#include <HMIHeaderServiceProxy.h>
#include <vector>
#include <map>
#include <QObject>
#include <QTimer>

namespace CsApp {
    class CSEngine;
    class ConnectedServiceProvider final : public uicommon::ConnectedServiceAgency {
        WLOG_DEF

        public:
            struct ConnectedStateHolder {
                bool isDisplay{false};
                bool isReminder{false};
            };

            struct StatusManager {
                bool m_isPreStartOpeningCompleted{false};
                bool m_isStartOpeningCompleted{false};
                bool m_isCanOpenScreen{true};
                bool m_isDriving{false};
                bool m_isHighDrvResState{false};
                bool m_isPopupReady{false};
                bool m_isHomeAppReady{false};
            };

            struct CSInformationWrapper{
                QString screenName{""};
                srvwrp::ConnectedServiceWrapper::ConnectedInformation CSInfor;
            };

        public:
            static ConnectedServiceProvider* getInstance();
            void initialize();
            ~ConnectedServiceProvider();
            void completePreStartOpening();
            void popupIsReady();
            void homeIsReady();

        public slots:
            void requestStartCall() override;
            void requestEndCall() override;
            void requestDeleteDigitalKey() override;
            void requestResetNetwork() override;
            bool requestGetDigitalKeyActiveStatus() override;
            void requestSetDigitalKeySettingStatus(bool active) override;
            bool requestGetDigitalKeySettingStatus() override;

        protected:
            ConnectedServiceProvider();
            void requestShowPopup(const QString&);
            void connectedServiceCallbackReceived(srvwrp::ConnectedServiceWrapper::Event, const srvwrp::ConnectedServiceWrapper::ConnectedServiceInfo &);
            void requestStartOpening();
            void processPreStartOpening();
            void processStartOpening();
            void processNetworkResetResultCallback(const srvwrp::ConnectedServiceWrapper::NetworkConnectionResetResult &result);
            void processInformationChanged(const std::vector<srvwrp::ConnectedServiceWrapper::ConnectedInformation>& serviceList);
            void drivingCallback(const srvwrp::VehicleServiceInfo &info);
            
            // Pretty Functions
            std::string _pretty(const srvwrp::ConnectedServiceWrapper::Event& _kind);
            std::string _pretty(const srvwrp::ConnectedServiceWrapper::ConnectedInformationKind& _kind);
            std::string _pretty(const srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag& _kind);
            std::string _pretty(const srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag& _kind);
            std::string _pretty(const srvwrp::ConnectedServiceWrapper::CallState& _kind);

            bool isSameCSMesage(const srvwrp::ConnectedServiceWrapper::ConnectedInformation& lhs, const srvwrp::ConnectedServiceWrapper::ConnectedInformation& rhs);
        protected:
            srvwrp::ConnectedServiceWrapper *m_connectedSrvWrap = nullptr;
            std::vector<srvwrp::signalsrv::Connect> m_connectedSrvConnections;
            aisinlbssdk::VariantService* m_variantService = nullptr;
            srvwrp::handle_t m_variantSvID = srvwrp::invalid_handle;
            std::shared_ptr<srvwrp::VehicleServiceWrapper>  m_variantVehicleSvwrp = nullptr;
            uicommon::ConnectedServiceAdaptor* m_connectedServiceAdaptor;
            uicommon::HMIHeaderServiceProxy& headerIF;
            CsApp::UICommunication& m_UIComCtrl;
            std::map<QString, ConnectedStateHolder> m_displayScreen;
            std::map<QString, ConnectedStateHolder>::iterator m_curPopup;
            StatusManager m_sttHolder;
            CSEngine* m_engine;
            std::vector<CSInformationWrapper> m_infoList;
            QTimer* m_timer{nullptr};
    };
}

#endif /* __CONNECTED_PROVIDER_H__ */