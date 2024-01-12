#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQmlContext>

#include "HMIFramework.h"
#include "ScreenQueue.h"
#include <QQuickWindow>
namespace uicommon {
class ScreenManager : public QObject
{
public:
    explicit ScreenManager(QQuickWindow* rootObject, QQmlContext* context, uint32_t scr);
    virtual ~ScreenManager();

    bool showScreen(const APPLICATION_STATE *scr, QVariant msg = QVariant());
    uint32_t getCurrentScreen() const;

    void createComponent(const QString& path);
private:
    // It's static so it can be shared with all instances.
    // Since both views are sharing the QQmlEngine we can simply reuse the QQmlComponents.
    // The Loader will set the correct QQmlContext on them, so they see the properties for the view
    // they are in.
    static uicommon::ScreenQueue mCacheScreen;
    QQuickWindow          *mRootObject;
    QQmlContext         *mContext;
    uint32_t            mScreen;
    const APPLICATION_STATE *mCurrentScreen;
private:
    void applyNewComponent(const QString& path,const QQmlComponentPtr& component);
private:
    QQmlComponentPtr getComponent(QObject *parent, QString screenFile);
    QQmlComponentPtr currentComponent;
};
}
#endif // SCREENMANAGER_H
