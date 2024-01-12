import UICommon.Base
import QtQuick
ListModel{
    id: model
    property var registerPros:["visible"]
    property var trackingPros:{
        "255" : {}
    }
    onTrackingProsChanged:{
        for (let indexItem of Object.keys(trackingPros)){
            if (indexItem == 255) return
            for (let idx = 0 ; idx < registerPros.length ; ++idx){
                model.get(indexItem)[registerPros[idx]] = trackingPros[indexItem][registerPros[idx]]
            }
        }
    }
}