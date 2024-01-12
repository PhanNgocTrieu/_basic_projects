#ifndef UICOMMUNCATION_H
#define UICOMMUNCATION_H

#include <QObject>
#include <SysUI/SysUIInterface.h>
#include <HMIViewer.h>
#include <SettingViewsEnums.h>
#include <functional>
#include <Proxy/Navigation/NavigationServiceProxy.h>
//Klocwork-Fix rule MISRA.NS.GLOBAL-START
namespace CsApp {
class UICommunication: public QObject{
    Q_OBJECT
    public:
        //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-START
        static void initializedView();
        //Klocwork-Fix rule MISRA.MEMB.NON_STATIC-END
        void registerProcessScreen(std::function<void(uint32_t)>);
        void registerContextProperty(QString, QVariant);
        QString getCurrentScreenPath() {return std::move(mViewer->getCurrentScreenPath());}
        void showApp();
        void retranslate();
        QString currentApplication() const { return m_SysIF->currentApplication();}
        void setCurrentScreenPath(const QString& path);
        void callOutToExpand(const QString& application, const QString& screenId = "", uicommon::SysUI::TransitionType transitionType = uicommon::SysUI::TransitionType::ShowTransition);
        void callToShowInternalPopup(const bool& expand);
        void enableMultitouchSettingScreen(const bool &isEnable);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        UICommunication(QObject* _parent = nullptr);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        UICommunication(const UICommunication&) = delete;
        UICommunication& operator=(const UICommunication&) = delete;
        void disableOperationWhileDriving();
        /**
         * @brief To send request through the system to synchronise 
         *        data or to update the properties
         * 
         * @param The unique request Id
         * @param Variant value
         */
        void sendDataThroughSys(const QString&, const QDBusVariant&);

        void setDefaultLayout(const QVariantList &newDefaultLayout);

        void setappIdTiel(const QString &newAppIdTiel);
        //Klocwork-Fix rule MISRA.EXPR.COND.NOT_BOOLEAN, MISRA.MEMB.NON_CONST-START
        QQmlEngine* getQMLEngine()  {return (mViewer!=nullptr) ? mViewer->qmlEngine():       nullptr;}
        uint16_t   getCurrentEvent() const {return (mViewer!=nullptr) ? mViewer->getCurrentEvent(): 0;}
        QQuickWindow *getViewer()    {return (mViewer!=nullptr) ? mViewer->getViewer(): nullptr;}
        //Klocwork-Fix rule MISRA.EXPR.COND.NOT_BOOLEAN, MISRA.MEMB.NON_CONST-END

        void setViewerSize(int width, int height);

        void registerAllComponents();
        void changeDisplayOnOff();
        void manualDriverRecord();
        void manualDriverPicture();
        //Klocwork-Fix rule MISRA.MEMB.NON_CONST-START
        QString getCurrentPopupPath() const {return m_SysIF->currentPopupPath();}
        //Klocwork-Fix rule MISRA.MEMB.NON_CONST-START

    public:
        static UICommunication& getInstance();
        ~UICommunication();
        /**
         * @brief This function is used to request the application to switch to full size
         *
         * @param Indicate that the current application is full size or not
         */
        void requestFullScreen(const bool &isFullSize);
        void setDefaultApps(const QVariantList &newDefaultApps);
        void setDefaultBarApps(const QVariantList &newDefaultBarApps);
        void setlayoutType(int newLayoutType);
        void backToHomeScreen();
        void receiveAppToCallOut(const QString &appID, const int &screenID);
        void getFavoriteFromApps(const QString& appId,const int& eventId);
        

        void resizeWindowItem(const QString& SURFACE_ID, const int& width, const int& height);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void rePositionWindowItem(const QString& SURFACE_ID, const int& _x, const int& _y);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        void backToPreviousScreen();
        bool checkCurrentScreen(const QString& screenpath);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void notifySettingChanged(const QString& _str);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        bool getCallOtherScreen() const {return m_callOtherScreens;}
        void requestToHome();
        void setCallOtherScreen(bool status){
            m_callOtherScreens = status;
        };
    public slots:
        //Klocwork-Fix rule MISRA.MEMB.NON_CONST, MISRA.VAR.HIDDEN-START
        void sendEvent(uint32_t eventID, QVariant _msg = QVariant()) const;
        //Klocwork-Fix rule MISRA.MEMB.NON_CONST, MISRA.VAR.HIDDEN-END
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void changeScreen(uint32_t eventID, QVariant _msg = QVariant());
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        void callASpecificScreen(const QString &appID, const int &screenNums);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void requestShowSurface(const QString& app, const int& width, const int& height, const int& _x, const int& _y);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        void requestHideSurface(const QString &app);
    signals:
        void currentApplicationChanged();
        void signallingDataThroughSys(const QString &pro, const QDBusVariant &var);
        void signalErrorCodeForTest(QString appID, QString error);

        void signalGetSettingTielType();
        void signalSettingAppIdTile(QString appIdTiel);
        void signalGetSettingTileAppId();
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void writeNewSettingInfo(QString _first,QString second, QString third);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void writeNewDefaultBarApps(QString _first,QString second, QString third,QString fourth, QString fifth);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        void callScreensOfAGivenApp(const QString &appID, const int &screenNums);
        void signalChangeScreenSize(const QString Appid);
        void backToHome(const QString& previousScreen = "UNDEFINED");
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void notifyReplyResultPopup(const QString &title, QDBusVariant _data);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        void signallingDataThroughApp(const QString&, const QDBusVariant& var);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void propagatePosition(qreal _x,qreal _y, QString tempId, bool doubleClick,bool onlyAcceptRelease);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void keyEvent(uint16_t _key, int tempEvent);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void updateAppData(QString _first,QString second,QString third,QString fourth,QString fifth,QString first_id,QString second_id,QString third_id);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-START
        void transitionStateTrigger(uicommon::SysUI::TransitionType _type, const QString& app, const QString& eventID);
        //Klocwork-Fix rule MISRA.VAR.HIDDEN-END

        /**
         * @brief This signal tells when the screen is created or destroyed
         * @param bool isCreated:   (true) the screen is created
         *                          (false) the screen "may be" destroyed
         * @return none.
        */
        void onCurrentSettingScreenChanged(const QString& screenPath, bool isCreated);
    private:
        uicommon::HMIViewer* mViewer              = nullptr;
        hmi::service::sysifapps *m_SysIF          = nullptr;
        std::function<void(uint32_t)> onSendEvent;
        NavigationServiceProxy *m_naviProxy;
        bool                                      m_callOtherScreens = false;
};
}
//Klocwork-Fix rule MISRA.NS.GLOBAL-END
#endif
