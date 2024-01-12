pragma Singleton
import QtQuick 2.15
QtObject{
    id: fontProvider
    property QtObject _SUBBODY: QtObject{
        property int lineHeight: 36
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 26 
            }
        )
    }
    property QtObject _TITLE: QtObject{
        property int lineHeight: 72
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 54 
            }
        )
    }
    property QtObject _SUBTITLE: QtObject{
        property int lineHeight: 60
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 42 
            }
        )
    }
    property QtObject _HEADING: QtObject{
        property int lineHeight: 52
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 36 
            }
        )
    }
    property QtObject _BODY: QtObject{
        property int lineHeight: 40
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 28 
            }
        )
    }
    property QtObject _FOOTNOTE: QtObject{
        property int lineHeight: 32
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 22 
            }
        )
    }
    property QtObject _ULTRASMALL: QtObject{
        property int lineHeight: 24
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 18.8
            }
        )
    }

    property QtObject _SPECIAL_SIZE_100_140: QtObject{
        property int lineHeight: 140
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 100 
            }
        )
    }
    property QtObject _SPECIAL_SIZE_110_140: QtObject{
        property int lineHeight: 140
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 92
            }
        )
    }

    property QtObject _SPECIAL_SIZE_62_86: QtObject{
        property int lineHeight: 86
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 62
            }
        )
    }
    property QtObject _SPECIAL_SIZE_46_64: QtObject{
        property int lineHeight: 64
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 275 ,
                pixelSize: 46
            }
        )
    }
    property QtObject _SPECIAL_SIZE_42_60: QtObject{
        property int lineHeight: 60
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF Numericfont",
                weight: 400 ,
                pixelSize: 42
            }
        )
    }

}
