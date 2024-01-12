import QtQuick 2.0
import "./Common/js/def_constants.js" as CONST
import "./Common/js/def_resources.js" as RESOURCES
import UICommon.Base
Window {
    id:mainRootItem
    width: 1280
    color:"transparent"
    height: 720
    property bool showPopup:false
    property bool maskBackgroundPopup:false
    property bool showCamera: false
    property bool requestShowFull: maskBackgroundPopup || showPopup 
    property var screenParameters
    onRequestShowFullChanged: {
        if (requestShowFull){
            // VehicleGeneralState.playSound(VehicleGeneralState.Popup)
            // Temporarily disable till having the proper definitions of which type of popup should be played sounds
        }
        APP_ENGINE.callOutToShowInternalPopup(requestShowFull)

        if (requestShowFull){
            VehicleGeneralState.popupStatus("HAS_POPUP")
        }else{
            VehicleGeneralState.popupStatus("UNDEFINED")
        }
    }
    property bool isDisableBackGround:false
    Image {
        anchors.fill: parent
        visible: mainRootItem.requestShowFull
        source: "qrc:/qt-project.org/imports/UICommon/CItems/MaskPopup.png"
    }
    Rectangle{
        visible: mainRootItem.isDisableBackGround
        anchors.fill:parent
        color:'black'
    }
    Loader {
        id: main_layer
        width: HMI_SCREEEN_MAXSIZE && !mainRootItem.showCamera && !IS_FULLSIZE_APPLICATION? CONST.SCREEN_WIDTH  : HMI_SCREEN_WIDTH
        height:HMI_SCREEEN_MAXSIZE && !mainRootItem.showCamera && !IS_FULLSIZE_APPLICATION? CONST.SCREEN_HEIGHT : HMI_SCREEEN_HEIGHT
        x:     HMI_SCREEEN_MAXSIZE && !mainRootItem.showCamera && !IS_FULLSIZE_APPLICATION? CONST.CENTER_VIEW_X : 0
        y:     HMI_SCREEEN_MAXSIZE && !mainRootItem.showCamera && !IS_FULLSIZE_APPLICATION? CONST.CENTER_VIEW_Y : 0
        sourceComponent: HMIScreen
        onSourceComponentChanged: {
            if (UIConstants._APP_ENGINE == undefined){
                UIConstants._APP_ENGINE = APP_ENGINE
            }
            console.warn("Source Component Changed " + HMIScreen)
        }
    }
    ListModel { id: onsDataList }
    Repeater {
        id:ons_Creator
        model: onsDataList
        anchors.left: parent.left;
        Loader {
            id: osd_Loader
            width: CONST.SCREEN_WIDTH
            height: CONST.SCREEN_HEIGHT
            source: osdSource
        }
    }
    function load_Popup(Onsdata, popCount) {
        onsDataList.clear()
        for(var onsCnt = 0; onsCnt < popCount; onsCnt++ ) { var data = {'osdSource': Onsdata[onsCnt]}; onsDataList.append(data) }
    }
}
