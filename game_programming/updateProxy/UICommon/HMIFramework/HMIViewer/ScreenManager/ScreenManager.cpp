#include "ScreenManager.h"

uicommon::ScreenQueue uicommon::ScreenManager::mCacheScreen;
uicommon::ScreenManager::ScreenManager(QQuickWindow* rootObject, QQmlContext* context, uint32_t scr): mRootObject(rootObject), mContext(context), mScreen(scr), mCurrentScreen(NULL)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

uicommon::ScreenManager::~ScreenManager()
{

}

bool uicommon::ScreenManager::showScreen(const APPLICATION_STATE *scr, QVariant msg)
{
    bool ret = false;
    if((NULL != mRootObject) && (NULL != scr)){
        QString path = scr->QmlPath;

        (void)mRootObject->setProperty("screenParameters",msg);

        if(!mCacheScreen.contains(path)){
            QQmlComponentPtr newComp = getComponent(mRootObject, path);
            applyNewComponent(path, newComp);
            newComp.clear();
        }
        else{
            applyNewComponent(path, mCacheScreen[path]);
        }

        if(mCacheScreen[path].data()->isError()){
            qWarning() << "SCREEN_STATE ERROR:" << mCacheScreen[path].data()->errors();
        }
        else{
            qWarning() << "Current Screen path: "<<mCacheScreen[path]->url();
            mCurrentScreen = scr;
        }
    }
    return ret;
}

void uicommon::ScreenManager::applyNewComponent(const QString& path,const QQmlComponentPtr& component)
{
    // Fix klocwork START
    if (component != nullptr){
        if ((currentComponent == nullptr) || (component->url() != currentComponent->url())){
            currentComponent = component;
            mContext->setContextProperty("HMIScreen", currentComponent.data());
            mCacheScreen.insert(path, currentComponent);
        }
    }
    //Fix klocwork END
}

uint32_t uicommon::ScreenManager::getCurrentScreen() const
{
    return (NULL != mCurrentScreen) ? mCurrentScreen->id : 0;
}

QQmlComponentPtr uicommon::ScreenManager::getComponent(QObject *parent, QString screenFile) {
    //Fix klocwork START
    QQmlComponentPtr component;
    if(nullptr != parent){
        QQmlEngine *engine = qmlEngine(parent);
        if(nullptr != engine) {
            component = QQmlComponentPtr(new QQmlComponent(engine, screenFile, this));
            QQmlEngine::setObjectOwnership(component.data(), QQmlEngine::CppOwnership);
        }else{
            component = QQmlComponentPtr(nullptr);
        }
    }else{
        component = QQmlComponentPtr(nullptr);
    }
    return component;
    //Fix klocwork END
}

void uicommon::ScreenManager::createComponent(const QString& path){
    if(!mCacheScreen.contains(path)){
        QQmlComponentPtr newComp = getComponent(mRootObject, path);
        mCacheScreen.insert(path, newComp);
        newComp.clear();
    }
}
