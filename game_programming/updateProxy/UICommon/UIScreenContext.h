#ifndef UICOMMON_UISCREEN_CONTEXT
#define UICOMMON_UISCREEN_CONTEXT

#include <QObject>
#include <QVariant>
#include <deque>
#include <common/Logger.h>
#include <SysUI/SysUIInterface.h>

namespace uicommon 
{
    enum ScreenContext
    {
        ScreenContextHide,
        ScreenContextFull,
        ScreenContext13_Left, 
        ScreenContext13_Middle,
        ScreenContext13_Right,
        ScreenContext23_Left,
        ScreenContext23_Right,
        ScreenContextMax
    };
    class UIScreenContext : public QObject 
    {
        Q_OBJECT
        WLOG_DEF
        Q_PROPERTY(bool isDeterminedSize READ isDeterminedSize NOTIFY determinedSizeChanged)
        Q_PROPERTY(bool isScreen13 READ isScreen13 NOTIFY screenSizeChanged)
        Q_PROPERTY(bool isScreen23 READ isScreen23 NOTIFY screenSizeChanged)
        Q_PROPERTY(bool isScreenFull READ isScreenFull NOTIFY screenSizeChanged)
        Q_PROPERTY(QString lastScreenPath READ lastScreenPath NOTIFY screenSizeChanged)

    public:
        explicit UIScreenContext(const QString& appName, QObject* parent = nullptr);
        QString notifyScreenChanged(const QString& screenPath);
        void setSysIF( hmi::service::sysifapps * sysIF);
        bool isDeterminedSize() const;
        bool isScreen13() const;
        bool isScreen23() const;
        bool isScreenFull() const;
        QString lastScreenPath() const;
        uicommon::ScreenContext getCurrentContext() const;

        Q_INVOKABLE bool isSizeMatch(float width, float height);
        Q_INVOKABLE void notifyHide(QString& screenPath);
        Q_INVOKABLE void notifyShow(QString& screenPath);
    signals:
        void determinedSizeChanged();
        void screenSizeChanged();
        void screenContextChanged(uicommon::ScreenContext from, uicommon::ScreenContext to);
    private:
        bool                    m_IsDeterminedSize = false;
        bool                    m_IsFullScreen  = false;    //true if in fullScreen mode
        bool                    m_IsScreen23    = false;    //true if in 2/3 - 1/3 mode
        QString                 m_Screen23; 
        QString                 m_FullScreen;
        std::deque<QString>     m_Screen13Queue;
        QString                 m_AppID;
        QString                 m_LastScreenPath;
        int                     m_ScreenWidth;
        int                     m_ScreenHeight;
        bool                    m_IsChanging = true;
        hmi::service::sysifapps *m_SysIF {nullptr};
        uicommon::ScreenContext m_ScreenContext = uicommon::ScreenContext::ScreenContextHide;
    };
}

#endif //UICOMMON_UISCREEN_CONTEXT