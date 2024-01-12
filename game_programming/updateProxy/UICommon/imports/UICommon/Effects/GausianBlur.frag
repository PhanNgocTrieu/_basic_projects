#version 440
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
    float srcWidth;
    float srcHeight;
    int phase;
    vec4 color;
};
layout(binding = 1) uniform sampler2D source;

layout(location = 0) in vec2 texCoord;

layout(location = 0) out vec4 fragColor;

float probeTexture(vec2 offset) {
    if ((texCoord.x + offset.x/srcWidth) < 0
        || (texCoord.x + offset.x/srcWidth) > 1
        || (texCoord.y + offset.y/srcHeight) < 0
        || (texCoord.y + offset.y/srcHeight) > 1) {
        return 0;
    }
    else {
        return texture(source,vec2(texCoord.x + offset.x/srcWidth,texCoord.y + offset.y/srcHeight)).a;
    }
}

void main() {
    float sum = texture(source, texCoord).a * 0.17524;

    if (phase == 0) {
       sum += probeTexture(vec2(0,-1)) * 0.16577;
       sum += probeTexture(vec2(0, 1)) * 0.16577;
       sum += probeTexture(vec2(0,-2)) * 0.140321;
       sum += probeTexture(vec2(0, 2)) * 0.140321;
       sum += probeTexture(vec2(0,-3)) * 0.106289;
       sum += probeTexture(vec2(0, 3)) * 0.106289;
       fragColor = vec4(0, 0, 0, clamp(sum,0.0,1.0));
    }
    else {
       sum += probeTexture(vec2(-1,0)) * 0.16577;
       sum += probeTexture(vec2(1,0)) * 0.16577;
       sum += probeTexture(vec2(-2,0)) * 0.140321;
       sum += probeTexture(vec2(2,0)) * 0.140321;
       sum += probeTexture(vec2(-3,0)) * 0.106289;
       sum += probeTexture(vec2(3,0)) * 0.106289;
       fragColor = mix(vec4(0.0), color, clamp(sum,0.0,1.0)) * qt_Opacity;
    }

}
