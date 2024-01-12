import QtQuick 2.0

Item {
    width: HMI_SCREEN_WIDTH
    height: HMI_SCREEEN_HEIGHT

    property var screen_layer_base: screen_layer_1
    readonly property int _ANI_DURATION: 1000
    property bool isFirst: true

    Loader {
        id: screen_layer_1
        width: HMI_SCREEN_WIDTH
        height: HMI_SCREEEN_HEIGHT
        onLoaded: {
            if(isFirst) { isFirst = false; switch_screen_layer_base( screen_layer_2, screen_layer_1 ) }
            else { screen_layer_1_ani.start();}
        }
    }

    NumberAnimation {
        id: screen_layer_1_ani
        alwaysRunToEnd: true
        target: screen_layer_1
        property: "x"
        from: -HMI_SCREEN_WIDTH
        to: 0
        duration: _ANI_DURATION
        easing.type: Easing.OutCubic
        onStopped: { switch_screen_layer_base( screen_layer_2, screen_layer_1 ); }
    }

    Loader {
        id: screen_layer_2
        width: HMI_SCREEN_WIDTH
        height: HMI_SCREEEN_HEIGHT
        onLoaded: {
            if(isFirst) { isFirst = false; switch_screen_layer_base( screen_layer_1, screen_layer_2 ) }
            else { screen_layer_2_ani.start();}
        }
    }

    NumberAnimation {
        id: screen_layer_2_ani
        alwaysRunToEnd: true
        target: screen_layer_2
        property: "x"
        from: -HMI_SCREEN_WIDTH
        to: 0
        duration: _ANI_DURATION
        easing.type: Easing.OutCubic
        onStopped: { switch_screen_layer_base( screen_layer_1, screen_layer_2 ); }
    }


    function switch_screen_layer_base(from, to) {
        if ( from.item !== null ) { from.item.visible = false; from.sourceComponent = null }
        if ( to.item !== null ) { to.item.visible = true }
        screen_layer_base = from; from.z = 1; to.z = 0; from.enabled = false; to.enabled = true
    }

    function screen_Transition() {
        screen_layer_base.sourceComponent = null
        screen_layer_base.sourceComponent = HMIScreen
    }

    ListModel { id: onsDataList }
    Repeater {
        id:ons_Creator
        model: onsDataList
        anchors.left: parent.left;
        Loader {
            id: osd_Loader
            width: HMI_SCREEN_WIDTH
            height: HMI_SCREEEN_HEIGHT
            source: osdSource
        }
    }

    function load_Popup(Onsdata, popCount) {
        onsDataList.clear()
        for(var onsCnt = 0; onsCnt < popCount; onsCnt++ ) { var data = {'osdSource': Onsdata[onsCnt]}; onsDataList.append(data) }
    }
}
