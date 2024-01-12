import QtQuick
import UICommon.Base 
import UICommon.SysUI 1.0
/**
  * @brief This popup is dedicated to the internal Popup (Popup does not disable the background)
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

    property int duration: 0

    /*!
        This property hold the lifetime of the popup
        If duration equals 0, popup will open forever until it is closely by user
    */
    property bool timerActive:true
    property bool loaderActive:true
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
