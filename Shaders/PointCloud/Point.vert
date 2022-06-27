#version 330
#define MAX_POINTS 2^32-1

layout (binding = 0) uniform SceneUniformBuffer
{
    mat4 Projection;
	mat4 View;
};

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 UV;

struct CloudPoint {
	vec3 position;
	vec4 color;
};

layout(std430, binding = 3) buffer PointCloudSSBO
{
    CloudPoint points[];
};

out vec4 fragColor;
out vec2 uv;

mat4 billboard()
{
	mat4 ModelView = View;

	ModelView[0][0] = 1;
	ModelView[0][1] = 0;
	ModelView[0][2] = 0;

	ModelView[1][0] = 0;
	ModelView[1][1] = 1;
	ModelView[1][2] = 0;

	ModelView[2][0] = 0;
	ModelView[2][1] = 0;
	ModelView[2][2] = 1;
	
	return ModelView;
}

void main()
{
	uv = UV;
	fragColor = points[gl_InstanceID].color;
    gl_Position = Projection * billboard() * vec4(aPos + points[gl_InstanceID].position, 1);
}