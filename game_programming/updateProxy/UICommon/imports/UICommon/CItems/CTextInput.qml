import QtQuick 2.15
import UICommon.Base
TextInput {
    property string previousContent:""
    property bool isBtnPressed: false // use when just play sound from outside button
    property bool isCompleted: false // prevent play sound multitime when completing screen. Set to true
                                    // in onCompleted of screen
    focus:!APP_ENGINE.isDriving
    QtObject{
        id: privateController
        property bool soundOnWhenClicking: false
        function soundOn(){
            VehicleGeneralState.playSound(VehicleGeneralState.Touch)
        }
    }
    onTextChanged: {
        if (focus) previousContent = text
    }
    onTextEdited: {
//        privateController.soundOn()
    }
    onCursorPositionChanged: {
        if(isCompleted){
            if (!isBtnPressed && !privateController.soundOnWhenClicking) privateController.soundOn()
            privateController.soundOnWhenClicking = false
        }
    }
    onFocusChanged: {
        if (!focus){
            if (text.length>30){
                 text = ""
            }
        }else{
            text = previousContent
        }
    }
    MouseArea{
        anchors.fill: parent
        onPressed: (mouse) => {
            mouse.accepted = false
            privateController.soundOnWhenClicking = true
            privateController.soundOn()
        }
    }
}
