pragma Singleton
import QtQuick

QtObject {
    id:rootItem

    property int curSeverity: 0
    property var svrDescTbl:["DBG","INF","WRN", "ERR", "FTL"];
    
    function setSeverity(severity) {
        rootItem.curSeverity = sevrity;
    }

    function log(severity, message) {
        if (severity >= rootItem.curSeverity) {
            var _svrDesc;
            var _timestamp = new Date();
            if (severity < rootItem.svrDescTbl.length) {
                _svrDesc = rootItem.svrDescTbl[severity];
            }
            else {
                _svrDesc = rootItem.svrDescTbl[0];
            }
            console.log("["+_svrDesc+"]["+_timestamp.getFullYear()
                                    +"-"+_timestamp.getMonth()
                                    +"-"+_timestamp.getDate()
                                    +" "+_timestamp.getHours()
                                    +":"+_timestamp.getMinutes()
                                    +":"+_timestamp.getSeconds()
                                    +"."+_timestamp.getMilliseconds()
                                    +"] "+message);
        }
    }

    function logDbg(message) {
        rootItem.log(0,message);
    }

    function logInf(message) {
        rootItem.log(1,message);
    }

    function logWrn(message) {
        rootItem.log(2,message);
    }

    function logErr(message) {
        rootItem.log(3,message);
    }

    function logFtl(message) {
        rootItem.log(4,message);
    }

    Component.onCompleted: {
        logDbg("Logger singleton is created");
    }
}
