#include "ScreenQueue.h"
#include <QMutexLocker>
uicommon::ScreenQueue::ScreenQueue(uchar max_deep, QObject *parent) : QObject(parent),mMaxDeep(max_deep)
{

}

uicommon::ScreenQueue::~ScreenQueue()
{

}
bool uicommon::ScreenQueue::contains(const  QString& tempid){
    QMutexLocker locker(&mMutex);
    //Fix klocwork START
    bool isContainsScreen = false;
    for(qsizetype i = 0; i < mScreenList.size(); i++){
        if( mScreenList.at(i).scrName ==  tempid){
            isContainsScreen = true;
            break;
        }
    }
    return isContainsScreen;
    //Fix klocwork END
}

QQmlComponentPtr uicommon::ScreenQueue::getScreen(const  QString& scrName){
    QMutexLocker locker(&mMutex);
    //Fix klocwork START
    QQmlComponentPtr component = QQmlComponentPtr();
    for(qsizetype i = 0; i < mScreenList.size(); i++){
        if( mScreenList.at(i).scrName == scrName){
            component =  mScreenList.at(i).qml;
            break;
        }
    }
    return component;
    //Fix klocwork END
}

void uicommon::ScreenQueue::insert(const  QString& scrName, QQmlComponentPtr qml){
    QMutexLocker locker(&mMutex);
    if(mScreenList.count() >= mMaxDeep){
        mScreenList.removeLast();
    }
    //Fix klocwork START
    uicommon::SCREEN_T t;
    t.scrName = scrName;
    t.qml = qml;
    //Fix klocwork END
    mScreenList.insert(0,t);
}


void uicommon::ScreenQueue::setMaxDeep(int max_deep){
    QMutexLocker locker(&mMutex);
    if((max_deep >= 0) && (max_deep <= UCHAR_MAX)) {
        mMaxDeep = static_cast<uchar>(max_deep);
    }
    if(static_cast<qsizetype>(mMaxDeep) < mScreenList.count()){
        qsizetype gap = static_cast<qsizetype>(mScreenList.count() - mMaxDeep);
        for(qsizetype i = 0; i < gap; i++){
            mScreenList.removeLast();
        }
    }
}

QQmlComponentPtr uicommon::ScreenQueue::operator[](const QString &scrName){
    return getScreen(scrName);
}

void uicommon::ScreenQueue::initializeQueue()
{
    QMutexLocker locker(&mMutex);
    while (mScreenList.count() > 1) {
        mScreenList.removeLast();
    }
}
