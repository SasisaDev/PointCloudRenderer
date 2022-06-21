#version 450
#define MAX_POINTS 1000000000

layout(location = 0) in int PointsCount;
layout(location = 1) in vec3 Points[MAX_POINTS];
layout(location = 2) in vec2 PointsColors[MAX_POINTS];

layout(location = 3) out vec3 OutPoints[MAX_POINTS];

void main() {

}