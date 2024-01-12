import QtQuick
OpacityMask{
    id: mask
    property rect section
    function requestDraw(){
        controller.painter = controller.draw
        canvas.getContext("2d").clearRect(0,0,mask.width,mask.height)
        canvas.requestPaint();
    }
    function restore(){
        controller.painter = controller.restore
        canvas.getContext("2d").clearRect(0,0,mask.width,mask.height)
        canvas.requestPaint();
    }
    QtObject{   
        id: controller
        property var painter: controller.restore
        function draw(ctx){
            ctx.fillRect(0,0,mask.section.x,canvas.height)
            ctx.fillRect(0,0,canvas.width,mask.section.y)
            ctx.fillRect(0,mask.section.y + mask.section.height,canvas.width,canvas.height - mask.section.y - mask.section.height)
            ctx.fillRect(mask.section.width + mask.section.x , 0 , canvas.width - mask.section.width - mask.section.x , canvas.height)
        }
        function restore(ctx){
            ctx.beginPath()
            ctx.moveTo(0,0)
            ctx.lineTo(mask.width,0)
            ctx.lineTo(mask.width,mask.height)
            ctx.lineTo(0,mask.height)
            ctx.lineTo(0,0)
            ctx.fill()
        }
    }
    maskSource: Item{
        width: mask.width
        height: mask.height
        Canvas{
            id: canvas
            anchors.fill: parent
            onPaint:{
                let ctx = getContext("2d")
                ctx.fillStyle = "black"
                controller.painter(ctx)
            }
        }
    }
}