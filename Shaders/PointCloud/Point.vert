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

void billboard()
{
	mat4 VP = Projection * View;       
	vec3 CameraRight = vec3(View[0][0], View[1][0], View[2][0]);
	vec3 CameraUp = vec3(View[0][1], View[1][1], View[2][1]);

	vec3 Pos = gl_Position.xyz;  // The desired point for the billboard

	vec4 v1 = VP * vec4(Pos + CameraRight * 0.5 * CameraUp * -0.5, 1.0);  
	vec4 v2 = VP * vec4(Pos + CameraRight * 0.5 * CameraUp * 0.5, 1.0);     
	vec4 v3 = VP * vec4(Pos + CameraRight * -0.5 * CameraUp * -0.5, 1.0); 
	vec4 v4 = VP * vec4(Pos + CameraRight * -0.5 * CameraUp * 0.5, 1.0);  
}

void main()
{
	uv = UV;
	fragColor = points[gl_InstanceID].color;
    gl_Position = Projection * View * vec4(aPos + points[gl_InstanceID].position, 1);
}