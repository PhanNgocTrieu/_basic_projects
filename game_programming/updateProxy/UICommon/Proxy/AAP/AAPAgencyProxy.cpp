/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c AAPAgencyProxy -p AAPAgencyProxy AAPAgency.xml
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "AAPAgencyProxy.h"

namespace uicommon
{
    AAPAgencyProxy &AAPAgencyProxy::getInstance()
    {
        static AAPAgencyProxy singleton("ese.hmi.syspopup", "/AAPAgency", QDBusConnection::sessionBus());

        return singleton;
    }


    AAPAgencyProxy::AAPAgencyProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
        : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    {
        qInfo() << "AAPAgencyProxy create instance";
    }

    AAPAgencyProxy::~AAPAgencyProxy()
    {
    }

}