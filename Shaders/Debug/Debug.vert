#version 430

layout (binding = 0) uniform SceneUniformBuffer
{
    mat4 Projection;
	mat4 View;
};

layout (location = 0) in vec3 aPos;
uniform mat4 Model;

void main()
{
    gl_Position = Projection * View * Model * vec4(aPos, 1);
}