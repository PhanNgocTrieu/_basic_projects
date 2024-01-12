import QtQuick
import UICommon.Base
import UICommon.CItems
NavigateDelegate{
    id: selectionPopup
    textWidth: 612
    isOnlyNavigator: false
    /**
      * @brief With Selection popup, it comes up with many selections which allow user to
      *        choose. This variable is a set of selections
      */
    property alias selections       : selectionItem.selections
    property alias currentSelection : selectionItem.currentSelection
    property bool isObjectSelection : false
    property alias active           : selectionItem.active
    property alias representativeRightMargin: selectionItem.representativeRightMargin
    hasUsageOfCurrentItem: true
    signal closePopup()
    signal selectItem(int index)
    onSettingApply:{
        if (setting != undefined){
            if (typeof setting.currentSelection != "undefined")
            {
                selectionItem.currentSelection = Qt.binding(function() {return setting.currentSelection})
            }
            else if (typeof setting.currentIndex != "undefined")
            {
                selectionItem.currentSelection = Qt.binding(function() {return setting.currentIndex})
            }           
            selectionItem.selections = Qt.binding(function() {return setting.selectionList})
        }
//        // start overflow
//        if(DelegateConstants._UI_COMMUNICATION.overFlowRequest()){
//            selectionPopup.active = true
//        }
//        // end overflow
    }
    onReleased:{
        if (!(VehicleGeneralState.isDriving && selectionPopup.isObject)) selectionPopup.active = true
    }
    onVisibleChanged:{
//        // start overflow
//        if(DelegateConstants._UI_COMMUNICATION.overFlowRequest()){
//            return
//        }
//        // end overflow
        if (!visible && (currentIndexInSetting === index)) {
            selectionPopup.active = false
            selectionPopup.closePopup()
            if (modifyCurrentIndex != undefined){
                modifyCurrentIndex(DelegateConstants._UNSELECT_INDEX)
            }
        }
    }
    SelectionPopupComponent{
        id: selectionItem
        inActiveState: selectionPopup.disableActions
        pressedState  : selectionPopup.pressedState
        isObject      : selectionPopup.isObjectSelection
        onReleased:{
            if (modifyCurrentIndex != undefined){
                modifyCurrentIndex(DelegateConstants._UNSELECT_INDEX)
            }
            selectionPopup.active = false
            selectionPopup.closePopup()
        }
        onSelectItem: (index) => {
            // If the processor is differ from undefined, that means the processor
            // has been applied. Thus no need of exposing handling to outside world
            if (setting?.processor && setting.processor != undefined){
                setting.processor(setting.settingType, index)
            }else{
                selectionPopup.selectItem(index)
            }
        }
        property int textId: -1
        Component.onCompleted:  {
            textId = selectionPopup.addLineCountElement(lineCount, 32)
        }
        onLineCountChanged: selectionPopup.calculationHeightElement(textId, lineCount)
    }
}
