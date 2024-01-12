import QtQuick
import UICommon.Base
Text {
    id: root
    property int _size_of_text: UIConstants._FONT_SIZE_28
    property int _line_height: UIConstants._POPUP_MSG_LINE_HEIGHT_36
    lineHeightMode: Text.FixedHeight
    lineHeight: root._line_height
    font{
        family: UIConstants._FONT_FAMILY_SUZUKI
        pixelSize: root._size_of_text
        weight: UIConstants._FONT_WEIGHT  
    }
}
