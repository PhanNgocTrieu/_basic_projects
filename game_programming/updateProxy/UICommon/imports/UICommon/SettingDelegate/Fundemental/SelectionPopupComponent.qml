import QtQuick
import UICommon.Base
import UICommon.CItems
CText{
    id: representative
    signal released()
    signal selectItem(int index)
    signal accept()
    signal reject()
    property var selections: ListModel{}
    property bool popupPlaceCentralItem: true
    property var contentFont: CFont._SUBBODY
    property var contentFontSelectionsList: CFont._BODY
    property bool isObject: true
    property alias containerParent  : container.parent
    property alias containerOffsetX : container.x
    property alias containerOffsetY : container.y
    property int  specificDetailWidth: 368
    Component.onCompleted: {
        privateController.demtermineCurrnetTitle()
        if (privateController.containsButtons)
        {
            if (requireOnlyConfirm)
            {
                selectConfirmation.sourceComponent = DelegateConstants._ACCEPT_BUTTON_DELEGATE
            }
            else if (requireConfirmAndCancel)
            {
                selectConfirmation.sourceComponent = DelegateConstants._ACCEPT_CANCEL_BUTTON_DELEGATE
            }
            privateController.selectionIndicator = DelegateConstants.toggleSelectionIndicatorDelegate
            privateController.titleProperty = DelegateConstants._MULTIPLE_selectionTitleProperty
        }else
        {
            privateController.titleProperty = DelegateConstants._ONE_selectionTitleProperty
            privateController.selectionIndicator = DelegateConstants.selectBoxIndicatorDelegate
        }
    }
    onSelectionsChanged:   
    {
        privateController.demtermineCurrnetTitle()
    }
    property bool active: false
    property int representativeRightMargin: 56
    property int currentSelection: -1
    onCurrentSelectionChanged: 
    {
        privateController.demtermineCurrnetTitle()
    }
    width: 252
    height: 36
    anchors{
        right: parent.right
        rightMargin: representative.representativeRightMargin
        verticalCenter: parent.verticalCenter
    }
    horizontalAlignment : Text.AlignRight
    verticalAlignment   : Text.AlignVCenter
    _font: representative.contentFont
    wrapMode: Text.Wrap
    property var anchorItem: representative
    property bool requireOnlyConfirm: false
    property bool requireConfirmAndCancel: false
    function getTotalHeight(height, currentIndex) {
        var totalHeight = 0;
        for (var i = 0; i < listSelection.count; ++i) {
            if(listSelection.itemAtIndex(i)?.height) {
                totalHeight += listSelection.itemAtIndex(i).height;
            }else if(currentIndex === i){
                totalHeight += height
            }
        }

        if (privateController.containsButtons)
        {
            totalHeight +=  112
        }else{
            totalHeight +=  32
        }

        if(totalHeight >= 528) {
            selectionList.height = 528
            listSelection.interactive  = true;
            listSelection.fadingActive = true;
            selectionList.heightImageBase = 528
            selectionList.sourceImageBase = UIConstants.background_popup_list_488x528
        } else  {
            if(totalHeight == 128) {
                selectionList.heightImageBase = 128
                selectionList.sourceImageBase = UIConstants.background_popup_list_488x128
            }else if(totalHeight == 192) {
                selectionList.heightImageBase = 192
                selectionList.sourceImageBase = UIConstants.background_popup_list_488x192
            } else {
                selectionList.heightImageBase = 528
                selectionList.sourceImageBase = UIConstants.background_popup_list_488x528
            }

            selectionList.height =  totalHeight
            listSelection.interactive  = false;
            listSelection.fadingActive = false;
            listSelection.positionViewAtBeginning()
        }
        if (representative.visible) privateController.calculatePositionOfSelectionPopup()
    }
//    function onVisibleItemChanged(){
//        listSelection.__count = 0
//        for (let idx = 0 ; idx < selections.count ; ++idx)
//        {
//            if (selections.get(idx).visible) ++listSelection.__count;
//        }
//        if (listSelection.__count > 6){
//            selectionList.height = 528
//        }
//        else{
//            if (privateController.containsButtons)
//            {
//                selectionList.height = (listSelection.__count + 1) * 80
//            }else{
//                selectionList.height = (listSelection.__count) * 80
//            }
//            listSelection.positionViewAtBeginning()
//        }
//        listSelection.__height = DelegateConstants._DELEGATE_HEGIHT * listSelection.__count;
//        if (listSelection.__height <= 528)
//        {
//            listSelection.interactive  = false;
//            listSelection.fadingActive = false;
//        }
//        else
//        {
//            listSelection.interactive  = true;
//            listSelection.fadingActive = true;
//        }
//        if (representative.visible) privateController.calculatePositionOfSelectionPopup()

//    }
    CItem{
        id: container
        parent: DelegateConstants._ROOT_ITEM
        width:  1008
        height: 624
        x: 136
        y: 80

        states:[
            State{
                when: representative.active
                StateChangeScript{
                    script: {
                        privateController.selectionListActive()
                        privateController.calculatePositionOfSelectionPopup()
                    }
                }
                PropertyChanges{target: outOfRegionController; enabled: true}
                PropertyChanges{target: selectionList;         visible: true}
            },
            State{
                when: !representative.active
                StateChangeScript{
                    script: {
                        privateController.selectionListInActive()
                    }
                }
                PropertyChanges{target: outOfRegionController; enabled: false}
                PropertyChanges{target: selectionList;         visible: false}
            }
        ]
        CMouseArea{
            id: outOfRegionController
            anchors.fill: parent
            isEnableSound: false
            isObject: false
            onReleased:
            {
                representative.released()
            }
        }
        QtObject{
            id: privateController
            property Component selectionIndicator
            property QtObject titleProperty: DelegateConstants._ONE_selectionTitleProperty
            property bool containsButtons: requireOnlyConfirm || requireConfirmAndCancel
            property int storeContentY: 0
            function demtermineCurrnetTitle(){
                 if(representative.selections != undefined && representative.currentSelection < representative.selections.count && representative.currentSelection >= 0 ) {
                    var currentSelectedItem = representative.selections.get(representative.currentSelection)
                    if (typeof currentSelectedItem.specificDetail == "string")
                    {
                        representative.text = Qt.binding(function() {return qsTrId(currentSelectedItem.specificDetail)})
                    }
                    else if (typeof currentSelectedItem.value == "string")
                    {
                        representative.text = Qt.binding(function() {return qsTrId(currentSelectedItem.value)})
                    }
                    else
                    {
                        representative.text = DelegateConstants._INVALID_TITLE
                    }
                } 
                else 
                {
                    representative.text =  DelegateConstants._INVALID_TITLE
                }
            }
            function selectionListInActive(){
                privateController.storeContentY = listSelection.contentY
            }
            function selectionListActive(){
                listSelection.contentY = privateController.storeContentY
            }
            function calculatePositionOfSelectionPopup(){
                let globalPos = representative.anchorItem.mapToItem(container,representative.anchorItem.x,0)
                if (representative.popupPlaceCentralItem){
                    selectionList.y = globalPos.y - (selectionList.height - representative.anchorItem.height) / 2
                }else{
                    selectionList.y = globalPos.y // SCO_13 USB
                    if(selectionList.height >= 352) { // SCO_13 Wifi
                        selectionList.y = 80
                        return;
                    }
                }
                if (selectionList.height >= 512 || selectionList.y < 80){
                    selectionList.y = 80
                }else if (selectionList.y + selectionList.height >= 608){
                    selectionList.y = 608 - selectionList.height
                }
            }
        }


        component Background : Item {
            id: backgroundPopup
            property string sourceImageBase: UIConstants.background_popup_list_488x528
            property int heightImageBase: 528
            property alias applyShadowEffect: imageBackground.applyShadowEffect
            QtObject {
                id: privateImage
                readonly property int radius: 8
                property string scource: backgroundPopup.sourceImageBase
                property int yClipBottom: backgroundPopup.heightImageBase - radius
            }
            CImage {
                id: imageBackground
                anchors.fill: parent
                applyShadowEffect: true
                CImage {
                    id: backgroundClipTop
                    source: privateImage.scource
                    sourceClipRect: Qt.rect(0, 0, backgroundPopup.width, backgroundPopup.height - privateImage.radius)
                }
                CImage {
                    id: backgroundClipBottom
                    anchors.top: backgroundClipTop.bottom
                    anchors.left: backgroundClipTop.left
                    source: privateImage.scource
                    sourceClipRect: Qt.rect(0, privateImage.yClipBottom, backgroundPopup.width, privateImage.radius)
                }
            }
        }

        Background {
            id: selectionList
            x: 504
            visible: false
            width: 488
            //source: privateController.background[3]
//            MouseArea {
//                anchors.fill: parent
//            }
            onVisibleChanged: {
                if(visible) listSelection.isScrollbarUsed = false
            }
            CListView{
                states:[
                    State{
                        when: representative.isObject && VehicleGeneralState.isDriving
                        PropertyChanges{ target : listSelection; interactive  : false}
                    }
                ]
                id: listSelection
                cacheBuffer: listSelection.count * 80
                width  : 460
                height : 496
                clip   : true
                x      : 16
                y      : 16
                rightMarginValue: 16
                leftMarginValue: 16
                preventShowinFirstTime: true
                property int __count: 0
                property int __height: 0
                property int realHeight: 0
                model: selections
                delegate:
                            ImageButton {
                                id: indicator
                                listContainer         : listSelection
                                indexInList           : (model?.index) ? model.index : -1
                                visible               : (model?.visible) ? model.visible : true
                                onHeightChanged       : representative.getTotalHeight(height, model.index)
                                //onVisibleChanged      : representative.onVisibleItemChanged()
                                width                 : 456
                                height                : visible ? (80 + (specificDetail.lineCount - 1) * 32) : 0
                                tonedownItem          : (model.isItemDisable === true)
                                isObject              : representative.isObject
                                onReleased: {
                                    representative.selectItem(model.index)
                                    representative.released()
                                }

                                Background {
                                    id: highLight
                                    y: 4
                                    width: 456
                                    heightImageBase: 542
                                    applyShadowEffect: false
                                    visible: indicator.pressedState
                                    sourceImageBase: UIConstants.background_popupList_pressed_456x542
                                    height: indicator.height - 10
                                }

                                Item{
                                    id: marginContainer
                                    anchors.margins: 16
                                    anchors.fill: parent
                                    CText {
                                        id: specificDetail
                                        pressedState:indicator.pressedState
                                        inActiveState:indicator.inActiveState
                                        textID: model?.specificDetail ? (model.specificDetail) : (model.value)
                                        textWidth: model?.textWidth ? model.textWidth : specificDetail.width
                                        textHeight: model?.textHeight ? model.textHeight : specificDetail.height
                                        text: model?.specificDetail ? qsTrId(model.specificDetail) : qsTrId(model.value)
                                        horizontalAlignment: Text.AlignLeft
                                        width: representative.specificDetailWidth
                                        wrapMode: Text.Wrap
                                        topPadding: 4
                                        _font: representative.contentFontSelectionsList
                                        x: privateController.titleProperty.x//56
                                        anchors.verticalCenter: parent.verticalCenter
                                    }
                                    Loader{
                                        id: selectionIndicator
                                        sourceComponent: privateController.selectionIndicator
                                        enabled: false
                                        onItemChanged: {
                                            if (item != undefined)
                                            {
                                                if (privateController.containsButtons)
                                                {
                                                    item.checked = Qt.binding(function(){return model.status})
                                                    item.toneDownCondition = Qt.binding(function(){return model.isItemDisable})
                                                }else{
                                                    item.isSelected= Qt.binding(function(){return model.index == representative.currentSelection})
                                                    item.inActiveState = Qt.binding(function(){return indicator.inActiveState})
                                                    item.indicatorY = Qt.binding(function(){return ((specificDetail.lineCount - 1) * 16)})
                                                }
                                            }
                                        }
                                    }

                                }
                                Image{
                                    anchors.bottom: parent.bottom
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    source: indicator.pressedState ? UIConstants.divider_popup_list_pressed_456x2 : UIConstants.divider_popup_list_rormal_424x2
                                }
                            }
                }
                Loader{
                    id: selectConfirmation
                    active: privateController.containsButtons
                    anchors{
                        horizontalCenter: parent.horizontalCenter
                        bottom: parent.bottom
                        bottomMargin: 20
                    }
                    onItemChanged: {
                        if (item != undefined)
                        {
                            if (typeof item.accept == "function")
                            {
                                item.accept.connect(() =>
                                    {
                                        representative.accept();
                                    }
                                )
                            }
                            if (typeof item.reject == "function")
                            {
                                item.reject.connect( () =>
                                    {
                                        representative.reject();
                                    }
                                )
                            }
                        }
                    }
                }
        }

    }
}
