import UICommon.Base
import UICommon.CItems
import QtQuick
CListView{
    id:     listSetting
    x:      DelegateConstants._OFFSET_LISTSETTING_X
    y:      DelegateConstants._OFFSET_LISTSETTING_Y
    width:  DelegateConstants._LIST_SETTING_WIDTH
    height: DelegateConstants._LIST_SETTING_HEIGHT
    property bool isBuiltInModel: false
    property var visibleTracking:[]
    property bool isPopupOpened: prvtController.currentSelected !== -1
    cacheBuffer: listSetting.count * 80
    fadingActive: true
    QtObject{
        id: prvtController
        property int offSet: 0
        function modifyVisibility(index, visible){
            if (index < 0 || index >= listSetting.visibleTracking.length) return
            listSetting.visibleTracking[index] = visible
            onVisibleItemChanged()
        }
        function onVisibleItemChanged(){
            let _count  = 0,
                _height = 0;
            for (let visible of listSetting.visibleTracking){
                if (visible) ++_count;
            }
            _height = DelegateConstants._DELEGATE_HEGIHT * _count;
            if (_height <= DelegateConstants._LIST_SETTING_HEIGHT + prvtController.offSet){
                interactiveCondition = false;
            }else{
                interactiveCondition = true;
            }
        }
        property int currentSelected: -1
        function modify(index){
            currentSelected = index
        }
    }
    delegate: 
            Delegator{
                id                      : delegator
                source                  : model.delegate
                modifyCurrentIndex      : prvtController.modify
                currentIndex            : prvtController.currentSelected
                listContainer           : listSetting
                visibleChangedHandler   : prvtController.modifyVisibility
                states:[
                    State{
                        when: listSetting.isBuiltInModel && model.type !== DelegateConstants._NAVI_DELEGATE
                        PropertyChanges{
                            target             : delegator
                            source             : model.type
                            isBuiltInModel     : true
                            customProcessor    : listSetting.model.modifySettings
                        }
                    },
                    State{
                        when: listSetting.isBuiltInModel && model.type === DelegateConstants._NAVI_DELEGATE
                        PropertyChanges{
                            target             : delegator
                            source             : model.type
                            isBuiltInModel     : true
                            customProcessor    : listSetting.model.conductRequest
                        }
                    }
                ]
            }
}
