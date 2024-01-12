
#include "AAPAgencyAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

namespace uicommon
{
    /*
    * Implementation of adaptor class AAPAgencyAdaptor
    */

    AAPAgencyAdaptor::AAPAgencyAdaptor(AAPAgency *parent)
        : QDBusAbstractAdaptor(parent)
    {
        // constructor
        setAutoRelaySignals(true);
    }

    AAPAgencyAdaptor::~AAPAgencyAdaptor()
    {
        // destructor
    }

    int AAPAgencyAdaptor::getCurrentState()
    {
        // handle method call ese.hmi.aapagency.getCurrentState
        return parent()->getCurrentState();
    }

    bool AAPAgencyAdaptor::setOperationMode(int mode)
    {
        // handle method call ese.hmi.aapagency.setOperationMode
        return parent()->setOperationMode(mode);
    }
     
    bool AAPAgencyAdaptor::setSourceOn(bool isSourceOn)
    {
        // handle method call ese.hmi.aapagency.setSourceOn
        return parent()->setSourceOn(isSourceOn);
    }

    bool AAPAgencyAdaptor::enjectKeyEvent(int keyCode, int keyStatus)
    {
        // handle method call ese.hmi.aapagency.enjectKeyEvent
        return parent()->enjectKeyEvent(keyCode, keyStatus);
    }

    uicommon::AAPAgency::MediaMetaData AAPAgencyAdaptor::getMediaMetaData()
    {
        // handle method call ese.hmi.aapagency.getMediaMetaData
        return parent()->getMediaMetaData();
    }

    uicommon::AAPAgency::MediaStatus AAPAgencyAdaptor::getMediaStatus()
    {
        // handle method call ese.hmi.aapagency.getMediaStatus
        return parent()->getMediaStatus();
    }

    bool AAPAgencyAdaptor::setAAPContrastStepValue(QString detail)
    {
        return parent()->setContrastStepValue(detail);
    }

    bool AAPAgencyAdaptor::setAAPColorStepValue(QString detail)
    {
        return parent()->setColorStepValue(detail);
    }

    QString AAPAgencyAdaptor::getAAPContrastStepValue()
    {
        return parent()->getContrastStepValue();
    }

    QString AAPAgencyAdaptor::getAAPColorStepValue()
    {
        return parent()->getColorStepValue();
    }

    int AAPAgencyAdaptor::getAAPDayContrastValue()
    {
        return parent()->getDayContrastValue();
    }

    bool AAPAgencyAdaptor::setAAPDayContrastValue(int value)
    {
        return parent()->setDayContrastValue(value);
    }

    int AAPAgencyAdaptor::getAAPDayColorValue()
    {
        return parent()->getDayColorValue();
    }

    bool AAPAgencyAdaptor::setAAPDayColorValue(int value)
    {
        return parent()->setDayColorValue(value);
    }

    int AAPAgencyAdaptor::getAAPNightContrastValue()
    {
        return parent()->getNightContrastValue();
    }

    bool AAPAgencyAdaptor::setAAPNightContrastValue(int value)
    {
        return parent()->setNightContrastValue(value);
    }

    int AAPAgencyAdaptor::getAAPNightColorValue()
    {
        return parent()->getNightColorValue();
    }

    bool AAPAgencyAdaptor::setAAPNightColorValue(int value)
    {
        return parent()->setNightColorValue(value);
    }
}
