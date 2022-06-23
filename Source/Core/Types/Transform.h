#pragma once

#include <glm/glm.hpp>


struct Transform
{
	glm::vec3 Location;
	glm::vec3 Rotation;
	glm::vec3 Scale;

	Transform(){}
};

struct Transform2D
{
	unsigned int x, y, cx, cy;
};