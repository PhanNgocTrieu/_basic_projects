#version 440
layout(location = 0) in vec4 qt_Vertex;
layout(location = 1) in vec2 qt_MultiTexCoord0;

layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
    float srcWidth;
    float srcHeight;
    int phase;
    vec4 color;
};

layout(location = 0) out vec2 texCoord;

void main() {
    gl_Position = qt_Matrix * qt_Vertex;

    texCoord = qt_MultiTexCoord0;
}
