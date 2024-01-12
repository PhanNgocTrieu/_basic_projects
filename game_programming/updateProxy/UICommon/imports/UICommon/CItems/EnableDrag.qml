import QtQuick 2.15
import UICommon.Base
CMouseArea {
    id: dragHandler
    objectName:"dragHandler"
    //! allows drag in the targeted item or not
    property bool isEnableDrag: true
    //! The property represents the left margin of the receiver event on the targeted item
    property int eventReceiverLeftMargin:0
    //! The property represents the right margin of the receiver event on the targeted item
    property int eventReceiverRightMargin:0
    //! The property represents the top margin of the receiver event on the targeted item
    property int eventReceiverTopMargin:0
    //! The property represents the bottom margin of the receiver event on the targeted item
    property int eventReceiverBottomMargin:0
    //! This property holds the current pressing status of the targeted item
    function restoreThePos(){
        controller.movingX = controller.initialX
        controller.movingY = controller.initialY
    }
    property int x_Offset : 0
    QtObject{
        id: controller
        property bool held: false
        // Store the position upon starting moving
        property int initialX: 0
        property int initialY: 0
        // Store the position when moving
        property int movingX:0
        property int movingY:0
        onHeldChanged:{
        // When the user released the touch or click action
        // update the position of the targeted obejct
            if (!held){
                dragHandler.parent.x = movingX
                dragHandler.parent.y = movingY
                initialX             = movingX     // store new position
                initialY             = movingY
            }
        }
        property var activePoints:[
            {"x": 0,                          "y": 0},                               // top left
            {"x": dragHandler.parent.width,   "y": 0},                               // top right
            {"x": 0,                          "y": dragHandler.parent.height},       // bottom left
            {"x": dragHandler.parent.width,   "y": dragHandler.parent.height},       // bottom right
            {"x": dragHandler.parent.width/2, "y": 0},                               // middle of top side
            {"x": dragHandler.parent.width/2, "y": dragHandler.parent.height},       // middle of bottom side
            {"x": 0,                          "y": dragHandler.parent.height/2},     // middle of left side
            {"x": dragHandler.parent.width,   "y": dragHandler.parent.height/2},     // middle of right side
        ]
        // Propagte the drop event on 4 corner point and 4 middle point
        // To detect whether a Drop happens on A droppable Item
        function activateDragPoint(){
            for (let point of activePoints){
                dragHandler.parent.Drag.active    = true
                dragHandler.parent.Drag.hotSpot.x = point.x
                dragHandler.parent.Drag.hotSpot.y = point.y
                dragHandler.parent.Drag.drop()
            }
        }
    }
    Component.onCompleted:{
         controller.movingX = controller.initialX = parent.x
         controller.movingY = controller.initialY = parent.y
         // To handle drag drop events
         // Update the storage position of X when the item is dragging
         dragHandler.parent.xChanged.connect(()=>{if (controller.held) controller.movingX = dragHandler.parent.x})
         // Update the storage position of Y when the item is dragging
         dragHandler.parent.yChanged.connect(()=>{if (controller.held) controller.movingY = dragHandler.parent.y})
         // Binding directly the Drag.source of Parent
         parent.Drag.source = Qt.binding(function(){return dragHandler.parent})
         // init the drag hotSpot X for the parent
         parent.Drag.hotSpot.x   = 0
         // init the drag hotSpot Y for the parent
         parent.Drag.hotSpot.y   = 0
    }
    //! These properties are used to determnine the position
    anchors{
          fill: parent
          leftMargin: dragHandler.eventReceiverLeftMargin
          rightMargin: dragHandler.eventReceiverRightMargin
          topMargin: dragHandler.eventReceiverTopMargin
          bottomMargin: dragHandler.eventReceiverBottomMargin
    }
    // Group of drag properties
    drag{
        target: controller.held && dragHandler.isEnableDrag ? parent : undefined
        axis: Drag.XAndYAxis
        minimumX: 0
        maximumX: root.width - analog.width + x_Offset
        minimumY: 0
        maximumY: root.height - analog.height
    }
    onPress: (mouse)=> {
        parent.Drag.active = true         // enable Drag properties on this item such as drop
        controller.held = true
    }
    onReleased: (mouse) =>  {
        controller.activateDragPoint()   // broadcasting drop event on 8 point of the item
        controller.held = false
    }
    DropArea{
        anchors.fill:parent
        onDropped:(dragItem)=>{
                      // receive the drop source item
                      // find the object called dragHandler
                      // and process - update the properties
                      let children = dragItem.source.children
                      for (let i=0;i<children.length;++i){
                          let dragController = undefined
                          if (children[i].objectName === "dragHandler"){
                              children[i].restoreThePos()
                              break;
                          }
                      }
                  }
    }
}

