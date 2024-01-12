/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i systemifapps_interface.h -p :systemifapps_interface.cpp ../../../native/1_SETTING_App/systemifapps.xml
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "SysUIInterface.h"
/*
 * Implementation of interface class HmiServiceSysifappsInterface
 */

HmiServiceSysifappsInterface::HmiServiceSysifappsInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

HmiServiceSysifappsInterface::~HmiServiceSysifappsInterface()
{
}

HmiServiceSysifappsInterface& HmiServiceSysifappsInterface::getInstance()
{

    static HmiServiceSysifappsInterface instance("hmi.service.sysifapps", "/SystemIfApps", QDBusConnection::sessionBus());
    qWarning()<<"IS connect "<<instance.isValid();

    return instance;
}

