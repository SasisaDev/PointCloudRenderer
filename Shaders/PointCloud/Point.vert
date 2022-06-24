#version 430

layout (std430, binding = 0) uniform SceneUniformBuffer
{
    mat4 Projection;
	mat4 View;
};

layout (location = 0) in vec3 aPos;
layout (location = 1) in uniform mat4 model;

void main()
{
	gl_Position = SceneUniformBuffer.Projection * SceneUniformBuffer.View * model vec4(aPos, 1.0);
}