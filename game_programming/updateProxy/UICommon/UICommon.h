#ifndef UI_COMMON_H
#define UI_COMMON_H

#include "UICommon_global.h"
#include "Proxy/HMISystem/HMISystemServiceAdaptor.h"
#include "LanguageManagement.h"
#include "UIKeyboard.h"
#include "Proxy/VehicleGeneralState/VehicleGeneralStateModel.h"
#include "Proxy/HMISystem/HMISystemServiceProxy.h"
#include "Models/TitleModel.h"
namespace uicommon {
    UICOMMON_EXPORT int initialize();
    UICOMMON_EXPORT int setup_logger(const std::string& appName, 
                                    const std::string& dltAppId,
                                    const std::string& dltCtxId,
                                    const std::string& dltDesc);
    UICOMMON_EXPORT int finialize();
}

#endif