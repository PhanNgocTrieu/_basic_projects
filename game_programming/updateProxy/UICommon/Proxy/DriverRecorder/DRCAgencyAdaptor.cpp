#include "DRCAgencyAdaptor.h"

#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

namespace uicommon{
    DRCAgencyAdaptor::DRCAgencyAdaptor(DRCAgency* parent)
        :QDBusAbstractAdaptor(parent)
    {
        setAutoRelaySignals(true);
    }

    DRCAgencyAdaptor::~DRCAgencyAdaptor()
    {

    }

    void DRCAgencyAdaptor::requestDRCService(uicommon::DRCAgencyRequest req,  int reqValue ){
        QMetaObject::invokeMethod(parent(),"requestDRCService",Q_ARG(uicommon::DRCAgencyRequest, req), Q_ARG(int,reqValue));
    }   

    QString DRCAgencyAdaptor::getDVRVersion(){
        return static_cast<QString>(parent()->getDVRVersion());
    }

    void DRCAgencyAdaptor::stopRecordingForTransition()
    {
        return parent()->stopRecordingForTransition();
    }

    void DRCAgencyAdaptor::confirmStopRecoding()
    {
        return parent()->confirmStopRecoding();
    }

    void DRCAgencyAdaptor::indicateEmptyStorage()
    {
        return parent()->indicateEmptyStorage();
    }

    uicommon::RecordingStatus DRCAgencyAdaptor::getRecordingStatus()
    {
        return parent()->getRecordingStatus();
    }

    void DRCAgencyAdaptor::toPreviewMode()
    {
        return parent()->toPreviewMode();
    }

    void DRCAgencyAdaptor::outPreviewMode()
    {
        return parent()->outPreviewMode();
    }

    bool DRCAgencyAdaptor::isSDCardPlugIn()
    {
        return parent()->isSDCardPlugIn();
    }

    void DRCAgencyAdaptor::confirmHighTemperature()
    {
        return parent()->confirmHighTemperature();
    }

    void DRCAgencyAdaptor::confirmDisconnectionWithAllowanceToAppearAgain(bool allowed)
    {
        return parent()->confirmDisconnectionWithAllowanceToAppearAgain(allowed);
    }

    void DRCAgencyAdaptor::confirmUpdating()
    {
        return parent()->confirmUpdating();
    }

    void DRCAgencyAdaptor::confirmDropSDCard()
    {
        return parent()->confirmDropSDCard();
    }
    
    void DRCAgencyAdaptor::confirmFileAccessError()
    {
        return parent()->confirmFileAccessError();
    }

    void DRCAgencyAdaptor::confirmResumesRecording()
    {
        return parent()->confirmResumesRecording();
    }
};
