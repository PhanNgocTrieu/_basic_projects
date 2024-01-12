import UICommon.Base
import UICommon.CItems
import QtQuick
CColumn{
    id: listSetting
    x: 32
    y: 80
    property bool isPopupOpened: privateController.currentSelected !== DelegateConstants._UNSELECT_INDEX
    property int  currentContentHeight: 0
    QtObject{
        id: privateController
        property int currentSelected: -1
        function modify(index){
            currentSelected = index
        }
    }
    Component.onCompleted:{
        for (let idx = 0 ; idx < listSetting.children.length; ++idx){
            if (listSetting.children[idx] instanceof SettingDelegateTemplate){
                listSetting.children[idx].currentIndexInSetting   = Qt.binding(function(){return privateController.currentSelected})
                listSetting.children[idx].modifyCurrentIndex      = privateController.modify
                listSetting.children[idx].index                   = idx
                listSetting.currentContentHeight                 += listSetting.children[idx].height
            }
//            // start overflow
//            if(DelegateConstants._UI_COMMUNICATION.overFlowRequest() && listSetting.children[idx] instanceof SelectionPopupDelegate){
//               listSetting.children[idx].active = true
//            }
//            // end overflow
        }
    }
}
