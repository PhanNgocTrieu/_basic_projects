import UICommon.CItems
import UICommon.Base
import QtQuick 2.15

CImage {
    id: rootPopupContainer
    property bool isPositionCenter: false
    property int popupBottomMargin: isPositionCenter ? (IS_SYSTEM_POPUP ? (720 - height) /2 : (720 - height) /2 - 16) : (IS_SYSTEM_POPUP ? 16 : 0)
    anchors.bottom: parent.bottom
    anchors.bottomMargin: popupBottomMargin
    anchors.horizontalCenter: parent.horizontalCenter
}
