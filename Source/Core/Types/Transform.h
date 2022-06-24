#pragma once

#include <glm/glm.hpp>


struct Transform
{
	glm::vec3 Location;
	glm::vec3 Rotation;
	glm::vec3 Scale;

	Transform() : Location(0), Rotation(0), Scale(1){}
};

struct Transform2D
{
	unsigned int x, y, cx, cy;
};