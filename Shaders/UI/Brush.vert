#version 330

layout (binding = 1) uniform WidgetUniformBuffer
{
    mat4 Projection;
};

layout (location = 0) in vec3 Position;

void main()
{
    gl_Position = Projection * View * Model * vec4(Position, 1);
}