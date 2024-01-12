#ifndef UICOMMON_GLOBAL_H
#define UICOMMON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UICOMMON_LIBRARY)
#  define UICOMMON_EXPORT Q_DECL_EXPORT
#else
#  define UICOMMON_EXPORT Q_DECL_IMPORT
#endif
#define LAN_JA_ID (0)
#endif // UICOMMON_GLOBAL_H
