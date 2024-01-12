#include <cmath>
#include "UIScreenContext.h"

namespace uicommon
{
    UIScreenContext::UIScreenContext(const QString& appName, QObject* parent) 
    : QObject{parent},
    m_AppID(appName),
    // START - Fix klocwork UNINIT.CTOR.MUST
    m_Screen13Queue(),
    m_ScreenWidth(0),
    m_ScreenHeight(0)
    // END - Fix klocwork UNINIT.CTOR.MUST
    {

    }
    void UIScreenContext::setSysIF( hmi::service::sysifapps * sysIF)
    {
        m_SysIF = sysIF;
    }
    QString UIScreenContext::lastScreenPath() const
    {
        return m_LastScreenPath;
    }
    QString UIScreenContext::notifyScreenChanged(const QString& screenPath)
    {
        QString shouldChange = "";
        bool isContainApp = screenPath.contains(m_AppID);

        // if(screenPath == m_LastScreenPath)
        // {
        //     if(isContainApp && !m_IsDeterminedSize)
        //     {
        //         m_IsDeterminedSize = true;
        //         emit determinedSizeChanged();
        //     }
        //     return shouldChange;
        // }

        m_LastScreenPath = screenPath;
        uicommon::ScreenContext screenContext = uicommon::ScreenContext::ScreenContextHide;

        if(true == screenPath.contains("_13") )
        {
            while( (( m_IsScreen23 && (m_Screen13Queue.size() >= 1)  ) || (  m_Screen13Queue.size() > 2  )) )
            {
                m_Screen13Queue.pop_front();
            }

            m_Screen13Queue.push_back(screenPath);
            if(isContainApp)
            {
                if(m_Screen13Queue.size() == 1)
                {
                    screenContext = uicommon::ScreenContext::ScreenContext13_Left;
                }
                else if (m_Screen13Queue.size() == 2)
                {
                    screenContext = uicommon::ScreenContext::ScreenContext13_Middle;
                }
                else if (m_Screen13Queue.size() == 3)
                {
                    screenContext = uicommon::ScreenContext::ScreenContext13_Right;
                }
            }
        }
        else if (true == screenPath.contains("_23"))
        {
            while( m_Screen13Queue.size() > 1 )
            {
                m_Screen13Queue.pop_front();
            }
            m_IsScreen23 = true;
            m_IsFullScreen = false;
            m_Screen23 = screenPath;
            if(isContainApp)
            {
                if (m_Screen13Queue.size() == 0)
                    screenContext = uicommon::ScreenContext::ScreenContext23_Left;
                else 
                    screenContext = uicommon::ScreenContext::ScreenContext23_Right;
            }
        }
        else
        {
            m_FullScreen = screenPath;
            m_IsFullScreen = true;
            m_IsScreen23 = false;
            m_Screen13Queue.clear();
        }
        

        bool isReset = (m_Screen13Queue.size() == 3 || (m_Screen13Queue.size() == 1 && m_IsScreen23 == true) || m_IsFullScreen);
        if(m_IsFullScreen) {
            if (screenPath == m_AppID) {
                screenContext = uicommon::ScreenContext::ScreenContextFull;
            }
        } 
        else if (m_IsScreen23) 
        {
            if (m_Screen23.contains(m_AppID))
            {
                if (m_Screen13Queue.size() == 0)
                    screenContext = uicommon::ScreenContext::ScreenContext23_Left;
                else if (m_Screen13Queue.size() == 1)
                    screenContext = uicommon::ScreenContext::ScreenContext23_Right;
                else {

                }
            }
            else if(m_Screen13Queue.size() > 0) 
            {
                if(m_Screen13Queue[m_Screen13Queue.size() - 1].contains(m_AppID))
                {
                    screenContext = uicommon::ScreenContext::ScreenContext13_Left;
                    //TODO: improve
                }
            }
        }
        else 
        {
            
            for (size_t i = 0; i < m_Screen13Queue.size(); i++)
            {
                if(m_Screen13Queue[i].contains(m_AppID))
                {
                    switch(i){
                        case 0: 
                            screenContext = uicommon::ScreenContext::ScreenContext13_Left;
                            break;
                        case 1:
                            screenContext = uicommon::ScreenContext::ScreenContext13_Middle;
                            break;
                        case 2:
                            screenContext = uicommon::ScreenContext::ScreenContext13_Right;
                            break;
                        default:
                            screenContext = uicommon::ScreenContext::ScreenContext13_Left;
                            break;
                    }
                    break;
                }
            }
        }
        if(isReset || screenContext != uicommon::ScreenContext::ScreenContextHide)
        {
            bool ctxChanged = m_ScreenContext != screenContext;
            uicommon::ScreenContext curContext = m_ScreenContext;
            m_ScreenContext = screenContext;
            if(screenContext == uicommon::ScreenContext::ScreenContextHide)
            {
                m_IsDeterminedSize = false;
                emit determinedSizeChanged();
                if(!m_IsChanging && m_SysIF != nullptr)
                {
                    for (int i = 0; i < m_SysIF->defaultApps().size(); ++i)
                    {
                        if (m_SysIF->defaultApps()[i].toString() == m_AppID)
                        {
                            if (m_SysIF->defaultLayout()[i].toBool())
                            {
                                shouldChange = m_AppID + "_23";
                            }
                            else 
                            {
                                shouldChange = m_AppID + "_13";
                            }
                        }
                    }
                }
            }
            else 
            {
                if(isScreen13())
                {
                    m_ScreenWidth = 368;
                    m_ScreenHeight = 624;
                }
                else if(isScreen23())
                {
                    m_ScreenWidth = 752;
                    m_ScreenHeight = 624;
                }
                else 
                {
                    m_ScreenWidth = 1280;
                    m_ScreenHeight = 624;
                }
                WLOG_INFO("screenSizeChanged :" << (isScreen13() ? " 1/3" : isScreen23() ? " 2/3" : " full"));
                emit screenSizeChanged();
                if(!m_IsDeterminedSize)
                {
                    m_IsDeterminedSize = true;
                    emit determinedSizeChanged();
                }
            }
            m_IsScreen23 = false;
            m_IsFullScreen = false;
            m_Screen13Queue.clear();
            if(ctxChanged)
            {
                emit screenContextChanged(curContext, m_ScreenContext);
            }
        }
        else if(isContainApp && !m_IsDeterminedSize)
        {
            m_IsDeterminedSize = true;
            emit determinedSizeChanged();
        }
        return shouldChange;
    }
        
