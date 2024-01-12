import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import UICommon.Base
import UICommon.CItems
import UICommon.Models 1.0

Item {
    id: root
    width: 1008
    height: 80

    property ListModel modelName: modelList
    property var headerModel : titleModel

    property double opacityBackButton: 1
    property bool isShowIcon: true
    property bool isPopupOpened: false
    property bool acceptDrivingConstraint: false
    property bool isAppliedDrivingRestrictionOnIcon: true
    property bool isObject: false
    property int yArrowIcon: -1
    property int headerIconLeftMargin: 3
    property int headerTextLeftMargin: 0
    property int headerArrowLeftMargin: 8
    property bool lineVisible: true
    property bool isCheckApplyDrivingCtrl: false

    property var fontText: CFont._BODY

    property alias containerWidth: itemContainer.width
    property alias containerHeight: itemContainer.height
    property alias itemSpacing: rowContainer.spacing
    property alias maxWidth: titleModel.maxWidth

    property int separatorWidth: 32
    property int separatorHeight: 32

    property string separatorSource: "qrc:/qt-project.org/imports/UICommon/Resources/arrow_right.png"
    property string backButtonNormalSource: "qrc:/qt-project.org/imports/UICommon/Resources/back_button_normal.png"
    property string backButtonPressedSource: "qrc:/qt-project.org/imports/UICommon/Resources/back_button_pressed.png"
    property string headerDividerSource: "qrc:/qt-project.org/imports/UICommon/Resources/header_divider.png"
    property string headerIconSource: "qrc:/qt-project.org/imports/UICommon/Resources/header_icon.png"

    signal backButtonClicked()

    TitleModel{
        id: titleModel
        font: fontText._Font
    }

    ListModel {
        id: modelList
    }

    Connections {
        target: modelName
        function onCountChanged(){
            titleModel.clear()
            for(var i = 0; i < modelName.count; i++){
                titleModel.append({name : modelName.get(i).name})
            }
        }
    }

    MouseArea {
        anchors.fill: parent
    }

    RowLayout {
        id: rowlayout
        Layout.fillWidth: true
        Layout.fillHeight: true
        Rectangle{
            id: backButton
            opacity: root.isPopupOpened ? 0.5 : 1
            Layout.alignment: Qt.AlignBottom
            Layout.bottomMargin: 0
            width: 80
            height: 80
            color: "transparent"
            Layout.leftMargin: (2 * 8)
            Image {
                anchors.fill: parent
                source: backButtonMouse.isValidEvent ? root.backButtonPressedSource : root.backButtonNormalSource
                CMouseArea {
                    id: backButtonMouse
                    enabled: !root.isPopupOpened
                    anchors.fill: parent
                    isObject: root.isObject
                    onReleased: {
                        if(isValidEvent)root.backButtonClicked();
                    }
                }
            }
        }

        CItem {
            id: headerIcon
            Layout.alignment: Qt.AlignBottom
            Layout.bottomMargin: 6
            Layout.leftMargin: root.headerIconLeftMargin
            width: (isShowIcon ? 56 : 0)
            height: (isShowIcon ? 56 : 0)
            isAppliedDrivingRestriction: root.isAppliedDrivingRestrictionOnIcon
            tonedownCondition: root.acceptDrivingConstraint
            visible: isShowIcon
            Image {
                anchors.fill: parent
                source: root.headerIconSource
            }
        }

        CItem {
            id: itemContainer
            width: 848
            height: 80
            Layout.leftMargin: 3
            Row {
                id: rowContainer
                spacing: 8
                anchors {
                    bottom: parent.bottom
                    bottomMargin: 15
                }

                Repeater {
                    id: repeaterContainer
                    model: headerModel
                    CRectangle {
                        id: rectt
                        width: model.visible ? (!model.isseparator ? textWraper.width : linkArrowIcon.width) : 0
                        height: 36
                        visible: model.visible
                        color: "transparent"

                        CRectangle {
                            id: textWraper
                            isAppliedDrivingRestriction: root.isAppliedDrivingRestrictionOnIcon
                            tonedownCondition: root.acceptDrivingConstraint
                            anchors.left: parent.left
                            anchors.leftMargin: root.headerTextLeftMargin
                            width: txtInfo.contentWidth
                            height: 36
                            color: "transparent"
                            anchors.verticalCenter: parent.verticalCenter
                            visible: !model.isseparator
                            CText {
                                id : txtInfo
                                width: model.width
                                height: 36
                                color: "white"
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                TextMetrics {
                                    id: textMetrics
                                    text: model.isseparator ? "" : qsTrId(model.label)
                                    elideWidth: model.width
                                    elide: model.flag === 1 ? Text.ElideRight : Text.ElideNone

                                    font {
                                        family: txtInfo.font.family
                                        pixelSize: txtInfo.font.pixelSize
                                        weight: txtInfo.font.weight
                                    }
                                }
                                text: textMetrics.elidedText.replace(/…$/,"...")
                                _font: fontText
                            }
                        }

                        CRectangle{
                            id: linkArrowIcon
                            isAppliedDrivingRestriction: root.isAppliedDrivingRestrictionOnIcon && !root.isCheckApplyDrivingCtrl
                            tonedownCondition: root.acceptDrivingConstraint && !root.isCheckApplyDrivingCtrl
                            color: "transparent"
                            visible:model.isseparator
                            anchors.verticalCenter: textWraper.verticalCenter
                            anchors.left: textWraper.right
                            width: separatorWidth
                            height: separatorHeight
                            Image {
                                y: root.yArrowIcon
                                source: root.separatorSource
                            }
                        }
                    }
                }
            }
        }
    }

    Image{
        width: 976
        height: 2
        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
        source: root.headerDividerSource
        visible: lineVisible

    }
}
