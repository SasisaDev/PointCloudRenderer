#version 430

layout (std430, binding = 0) uniform SceneUniformBuffer
{
    mat4 Projection;
	mat4 View;
	vec3 CamPosition;
	vec3 CamRotation;
};

layout (location = 0) in vec3 aPos;
layout (location = 1) in uniform mat4 model;

void main()
{
	gl_Position = projection * view * vec4(aPos, 1.0);
}