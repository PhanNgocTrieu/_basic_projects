#ifndef POPUPMANAGER_H
#define POPUPMANAGER_H

#include <QObject>
#include <QStack>
#include <QSharedPointer>
#include <QTimer>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQmlContext>
#include "HMIFramework.h"
namespace uicommon {
	class PopupObject;
	class PopupManager;
	typedef QSharedPointer<PopupObject> PopupObjectPtr;

	class PopupManager : public QObject
	{
	    Q_OBJECT
	public:
	    explicit PopupManager(QQuickItem* rootObject, QQmlContext* context, uint32_t scr);
	    virtual ~PopupManager();
	    QList<uint32_t> getCurrentPopup() const;
	    bool showPopup(POPUP_DATA p);
	    bool hidePopup(POPUP_DATA p);
	    bool closeAlls();
	private:
	    uint32_t                mScreen;
	    QQuickItem              *mRootObject;
	    QQmlContext             *mContext;
	    QList<PopupObjectPtr>   mListPopups;
	    QStringList             mQmlOlder;
	    void qmlSyn();

	public slots:
	    void ontimeoutHidePopup(uint32_t tempId);
	};

	class PopupObject: public QTimer
	{
	    Q_OBJECT
	public:
	    explicit PopupObject(POPUP_DATA p, uint32_t screen);
	    virtual ~PopupObject();
	    POPUP_DATA popupInfos() const;
	private:
	    POPUP_DATA   mpopupInfos;
	    uint32_t     mScreen;
	signals:
	    void timeoutHidePopup(uint32_t tempId);
	public slots:
	    void timeoutExec();
	};
}

#endif // POPUPMANAGER_H
