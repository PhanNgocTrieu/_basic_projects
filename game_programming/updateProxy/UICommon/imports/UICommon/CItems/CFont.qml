pragma Singleton
import QtQuick 2.15
import UICommon.Base
QtObject{
    id: fontProvider

    Component.onCompleted: {
        _SUBBODY._Font.pointSize = 26
        _TITLE._Font.pointSize = 54
        _SUBTITLE._Font.pointSize = 42
        _FOOTNOTE._Font.pointSize = 22
        _ULTRASMALL._Font.pointSize = 18
        _SPECIAL_SIZE_100_140_SUBBODY._Font.pointSize = 26
        _SPECIAL_SIZE_100_140_TITLE._Font.pointSize = 54
    }

    property QtObject _SUBBODY: QtObject{
        property int lineHeight: 36
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF TazuganeInfo",
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
                family: "Suzuki_IF TazuganeInfo",
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
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 42
            }
        )
    }
    property QtObject _SUBTITLE_NUM: QtObject{
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
                family: "Suzuki_IF TazuganeInfo",
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
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 28
            }
        )
    }
    property QtObject _BODY_NUM: QtObject{
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
                family: "Suzuki_IF TazuganeInfo",
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
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 19
            }
        )
    }
    property QtObject _SPECIAL_18_24: QtObject{
        property int lineHeight: 24
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 19
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

    property QtObject _SPECIAL_SIZE_32_44: QtObject{
        property int lineHeight: 44
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 32
            }
        )
    }

    property QtObject _SPECIAL_SIZE_24_34: QtObject{
        property int lineHeight: 34
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF TazuganeInfo",
                weight: 275 ,
                pixelSize: 24
            }
        )
    }

    property QtObject _SPECIAL_SIZE_100_140_SUBBODY: QtObject{
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

    property QtObject _SPECIAL_SIZE_100_140_TITLE: QtObject{
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

    property QtObject _SPECIAL_SIZE_28_40_AUTO: QtObject{
        property int lineHeight: 40
        property int lineHeightMode: Text.FixedHeight
        property font _Font   : Qt.font(
            {
                family: "Suzuki_IF TazuganeInfo",
                weight: 400 ,
                pixelSize: 28
            }
        )
    }

    property QtObject _SPECIAL_SIZE_30_40_AUTO: QtObject{
            property int lineHeight: 40
            property int lineHeightMode: Text.FixedHeight
            property font _Font   : Qt.font(
                {
                    family: "Suzuki_IF TazuganeInfo",
                    weight: 275 ,
                    pixelSize: 30
                }
            )
        }

}
