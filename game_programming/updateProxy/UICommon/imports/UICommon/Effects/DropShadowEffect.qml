import QtQuick

Item {
    id:rootItem

    property variant source:dummy;
    property vector2d blurPoint0:Qt.vector2d(0,0.8)
    property vector2d blurPoint1:Qt.vector2d(0.13,0.2)
    property vector2d blurPoint2:Qt.vector2d(0.24,0)
    property vector2d blurPoint3:Qt.vector2d(1.0,0.0)

    Rectangle {
        id:maskPattern
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 1-rootItem.blurPoint3.x; color.a: rootItem.blurPoint3.y}
            GradientStop { position: 1-rootItem.blurPoint2.x; color.a: rootItem.blurPoint2.y}
            GradientStop { position: 1-rootItem.blurPoint1.x; color.a: rootItem.blurPoint1.y}
            GradientStop { position: 1-rootItem.blurPoint0.x; color.a: rootItem.blurPoint0.y}
        }
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

        transform: [Scale { origin.y:shaderItem.height-1; yScale: -1.0},
                    Translate {
                        y:-shaderItem.height+1
                    }]
    }
}
