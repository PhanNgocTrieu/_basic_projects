#ifndef SCREENQUEUE_H
#define SCREENQUEUE_H

#include <QObject>
#include <QQmlComponent>
#include <QSharedPointer>
#include <QMutex>
#include "../../HMICommon/CommonFunctions.h"
#include "CommonStructs.h"

#define MAX_DEEP_LIMIT 10
namespace uicommon {
	class ScreenQueue : public QObject
	{
	    Q_OBJECT
	    QMutex          mMutex;
	protected:
	    uchar           mMaxDeep;
	    QList<SCREEN_T> mScreenList;
	public:
	    explicit ScreenQueue(uchar max_deep = static_cast<uchar>(MAX_DEEP_LIMIT), QObject *parent = nullptr);
	    virtual ~ScreenQueue();
	    bool contains(const QString &tempid);
	    QQmlComponentPtr getScreen(const QString &scrName);
	    void insert(const QString &scrName, QQmlComponentPtr qml);
	    void setMaxDeep(int max_deep);
	    QQmlComponentPtr operator[](const QString &scrName);
	    void initializeQueue();
	};
}
#endif // SCREENQUEUE_H