    bool UIScreenContext::isScreen13() const
    {
        return m_ScreenContext == uicommon::ScreenContext::ScreenContext13_Left
            || m_ScreenContext == uicommon::ScreenContext::ScreenContext13_Middle
            || m_ScreenContext == uicommon::ScreenContext::ScreenContext13_Right;
    }
    bool UIScreenContext::isScreen23() const
    {
        return m_ScreenContext ==  uicommon::ScreenContext::ScreenContext23_Left
            || m_ScreenContext ==  uicommon::ScreenContext::ScreenContext23_Right;
    }
    bool UIScreenContext::isScreenFull() const
    {
        return m_ScreenContext == uicommon::ScreenContext::ScreenContextFull
            || m_ScreenContext ==  uicommon::ScreenContext::ScreenContextMax;
    }

    bool UIScreenContext::isDeterminedSize() const
    {
        return m_IsDeterminedSize;
    }

    bool UIScreenContext::isSizeMatch(float width, float height)
    {
        int tmpWidth = static_cast<int>(std::round(width));
        int tmpHeight = static_cast<int>(std::round(height));

        return (std::abs(tmpWidth - m_ScreenWidth) ) < 30;
    }

    void UIScreenContext::notifyHide(QString& screenPath)
    {
        if (m_IsDeterminedSize 
        && ((screenPath.contains("_13") && isScreen13())
            || (screenPath.contains("_23") && isScreen23())
            || (screenPath == m_AppID && isScreenFull())
        ))
        {
           m_IsChanging = true;
        }
    }
    void UIScreenContext::notifyShow(QString& screenPath)
    {
        m_IsChanging = false;
        if(!m_IsDeterminedSize) 
        {
            m_IsDeterminedSize = true;
            emit determinedSizeChanged();
        }
    }
    uicommon::ScreenContext UIScreenContext::getCurrentContext() const
    {
        return m_ScreenContext;
    }
}
