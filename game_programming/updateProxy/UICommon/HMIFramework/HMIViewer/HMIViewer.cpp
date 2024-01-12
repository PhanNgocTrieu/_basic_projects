#include "HMIViewer.h"
#include <QtAppManCommon/logging.h>
#include <private/qquickwindow_p.h>
#include <private/qsgrenderloop_p.h>

namespace uicommon
{
    QQmlEngine* HMIViewer::mQmlEngine   = NULL;
    bool        HMIViewer::mRegister    = false;
    QHash<uint32_t, HMIViewer*>                 HMIViewer::mViewRegisted;
    QHash<uint32_t, const APPLICATION_STATE*>      HMIViewer::mStateRegisted;
    QHash<uint32_t, QHash<uint32_t, STATE_TRIGGER> >  HMIViewer::mPoolEvt;


    HMIViewer::HMIViewer(uint32_t scr) : mViewer(NULL), mContext(NULL), mScreen(scr), mScreenMng(NULL), mRootState(0)
    {
        QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    }

    HMIViewer *HMIViewer::getInstance()
    {
        static HMIViewer instance(static_cast<uchar>(VIEWER_INDEX::VIEWER_1ST));
        return &instance;
    }

    HMIViewer::~HMIViewer()
    {
        safeDelete(mViewer);
        safeDelete(mContext);
        safeDelete(mScreenMng);
    }


    QQmlEngine *uicommon::HMIViewer::qmlEngine()
    {
        return mQmlEngine;
    }

    void uicommon::HMIViewer::initialized()
    {
        if(NULL == mQmlEngine)
        {
            mQmlEngine = new QQmlEngine();
        }

        mContext = mQmlEngine->rootContext();

        mContextProperties.clear();

        (void)this->registerContextProperty("HMI_VIEWER_INDEX", QVariant::fromValue(mScreen));

        (void)this->registerContextProperty("HMI_SCREEN_WIDTH", 0);

        (void)this->registerContextProperty("HMIScreen", QVariant::fromValue(nullptr));

        (void)this->registerContextProperty("HMI_SCREEEN_HEIGHT", 0);

        (void)this->registerContextProperty("QMLHandle", QVariant::fromValue(this));

        (void)this->registerContextProperty("HMI_SCREEEN_MAXSIZE", false);

        (void)this->registerContextProperty("IS_FULLSIZE_APPLICATION", false);

        (void)this->registerContextProperty("IS_SYSTEM_POPUP", false);
        
        (void)this->setViewerSize(MAIN_SCREEN_WIDTH, MAIN_SCREEN_HEIGH);

        QQmlComponent *mainViewComponent = new QQmlComponent(mQmlEngine, QUrl(QStringLiteral(MAIN_VIEWPORT_QML)));

        mViewer = qobject_cast<QQuickWindow*>(mainViewComponent->create(mContext));

        delete mainViewComponent;

        QQuickWindowPrivate* wpriv = QQuickWindowPrivate::get(mViewer);

        if (wpriv != nullptr && wpriv->windowManager != nullptr) 
        {
            qWarning()<<"RenderLoop class name " << wpriv->windowManager->metaObject()->className();
        }
        else
        {
            qWarning()<<"Render Loop Null";
        }

        /* Connect with window to get this application is visible or not */
        QObject::connect(mViewer, &QQuickWindow::visibleChanged, this, &uicommon::HMIViewer::visibleChanged);
    }
    void uicommon::HMIViewer::initAllComponents(){
        for (int i = 0; i < mStateRegisted.keys().count(); ++i) {
            mScreenMng->createComponent(mStateRegisted[mStateRegisted.keys().at(i)]->QmlPath);
        }
    }

    QQuickItem* HMIViewer::getContentItem() const
    {
        return mViewer->contentItem();
    }

    void HMIViewer::completed()
    {
        mScreenMng = new uicommon::ScreenManager(mViewer, mContext, mScreen);
        mViewRegisted[mScreen] = this;

        for (int i = 0; i < mStateRegisted.keys().count(); i++) {
            if(LAYER::LAYER_BASE == mStateRegisted[mStateRegisted.keys().at(i)]->layerbase){
                mRootState = mStateRegisted[mStateRegisted.keys().at(i)]->id;
                break;
            }
        }

        QObject::connect(mViewer, &QQuickWindow::visibilityChanged, this, [this](QQuickWindow::Visibility visibility)
        {
            qWarning()<<"Visiblility Changed " << (int)visibility;
        });


    }

    bool uicommon::HMIViewer::registerContextProperty(const QString &str, const QVariant &var)
    {
        //Fix klocwork START
        bool isRegContext = false;
        if(true == mContextProperties.contains(str)){
            qDebug() << __FUNCTION__ << __LINE__ << "Property " << str << "Already existed";
        }else{
            mContextProperties.append(str);
            mContext->setContextProperty(str, var);
            isRegContext = true;
        }
        return isRegContext;
        //Fix klocwork END
    }

