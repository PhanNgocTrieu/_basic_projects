import QtQuick

Item {
    id:rootItem
    property variant source:dummy
    property int radius:100
    width:radius*2
    height:radius*2

    Rectangle {
        id:maskPattern
        anchors.fill: parent
        radius:rootItem.radius
        color:"black"
        visible:false
    }

    ShaderEffectSource {
        id:maskTexture
        anchors.fill: parent
        sourceItem: maskPattern
        visible:false
    }

    ShaderEffect {
        id:shaderItem
        property variant source: rootItem.source
        property variant maskSource:maskTexture
        anchors.fill: parent
        fragmentShader: "maskeffect.frag.qsb"
        vertexShader: "maskeffect.vert.qsb"
    }
}
