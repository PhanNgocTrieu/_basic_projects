import QtQuick

Item {
    id: root

    property Item source

    property alias color: verticalBlur.color

    ShaderEffect {
        id: verticalBlur

        anchors.fill: parent

        fragmentShader: "qrc:/qt-project.org/imports/UICommon/Effects/GausianBlur.frag.qsb"
        vertexShader: "qrc:/qt-project.org/imports/UICommon/Effects/GausianBlur.vert.qsb"

        property variant source: sourceProxy;
        property real srcWidth: root.source.width + 10
        property real srcHeight: root.source.height + 10
        property int phase: 0
        property color color: "white"

        layer.enabled: true
        layer.smooth: true

        visible: false
        blending: false
    }

    ShaderEffect {
        id: horizontalBlur

        anchors.fill: parent

        fragmentShader: "qrc:/qt-project.org/imports/UICommon/Effects/GausianBlur.frag.qsb"
        vertexShader: "qrc:/qt-project.org/imports/UICommon/Effects/GausianBlur.vert.qsb"

        property variant source: verticalBlur;

        property real srcWidth: root.source.width + 10
        property real srcHeight: root.source.height + 10

        property int phase: 1
        property color color: verticalBlur.color

        visible: true
    }

    ShaderEffectSource {
        id:sourceProxy

        anchors.fill: parent

        sourceItem: root.source
        visible: true
    }
}
