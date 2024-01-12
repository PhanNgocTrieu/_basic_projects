import QtQuick

Item {
    id:rootItem
    required property variant source
    required property variant maskSource
    ShaderEffectSource {
        id:maskTexture
        width: maskSource.width
        height: maskSource.height
        sourceItem: maskSource
        visible:false
    }
    ShaderEffect {
        id:shaderItem
        property variant source: rootItem.source
        property variant maskSource:maskTexture
        width : maskSource.width
        height: maskSource.height
        fragmentShader: "maskeffect.frag.qsb"
        vertexShader: "maskeffect.vert.qsb"
    }
}
