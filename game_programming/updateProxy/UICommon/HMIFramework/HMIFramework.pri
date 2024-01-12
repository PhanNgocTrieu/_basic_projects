QT += qml quick
CONFIG += c++11
QMAKE_CXXFLAGS_WARN_ON  += -Wno-unused-parameter

INCLUDEPATH +=  $$PWD/HMICommon \
                $$PWD/HMIViewer \
                $$PWD/HMIViewer/ScreenManager \
                $$PWD/HMIViewer/Common \
                $$PWD/HMIViewer/HMICommon \
                $$PWD/../IDSWindowTemplate 

HEADERS += \
    $$PWD/HMICommon/CommonFunctions.h \
    $$PWD/HMIViewer/HMIViewer.h \
    $$PWD/HMIViewer/ScreenManager/ScreenManager.h \
    $$PWD/HMIViewer/Common/CommonDefines.h \
    $$PWD/HMIViewer/Common/CommonStructs.h \
    $$PWD/HMIViewer/Common/CommonEnums.h \
    $$PWD/HMIViewer/Common/HMIFramework.h \
    $$PWD/HMIViewer/ScreenManager/ScreenQueue.h

SOURCES += \
    $$PWD/HMIViewer/HMIViewer.cpp \
    $$PWD/HMIViewer/ScreenManager/ScreenManager.cpp \
    $$PWD/HMIViewer/ScreenManager/ScreenQueue.cpp

RESOURCES += \
    $$PWD/HMIFramework.qrc