    QList<QString> uicommon::HMIViewer::contextPropertiesRegisted() const
    {
        return mContextProperties;
    }
    bool uicommon::HMIViewer::updateContextProperty(const QString &str, const QVariant &var)
    {
        bool ret = false;
        if(mContextProperties.contains(str) && (NULL != mContext))
        {
            mContext->setContextProperty(str, var);
            ret = true;
        }
        else{
            qWarning() << __FUNCTION__ << __LINE__ << "The property" << str << "Did not initial, it should be register with registerContextProperty() before call completed()";
        }
        return ret;
    }

    void uicommon::HMIViewer::sendEvent(uint32_t eventID, QVariant msg)
    {
        // bool isExisted = false;
        mCurrentEvent = eventID;
        if(NULL != mScreenMng){
            uint32_t scr = mScreenMng->getCurrentScreen();
            qWarning()<<"SendEvent In Screen " << eventID;
            if(mPoolEvt[scr].contains(eventID)){

                if(NULL != mPoolEvt[scr][eventID].trans){
                    handleTransition(mStateRegisted[scr], mPoolEvt[scr][eventID].trans, msg);
                }
                else
                {
                    qWarning()<<"is Null";
                }
            }
            else
            {
                qWarning()<<"Not COntains";
            }
            // isExisted = true;
        }
        // if ( isExisted == false)
        // {
            // CHECK IN ROOT
            qWarning()<<"SendEvent In Root " << eventID;
            if(mPoolEvt[mRootState].contains(eventID)){
                if(nullptr != mPoolEvt[mRootState][eventID].trans){
                    handleTransition(mStateRegisted[mRootState], mPoolEvt[mRootState][eventID].trans, msg);
                }
            }
        // }
    }


    bool uicommon::HMIViewer::setViewerSize(int width, int height)
    {
        bool ret = false;
        ret &= this->updateContextProperty("HMI_SCREEN_WIDTH", width);
        ret &= this->updateContextProperty("HMI_SCREEEN_HEIGHT", height);
        bool isMaxSize = false;
        if ((width == 1280) && (height == 720)) isMaxSize = true;
        ret &=this->updateContextProperty("HMI_SCREEEN_MAXSIZE", isMaxSize);
        return ret;
    }

    void HMIViewer::show()
    {
        if (mViewer != nullptr)
        {
            mViewer->show();
        }
    }

    void HMIViewer::hide()
    {
        if (mViewer != nullptr)
        {
            mViewer->hide();
        }
    }

    void HMIViewer::destroyWindowResource()
    {
        if (mViewer != nullptr)
        {
            mViewer->destroy();
        }
    }

    void HMIViewer::closeSession()
    {
        if (mViewer != nullptr)
        {
            mViewer->close();
        }
    }

    QQmlContext *uicommon::HMIViewer::getQmlContext()
    {
        return mContext;
    }

    QQuickWindow *HMIViewer::getViewer()
    {
        return mViewer;
    }

    QList<uint32_t> uicommon::HMIViewer::getCurrentStates() const
    {
        QList<uint32_t> list ;
        if(NULL != mScreenMng){
            list.append(mScreenMng->getCurrentScreen());
        }
        return list;
    }

    void uicommon::HMIViewer::registerStates(const STATE_SYSTEM tbl[], uint len)
    {
        if(false == mRegister){
            if(!mPoolEvt.isEmpty()){
                mPoolEvt.clear();
            }

            if(!mStateRegisted.isEmpty()){
                mStateRegisted.clear();
            }

            // Looking for all child
            for (uint i = 0; i < len; i++) {
                mStateRegisted[tbl[i].id] = tbl[i].state;
                for (uint j = 0; j < tbl[i].size; j++) {
                    mPoolEvt[tbl[i].id][tbl[i].trigger[j].evt] = tbl[i].trigger[j];
                }
            }

            mRegister = true;
            qDebug() << __FUNCTION__ << __LINE__ << "THERE ARE " << mStateRegisted.count() << "STATES REGISTED";
        }
    }


    void uicommon::HMIViewer::handleTransition(const APPLICATION_STATE *from, const APPLICATION_STATE *to, QVariant msg)
    {
        qWarning()<<"Handle Transition";
        if(((NULL != from) && (NULL != to))){

            if(LAYER::LAYER_SCREEN == to->layerbase)
            {
                if((NULL != mScreenMng) && (to->id == mScreenMng->getCurrentScreen()) && (LAYER::LAYER_BASE != from->layerbase) && (LAYER::LAYER_SCREEN != from->layerbase)){

                }
                else
                {
                    (void)this->showScreen(to->id, msg);
                }
            }
            else{/*No handle*/}
        }
    }

    bool uicommon::HMIViewer::showScreen(uint32_t tempId, QVariant msg)
    {
        bool ret = false;
        if((NULL != mScreenMng) && mStateRegisted.contains(tempId)){
            if(LAYER::LAYER_SCREEN == mStateRegisted[tempId]->layerbase){
                mCurrentScreenPath = mStateRegisted[tempId]->QmlPath;
                ret = mScreenMng->showScreen(mStateRegisted[tempId], msg);
            }
        }
        return ret;
    }


    void uicommon::HMIViewer::collectGarbage()
    {
        if(NULL != mQmlEngine){
            mQmlEngine->collectGarbage();
        }
    }

};
