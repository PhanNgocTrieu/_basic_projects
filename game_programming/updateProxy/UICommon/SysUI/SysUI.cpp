#include "SysUI.h"

namespace uicommon{

    QMap<QString, uicommon::SysUI::TransitionType> SysUI::g_screenStates;
}


bool isScreenRegistered(const QString& screenID)
{
    return uicommon::SysUI::g_screenStates.find(screenID) != uicommon::SysUI::g_screenStates.end();
}

bool isScreenInActiveState(const QString& screenID)
{
    return uicommon::SysUI::g_screenStates[screenID] == uicommon::SysUI::TransitionType::ShowTransition;
}

bool isScreenInInActiveState(const QString& screenID)
{
    return uicommon::SysUI::g_screenStates[screenID] == uicommon::SysUI::TransitionType::HideTransition;
}

bool isScreenInQueuedState(const QString& screenID)
{
    return uicommon::SysUI::g_screenStates[screenID] == uicommon::SysUI::TransitionType::QueueTransition;
}

void toActiveState(const QString& screenID)
{
    uicommon::SysUI::g_screenStates[screenID] = uicommon::SysUI::TransitionType::ShowTransition;
}

void toInActiveState(const QString& screenID)
{
    uicommon::SysUI::g_screenStates[screenID] = uicommon::SysUI::TransitionType::HideTransition;
}

void toQueueState(const QString& screenID)
{
    uicommon::SysUI::g_screenStates[screenID] = uicommon::SysUI::TransitionType::QueueTransition;
}

void setScreenState(const QString& screenID, const uicommon::SysUI::TransitionType& val)
{
    uicommon::SysUI::g_screenStates[screenID] = val;
}