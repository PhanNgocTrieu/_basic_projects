import QtQuick
import UICommon.Base
Item {
    id:rootItem
    anchors.fill:parent

    //property bool isSCO13: false
    readonly property alias showStatus: __privCtrl.popupStatus
    readonly property alias maskScreenVisible: __privCtrl.maskScreenVisible

    function close()
    {
        if (!__privCtrl.popupStatus) {
            Logger.logInf("__privCtrl.popupStatus " + __privCtrl.popupStatus)
            return
        }
        __dueTime.stop()
        __privCtrl.popupStatus = false

        popupLoader.source=""

        //isSCO13 = false       
    }

    function show(isModal,isMaskScreen,source,controller)
    {
        if (__privCtrl.popupStatus) {
            rootItem.close()
        }

        __privCtrl.isModal = isModal
        __privCtrl.isMaskScreen = isMaskScreen
        __privCtrl.popupController = controller
        __privCtrl.popupStatus = true

        popupLoader.source = source
        // if(source === "qrc:/QML_RESOURCES/Qml/Screens/SettingCommunication/SCREEN_SETTING_COMMUNICATION_SCO_13.qml") {
        //     __privCtrl.popupStatus = isMaskScreen
        //     isSCO13 = true
        // } else {
        //     isSCO13 = false
        // }
        Logger.logInf("source: " + source)
    }

//    function showWithDueTime(duration,dueTimeHandler,isModal,isMaskScreen,source,controller)
//    {
//        if (__privCtrl.popupStatus) {
//            return
//        }

//        __privCtrl.isModal = isModal
//        __privCtrl.isMaskScreen = isMaskScreen
//        __privCtrl.dueTimeHandler = dueTimeHandler
//        __privCtrl.popupController = controller
//        __privCtrl.popupStatus = true

//        popupLoader.source = source

//        dueTime.interval = duration

//        dueTime.start()

//    }
    function startDueTimer(duration,dueTimeHandler)
    {
        __dueTime.interval = duration
        __dueTime._dueTimeHandler = dueTimeHandler
        __dueTime.restart()
    }

    QtObject {
        id: __privCtrl
        property bool popupStatus: false
        property bool isMaskScreen: false
        property bool isModal: false
        property bool maskScreenVisible: isMaskScreen && popupStatus
        property var popupController
    }


    Timer {
        id:__dueTime
        repeat:false
        running: false
        property var _dueTimeHandler
        onTriggered: {
            if (_dueTimeHandler) {
                _dueTimeHandler()
            }
        }
    }

    Image {
        visible: __privCtrl.maskScreenVisible
        anchors.fill:parent
        source:"qrc:/qt-project.org/imports/UICommon/CItems/MaskPopup.png"
    }

    CMouseArea {
        anchors.fill: parent
        isObject:    false
        isEnableSound: false
        enabled:     __privCtrl.popupStatus
        onClicked:{
            if (!__privCtrl.isModal) {
                rootItem.close()
            }
        }
    }

    Loader{
        id:popupLoader

        property var screenController: __privCtrl.popupController

        anchors.fill:parent
        active:true
    }
}
