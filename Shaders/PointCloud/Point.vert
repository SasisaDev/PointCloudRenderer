#version 330
#define MAX_POINTS 2^32-1

layout (binding = 0) uniform SceneUniformBuffer
{
    mat4 Projection;
	mat4 View;
};

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 UV;

layout(std430, binding = 3) buffer PointCloudSSBO
{
    vec3 Positions[];
	vec4 Colors[];
};

out vec4 fragColor;
out vec2 uv;

void main()
{
	uv = UV;
	fragColor = Colors[gl_InstanceID];
    gl_Position = Projection * View * vec4(aPos + Positions[gl_InstanceID], 1);
}