#version 330

layout (binding = 1) uniform WidgetUniformBuffer
{
    mat4 Projection;
};

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 UV;

layout(std430, binding = 3) buffer BrushSSBO
{
    vec4 Tint;
    mat4 Model;
};

out vec2 fragUV;

void main()
{
    //fragUV = UV;

    gl_Position = Projection * Model * vec4(Position, 1);
}