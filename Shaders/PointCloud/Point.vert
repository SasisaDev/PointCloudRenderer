#version 330
#define MAX_POINTS 2^32

layout (binding = 0) uniform SceneUniformBuffer
{
    mat4 Projection;
	mat4 View;
};

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 UV;
uniform mat4 Model[MAX_POINTS];
uniform vec4 Color[MAX_POINTS];

out vec4 fragColor;
in vec2 uv;

void main()
{
	uv = UV;
	fragColor = Color[gl_InstanceID];
    gl_Position = Projection * View * Model * vec4(aPos, 1);
}