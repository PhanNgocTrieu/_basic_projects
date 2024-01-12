#include "ConnectedProvider.h"

namespace CsApp {
    std::string ConnectedServiceProvider::_pretty(const srvwrp::ConnectedServiceWrapper::Event& _kind)
    {
        std::string ret;
        switch (_kind) {
            case srvwrp::ConnectedServiceWrapper::Event::INIT: {
                ret = "INIT";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::INFO_CHANGED: {
                ret = "INFO_CHANGED";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::NETWORK_RESET_RESULT: {
                ret = "NETWORK_RESET_RESULT";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::EMERGENCY_CALL_REPORT: {
                ret = "EMERGENCY_CALL_REPORT";
                break; 
            }
            case srvwrp::ConnectedServiceWrapper::Event::CONNECTED_CHANGED: {
                ret = "CONNECTED_CHANGED";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::WALLPAPER_DOWNLOAD_RESULT: {
                ret = "WALLPAPER_DOWNLOAD_RESULT";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::WALLPAPER_UNSAVED_DATA: {
                ret = "WALLPAPER_UNSAVED_DATA"; 
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::WALLPAPER_SAVED_DATA:{
                ret = "WALLPAPER_SAVED_DATA";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::DIGITAL_KEY_ACTIVE_STATUS:{
                ret = "DIGITAL_KEY_ACTIVE_STATUS";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::DIGITAL_KEY_SETTING_STATUS:{
                ret = "DIGITAL_KEY_SETTING_STATUS";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::DIGITAL_KEY_SETTING_CHANGE_RESULT:{
                ret = "DIGITAL_KEY_SETTING_CHANGE_RESULT";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::DCM_WAVE_STATUS:{
                ret = "DCM_WAVE_STATUS";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::Event::AUDIO_CONTROL_EVENT:{
                ret = "AUDIO_CONTROL_EVENT";
                break;
            }
        }
        return ret;
    }

    std::string ConnectedServiceProvider::_pretty(const srvwrp::ConnectedServiceWrapper::ConnectedInformationKind& _kind)
    {
        std::string ret;
        switch (_kind) {
            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Recall:
                ret = "Recall";
                break;
            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::VehicleInspection:
                ret = "VehicleInspection";
                break;
            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::PeriodicInspection:
                ret = "PeriodicInspection";
                break;
            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Inspection:
                ret = "Inspection";
                break;
            case srvwrp::ConnectedServiceWrapper::ConnectedInformationKind::Failure:
                ret = "Failure";
                break;
            default:
                ret = "Default";
                break;
        }
        return ret;
    }

    std::string ConnectedServiceProvider::_pretty(const srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag& _kind) {
        std::string ret = "UNKNOWN";
        switch (_kind) {
            case srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::On: {
                ret = "On";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::ConnectedSetupFlag::Off: {
                ret = "Off";
                break;
            }
            default: {
                break;
            }
        }
        return ret;
    }

    std::string ConnectedServiceProvider::_pretty(const srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag& _kind) {
        std::string ret = "UNKNOWN";
        switch (_kind) {
            case srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::On: {
                ret = "On";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::TelemarketingContractFlag::Off: {
                ret = "Off";
                break;
            }
            default: {
                break;
            }
        }
        return ret;
    }

    std::string ConnectedServiceProvider::_pretty(const srvwrp::ConnectedServiceWrapper::CallState& _kind) {
        std::string ret = "UNKNOWN";
        switch (_kind) {
            case srvwrp::ConnectedServiceWrapper::CallState::Voice: {
                ret = "Voice";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::CallState::Calling: {
                ret = "Calling";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::CallState::Impossible: {
                ret = "Impossible";
                break;
            }
            case srvwrp::ConnectedServiceWrapper::CallState::None: {
                ret = "None";
                break;
            }
            default: {
                break;
            }
        }
    }
};