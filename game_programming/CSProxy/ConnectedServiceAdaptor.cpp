/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -l ConnectedService -c ConnectedServiceInf -a ConnectedServiceAdaptor -p ConnectedServiceProxy ConnectedServiceInf.xml
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "ConnectedServiceAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class ConnectedServiceInf
 */

ConnectedServiceInf::ConnectedServiceInf(ConnectedService *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

ConnectedServiceInf::~ConnectedServiceInf()
{
    // destructor
}

void ConnectedServiceInf::requestDeleteDigitalKey()
{
    // handle method call ese.hmi.csif.requestDeleteDigitalKey
    parent()->requestDeleteDigitalKey();
}

void ConnectedServiceInf::requestEndCall()
{
    // handle method call ese.hmi.csif.requestEndCall
    parent()->requestEndCall();
}

QList<srvwrp::ConnectedServiceWrapper::ConnectedInformation> ConnectedServiceInf::requestGetConnectedInformations()
{
    // handle method call ese.hmi.csif.requestGetConnectedInformations
    return parent()->requestGetConnectedInformations();
}

int ConnectedServiceInf::requestGetDigitalKeyActiveStatus()
{
    // handle method call ese.hmi.csif.requestGetDigitalKeyActiveStatus
    return parent()->requestGetDigitalKeyActiveStatus();
}

int ConnectedServiceInf::requestGetDigitalKeySettingStatus()
{
    // handle method call ese.hmi.csif.requestGetDigitalKeySettingStatus
    return parent()->requestGetDigitalKeySettingStatus();
}

QList<srvwrp::ConnectedServiceWrapper::ImageDataBase64> ConnectedServiceInf::requestListWallPaperDownload()
{
    // handle method call ese.hmi.csif.requestListWallPaperDownload
    return parent()->requestListWallPaperDownload();
}

int ConnectedServiceInf::requestResetNetwork()
{
    // handle method call ese.hmi.csif.requestResetNetwork
    return parent()->requestResetNetwork();
}

void ConnectedServiceInf::requestSetDigitalKeyActiveStatus(int digKeySetActStt)
{
    // handle method call ese.hmi.csif.requestSetDigitalKeyActiveStatus
    parent()->requestSetDigitalKeyActiveStatus(digKeySetActStt);
}

void ConnectedServiceInf::requestSetDigitalKeySettingStatus(int digKeySetStt)
{
    // handle method call ese.hmi.csif.requestSetDigitalKeySettingStatus
    parent()->requestSetDigitalKeySettingStatus(digKeySetStt);
}

void ConnectedServiceInf::requestStartCall()
{
    // handle method call ese.hmi.csif.requestStartCall
    parent()->requestStartCall();
}

