#ifndef COMMONSTRUCTS_H
#define COMMONSTRUCTS_H
#include <QString>
#include <QVariant>
#include <stddef.h>
#include <QQmlComponent>
#include "CommonDefines.h"
#include "CommonEnums.h"

typedef QSharedPointer<QQmlComponent> QQmlComponentPtr;

namespace uicommon {
	typedef struct popup_data
	{
	    uint32_t       id;
	    LIMIT       duration;
	    QString     QmlPath;
	    QVariant    msg;
	} POPUP_DATA;

	typedef struct st_application_states
	{
	    uint32_t       id;
	    LAYER       layerbase;
	    LIMIT       duration;
	    QString     QmlPath;
	} APPLICATION_STATE;

	typedef struct _st_state_trigger
	{
	    uint32_t                evt;
	    const APPLICATION_STATE *trans;
	}STATE_TRIGGER;

	typedef struct _st_state_system
	{
	    uint32_t                id;
	    const STATE_TRIGGER     *trigger;
	    uint                    size;
	    const APPLICATION_STATE *state;
	}STATE_SYSTEM;

	struct SCREEN_T{
	    QString             scrName;
	    QQmlComponentPtr    qml;
	};

}
#endif // COMMONSTRUCTS_H
