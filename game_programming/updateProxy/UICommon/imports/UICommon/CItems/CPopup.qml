import QtQuick
import UICommon.Base 
import UICommon.SysUI 1.0
/*!
    This item is used as a container for popup item
    It will process and return value to the world
*/
Item{
    id:root
    anchors.fill:parent
    /*!
        This property will be used to define whether or not the popup is treated as
        a modal (cannot close popup when clicking outside)
    */
    required property bool isModal
    /*!
        This property will be used to define whether or not the popup uses a mask
    */
    required property bool isMaskScreen
    /*!
        This property links to the path of QML file
    */
    required property var popupPath
    onPopupPathChanged: {
        var typePopup = typeof popupPath
        if (typePopup === "string"){
            popupLoader.source = popupPath
        }else if (typePopup === "object"){
            popupLoader.sourceComponent = popupPath
        }
    }
    function requestShow(appID){
        if (privateController.handlerExist){
            UIConstants._SCREEN_STATE[appID] = SysUI.QueueTransition
            APP_ENGINE.requestShowScreen(appID)
        }
    }
    function requestHide(appID){
        if (privateController.handlerExist){
            UIConstants._SCREEN_STATE[appID] = SysUI.HideTransition
            APP_ENGINE.requestHideScreen(appID)
        }
    }
    property QtObject args
    /*!
        This property hold the lifetime of the popup
        If duration equals 0, popup will open forever until it is closely by user
    */
    property bool timerActive:true
    property bool loaderActive:false
    property int duration:0
    function startTimer(){
        lifeTimeController.start()
    }
    function stopTimer(){
        lifeTimeController.stop()
    }
    function restartTimer() {
        lifeTimeController.restart()
    }
    QtObject{
        id: privateController
        property bool handlerExist: false
        function handleReply(requestType, eventID){
            if (!UIConstants._SCREEN_STATE.hasOwnProperty(eventID)) return
            switch(requestType){
                case SysUI.ShowTransition:{
                    UIConstants._SCREEN_STATE[eventID] = SysUI.ShowTransition
                    root.active = true
                    break;
                }
                case SysUI.HideTransition:{
                    UIConstants._SCREEN_STATE[eventID] = SysUI.HideTransition
                    root.active = false
                    break;
                }
                case SysUI.QueueTransition:{
                    UIConstants._SCREEN_STATE[eventID] = SysUI.QueueTransition
                    break;
                }
                default: break;
            }
        }
        function handlerOverflowText(pathScreen){
            root.popupPath = pathScreen
            root.duration  = 0
            root.active    = true
        }
    }
    Component.onCompleted:{
        if (typeof APP_ENGINE != "undefined"){
            privateController.handlerExist = true
            // APP_ENGINE.requestScreenReply.connect(privateController.handleReply)
            if(APP_ENGINE?.overFlowRequestShowPopup){
                APP_ENGINE.overFlowRequestShowPopup.connect(privateController.handlerOverflowText)
            }
        }
    }
    Connections{
        target: APP_ENGINE
        function onRequestScreenReply(requestType, eventID)
        {
            privateController.handleReply(requestType, eventID)
        }
    }
    signal timeOut()
    Timer{
        id:lifeTimeController
        interval: duration
        onTriggered: {
            root.close()
            root.timeOut()
        }
    }

    /*!
        It is a popupItem
    */
    property alias popupItem:popupLoader.item
    /*!
        Set this property to true will open the popup and vice-versa
    */
    property bool active:false

    onDurationChanged: {
        if(active) {
            lifeTimeController.start()
        }
    }


    onActiveChanged: {
        if (active){
            if (duration) lifeTimeController.start()
            root.open()
        }else{
            lifeTimeController.stop()
            root.close()
        }
    }
    /*!
        Set this property to true will disable background
    */
    property bool isDisableBackground:false
    /*!
        Signal to notify when closing un-modal Popup
    */
    signal popupClosed()
    /*!
        Signal to notify when opening Popup
    */
    signal popupOpened()
    /*!
        Popup actions for manually closing and opening
    */
    function close(){
        root.loaderActive = false
        root.timerActive = false
        root.popupClosed()
    }
    function open(){
        root.loaderActive = true
        root.timerActive = true
        root.popupOpened()
    }
    /*!
        Holding click event and process based on isModal value
    */
    MouseArea{
        anchors.fill:parent
        enabled: popupLoader.active
        /*!
            Reserved for future using
        */
        onPressed: {
        }
        onClicked:{
            if (!root.isModal) root.close()
        }
    }
    Image{
        visible:popupLoader.active && root.isMaskScreen
        anchors.fill:parent
        source:"qrc:/qt-project.org/imports/UICommon/CItems/MaskPopup.png"
    }
    /*!
        This loader will hold popup item
    */
    Loader{
        id:popupLoader
        active:root.active && root.timerActive && root.loaderActive
        anchors.fill:parent
    }
    /*!
        Masking the system
    */
    Binding{
        target: mainRootItem
        property: "maskBackgroundPopup"
        value: popupLoader.active && root.isMaskScreen
    }
    Binding{
        target: mainRootItem
        property: "isDisableBackGround"
        value: popupLoader.active && root.isDisableBackground
    }
}
