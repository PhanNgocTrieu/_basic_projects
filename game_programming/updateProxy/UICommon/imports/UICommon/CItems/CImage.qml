import QtQuick
import QtQuick.Controls
import UICommon.Effects
import UICommon.Base

Image {
    id : imageItem
    // This property defines the image radius border
    property bool applyShadowEffect: false

    QtObject{
        id: privateCtl
        property Component effector: Component{
            RectangleGlow {
                property var sibling
                visible: imageItem.visible
                anchors.fill: sibling
                z: sibling.z - 1
                glowRadius: 40//root.glowRadius
                spread: 0.2
                color: Qt.rgba(0,0,0,0.5)
                cornerRadius: 28 
            }
        }
        property var effectInstance: undefined
    }
    Component.onCompleted: {
        if (applyShadowEffect){
            privateCtl.effectInstance = privateCtl.effector.createObject(imageItem.parent, {sibling: imageItem})
        }
    }
    Component.onDestruction:{
        if (privateCtl.effectInstance){
            privateCtl.effectInstance.destroy()
        }
    }
    property int radiusImg: 0
    layer.enabled: radiusImg > 0
    layer.effect: OpacityMask {
        maskSource: Rectangle {
            width:  imageItem.width
            height: imageItem.height
            radius: imageItem.radiusImg
            visible: false
        }
    }
}
