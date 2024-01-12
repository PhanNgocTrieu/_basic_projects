#include "PopupManager.h"

uicommon::PopupManager::PopupManager(QQuickItem *rootObject, QQmlContext *context, uint32_t scr): mScreen(scr), mRootObject(rootObject), mContext(context)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    if(!mListPopups.isEmpty()){
        mListPopups.clear();
    }
    if(!mQmlOlder.isEmpty()){
        mQmlOlder.clear();
    }
}

uicommon::PopupManager::~PopupManager()
{

}

QList<uint32_t> uicommon::PopupManager::getCurrentPopup() const
{
    QList<uint32_t> list;
    for (int i = 0; i < mListPopups.count(); i++) {
        list.append(mListPopups.at(i).data()->popupInfos().id);
    }
    return list;
}

bool uicommon::PopupManager::showPopup(POPUP_DATA p)
{
    int cIdx = -1;
    bool existed = false;
    for (int i = 0; i < mListPopups.count(); i++)
    {
        if(p.id == mListPopups.at(i).data()->popupInfos().id){
            cIdx = i;
            existed = true;
            break;
        }
    }

    if(!existed){
        PopupObjectPtr popup = PopupObjectPtr(new uicommon::PopupObject(p, this->mScreen));
        mListPopups.append(popup);
        if(LIMIT::NONE != popup.data()->popupInfos().duration){
            popup.data()->start(static_cast<int>(p.duration));
        }
        QObject::connect(popup.data() , SIGNAL(timeoutHidePopup(uint32_t)),this, SLOT(ontimeoutHidePopup(uint32_t)), Qt::QueuedConnection);
    }
    else{
        if(cIdx != (mListPopups.count() - 1)){
            mListPopups.move(cIdx, mListPopups.count() - 1);
        }

        mListPopups.last().data()->start(static_cast<int>(p.duration));
    }

    // SHOW QML
    qmlSyn();
    return true;
}

bool uicommon::PopupManager::hidePopup(POPUP_DATA p)
{
    bool ret = false;
    for (int i = 0; i < mListPopups.count(); i++) {
        if(p.id == mListPopups.at(i).data()->popupInfos().id){
            if(mListPopups.at(i).data()->isActive()){
                mListPopups.at(i).data()->stop();
            }
            ret = true;
            mListPopups.at(i).data()->timeoutHidePopup(mListPopups.at(i).data()->popupInfos().id);
        }
    }
    return ret;
}

bool uicommon::PopupManager::closeAlls()
{
    for (int i = 0; i < mListPopups.count(); i++) {
        if(mListPopups.at(i).data()->isActive()){
            mListPopups.at(i).data()->stop();
        }
        mListPopups.at(i).data()->timeoutHidePopup(mListPopups.at(i).data()->popupInfos().id);
    }
    mListPopups.clear();
    return mListPopups.isEmpty();
}

void uicommon::PopupManager::qmlSyn()
{
    QStringList m_PopupQmlData;
    m_PopupQmlData.clear();

    for (int i = 0; i < mListPopups.count(); i++) {
        m_PopupQmlData << mListPopups.at(i).data()->popupInfos().QmlPath;
    }

    if(mQmlOlder != m_PopupQmlData){
        mQmlOlder.clear();
        mQmlOlder = m_PopupQmlData;
        QMetaObject::invokeMethod(mRootObject, JS_POPUPS_TRANSITION_FUNCTION, Q_ARG(QVariant, QVariant::fromValue(mQmlOlder)), Q_ARG(QVariant,QVariant::fromValue( mQmlOlder.count())));
    }
    m_PopupQmlData.clear();
}

void uicommon::PopupManager::ontimeoutHidePopup(uint32_t tempId)
{
    QMutableListIterator<PopupObjectPtr> i(mListPopups);
    while (i.hasNext()) {
        PopupObjectPtr bs = i.next();
        if(tempId == bs.data()->popupInfos().id){
            i.remove();
        }
    }
    qmlSyn();
}

uicommon::PopupObject::PopupObject(POPUP_DATA p, uint32_t screen): mpopupInfos(p), mScreen(screen)
{
    if(LIMIT::NONE != p.duration){
        QObject::connect(this , SIGNAL(timeout()),this, SLOT(timeoutExec()));
    }
}

uicommon::PopupObject::~PopupObject()
{
}

uicommon::POPUP_DATA uicommon::PopupObject::popupInfos() const
{
    return mpopupInfos;
}

void uicommon::PopupObject::timeoutExec()
{
    this->stop();
    emit timeoutHidePopup(mpopupInfos.id);
}
