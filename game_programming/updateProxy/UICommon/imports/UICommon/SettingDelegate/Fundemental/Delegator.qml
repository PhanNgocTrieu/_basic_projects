import UICommon.Base
import UICommon.CItems
import QtQuick
CLoader{
    id: loadItem
    property var source
    property var modifyCurrentIndex
    property int currentIndex
    property bool _IN_LIST_SETTING: true
    property var listContainer
    property var visibleChangedHandler
    property bool isBuiltInModel: false
    property var customProcessor
    Component.onCompleted:{
        // If the passed in source has the type of number, that means it will choose the component from
        // Default component arrays
        let itemCmpnt;
        if (typeof source == "number"){
            itemCmpnt = DelegateConstants.delegateInstance[source];
        }else if (typeof source == "object"){
            itemCmpnt = source
        }
        loadItem.sourceComponent = itemCmpnt
    }
    QtObject{
        id: privateController
        function onVisibleChanged(){
            if (typeof model != "undefined"){
                loadItem.visibleChangedHandler(model.index, item.visible)
            }

        }
    }
    onItemChanged:{
        if (item != undefined){
            item.index                 =  model.index
            item.modifyCurrentIndex    =  loadItem.modifyCurrentIndex
            item.currentIndexInSetting =  Qt.binding(function(){return currentIndex})
            item.indexInList           =  model.index
            item.listContainer         =  loadItem.listContainer
            if (loadItem.isBuiltInModel)
            {
                model.processor = loadItem.customProcessor
                item.applySetting(model)
                loadItem.listContainer.visibleTracking[model.index] = model.available
            }
            else
            {
                item.applySetting(model.compPro)
                loadItem.listContainer.visibleTracking[model.index] = model.compPro.visible
            }
            item.visibleChanged.connect(privateController.onVisibleChanged)
            privateController.onVisibleChanged()
        }
    }
}