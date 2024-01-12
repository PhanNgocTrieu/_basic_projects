import QtQuick
/*!
    This item is will be used as a Popup
*/
Item{
    id: rootPopupContainer
    anchors.fill:parent
    property bool isDisableBackground   : false
    property bool activeMask            : true
    property bool isModal               : true
    property bool animateapperance      : true
    Rectangle{
        visible: isDisableBackground
        width: 1280
        height: 720
        color: "black"
        MouseArea{
            anchors.fill:parent
            onClicked:{
            }
        }
    }
    Component.onCompleted:{
        if (IS_SYSTEM_POPUP){
            rootSystemPopup.activeMaskScreen = Qt.binding(function(){return activeMask})
            rootSystemPopup.isModal = Qt.binding(function(){return isModal})
        }
        if (animateapperance) animation.start()
    }
    ParallelAnimation{
        id: animation
        NumberAnimation{
            target      : rootPopupContainer
            property    :"opacity"
            from        : 0
            to          : 1
            duration    : 200
            easing.type : Easing.InCubic
        }
        NumberAnimation{
            target      : rootPopupContainer
            property    :"scale"
            from        : 0.9
            to          : 1
            duration    : 200
            easing.type : Easing.InCubic
        }
    }
}
