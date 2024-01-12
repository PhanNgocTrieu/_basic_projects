import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import UICommon.Base

Item {
    id: imgAnimation    
    property var imgSrc : []
    property bool anirepeat : false
    property alias isMirror : imgAnimate.mirror
    property int intervals : 33
    signal  forwards()
    signal  backwards()
    signal  finished()
    signal  stops()

    QtObject {
        id: privateVar
        property bool isfw : false 
        property bool isbw : false
        property bool trepeat : true
        property int idx : 0
    }
    onForwards : {
        privateVar.isfw = true
        privateVar.isbw = false
        privateVar.idx = 0
        animaTimer.restart()   
    }

    onBackwards : {
        privateVar.isfw = false
        privateVar.isbw = true
        privateVar.idx = imgSrc.length - 1
        animaTimer.restart() 
    }

    onStops : {
    	animaTimer.stop()
    }   

    Timer {
        id: animaTimer        
        interval: intervals; running: false; repeat: true        
        onTriggered: {
            if (privateVar.isbw) {
                if (privateVar.idx > 1) {
                    privateVar.idx = privateVar.idx - 1
                }
                if (privateVar.idx <= 1) {  
                    finished()
                    stop()               
                    if (anirepeat) {
                        backwards()
                    }
                }
            }else if (privateVar.isfw) {
                if (privateVar.idx < imgSrc.length - 1) {
                    privateVar.idx = privateVar.idx + 1
                }
                if (privateVar.idx >= imgSrc.length - 1) {
                    finished()
                    stop()
                    if (anirepeat) {
                        forwards()
                    }
                }
            } else {

            }
        }
    }

    Image {
        id: imgAnimate
        anchors.fill: parent
        source: (privateVar.idx < imgSrc.length && privateVar.idx >= 0) ? imgSrc[privateVar.idx] : ""
        opacity: 1
        mirror: false
    }
}
