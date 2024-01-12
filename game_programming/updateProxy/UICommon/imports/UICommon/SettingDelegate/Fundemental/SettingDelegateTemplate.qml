import QtQuick
import UICommon.CItems
import UICommon.Base

ImageButton{
    id: indicator
    property int dividerWidth: 912
    property int textLeftMargin: 16
    property int textTopPadding: 0
    property int dividerLeftMargin: 16
    property var elideType: Text.ElideNone
    property int delegateWidth: 944
    property bool deactiveText : false

    /**
      * @brief With highlightBackgroundType, you can choose the type size of the highlight background when pressing the button.
      *        While choosing the type, it also modifies it's button holder size and divider size. Please read the code below for more informations.
      */
    property int highlightBackgroundType: 0

    /**
      * @brief With Selection popup, it comes up with many selections which allow user to
      *        choose. This variable is a set of selections
      */
    property bool hasUsageOfCurrentItem: false
    /**
      * @brief This is a setting is a solution for the usage inside a generator (Repeator, ListView,...)
      *        Apply to this property means this Delegate is used inside a generator
      */
    property var setting: undefined
    /**
      * @brief This Index acts as if the current highlight index in setting list
      *        For some delegates like SelectionPopup requires a highlight effect on its body and tonedown others
      *        This property will be used to determine whether this delegate should be highlighted
      */
    property int currentIndexInSetting: -1
    /**
      * @brief This property represents for the index of the item inside a setting list
      *        It could be declared inside a ListView, Repeater,... and has the default index (Index passed into each component)
      *        Or It is the order where Each specific Item is intr  oduced
      *        For example:
      *                   NavigateDelegate       -> will have the index of 0
      *                   SelectionDelegate      -> will have the index of 1
      */
    property int index: -1
    /**
      * @brief This property is considers as the handler for requesting changing the current seletected index
      *
      */
    property var modifyCurrentIndex
    /**
      * @brief This signal will propagated for the delegate which inherits from this delegateTemplate
      *        to apply appropriate actions based on the passed in settings
      */
    signal settingApply()
    /**
      * @brief When The delegate is used inside a generator. This function will be used to apply predefined - setting
      */
    function applySetting(stg){
        if (stg == undefined) return
        indicator.setting = stg
        indicator.title    = Qt.binding(function() {return stg.title})//qsTrId(stg.title)
        if (typeof stg.visible != "undefined")
        {
            indicator.visible  = Qt.binding(function() {return stg.visible})
        }
        else
        {
            indicator.visible  = Qt.binding(function() {return stg.available})
        }
        if (typeof stg.tonedownItem != "undefined") indicator.tonedownItem  = Qt.binding(function() {return stg.tonedownItem})
        if (typeof stg.enabled != "undefined") indicator.enabled = Qt.binding(function() {return stg.enabled})
        indicator.settingApply()
    }

    /**
      * @brief For A delegate that has the requirement for highlighting when selected (SelectionPopup, ...)
      *        When the item is Released out, we send the request to the root Container for setting the new current index
      */
    onReleased:{
        if (modifyCurrentIndex != undefined)
        {
            if (hasUsageOfCurrentItem) modifyCurrentIndex(index)
        }
    }
//    width                 : UIConstants.highlightHolderSize[indicator.highlightBackgroundType]["width"]
//    height                : visible ? UIConstants.highlightHolderSize[indicator.highlightBackgroundType]["height"] : 0

    property int defaultHeight: 80
    property int defaultWidth: 944
    property int defaultHighLighHeight: 74
    property int defaultHighLighWidth: defaultWidth
    property int highLightTopMargin: 4

    QtObject {
        id: privateController
        property int plusHeight: 0
        property var listLineCount:[]
    }

    function addLineCountElement(lineCount, value) {
        privateController.listLineCount.push({"lineCount": lineCount, "value": value})
        let index = privateController.listLineCount.length - 1
        calculationHeightElement(index, lineCount);
        return index
    }

    function calculationHeightElement(index, linecount){
        if (privateController.listLineCount.length == 0 && index === -1) {
            return
        }

        privateController.listLineCount[index].lineCount = linecount

        let _maxHeight = (privateController.listLineCount[0].lineCount - 1) * privateController.listLineCount[0].value
        let _currentHeight = 0
        for (var i = 1; i < privateController.listLineCount.length; ++i) {
            _currentHeight = (privateController.listLineCount[i].lineCount - 1) * privateController.listLineCount[i].value
            if(_currentHeight > _maxHeight) {
                _maxHeight = _currentHeight
            }
        }
        privateController.plusHeight = _maxHeight
    }

    width           : defaultWidth
    height          : visible ? defaultHeight + privateController.plusHeight : 0

    widthImage      : defaultHighLighWidth
    heightImage     : defaultHighLighHeight + privateController.plusHeight
    x               : 0
    highLightY      : 2
    disableUserEvent: disableActions
    pressedSource   : UIConstants.background_item_pressed_container[indicator.highlightBackgroundType]
    /**
      * @brief This will be used to enable or disable item when other selected
      */
    property bool disableActions: ((currentIndexInSetting != -1 && currentIndexInSetting != index) || inActiveState)
    property var titleFont: CFont._BODY
    property int textWidth: 912
    property int textHeight: 40
    property string sourceDividerNormal: UIConstants.divider_normal_container[indicator.highlightBackgroundType]["normal"]
    property string sourceDividerPressed: UIConstants.divider_pressed_container[indicator.highlightBackgroundType]["pressed"]
    property string title : "UNKNOWN"

    onDisableActionsChanged:{
        for (let child in indicator){
            if (indicator[child]?.disableActions){
                indicator[child].disableActions = disableActions
            }
        }
    }
    CText {
        id: title
        property int textId: -1
        Component.onCompleted:  {
            textId = indicator.addLineCountElement(lineCount, 40)
        }
        onLineCountChanged: indicator.calculationHeightElement(textId, lineCount)
        pressedState: indicator.pressedState
        inActiveState: indicator.disableActions
        width: indicator.textWidth
        height: indicator.textHeight
        _font: indicator.titleFont
        verticalAlignment: Text.AlignVCenter
        anchors {
            left: parent.left;
            leftMargin: indicator.textLeftMargin
            verticalCenter: parent.verticalCenter
        }
        wrapMode: Text.Wrap
        visible: !deactiveText
        textID: indicator.title
        text: qsTrId(indicator.title)
        elide: indicator.elideType
    }

    property int dividerBottomMargin: 0

    CImage {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: dividerBottomMargin
        anchors.horizontalCenter: parent.horizontalCenter
        source: pressedState ? sourceDividerPressed : sourceDividerNormal
    }

    //start overflow
    onVisibleChanged: {
        if(DelegateConstants._UI_COMMUNICATION.overFlowRequest() && !indicator.visible){
            indicator.visible = true
        }
    }
    //end overflow
}
