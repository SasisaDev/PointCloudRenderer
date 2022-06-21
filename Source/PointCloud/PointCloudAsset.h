#pragma once

#include "../Core/Object/Object.h"

#include <glm/glm.hpp>
#include <vector>

struct CloudPoint
{
	glm::vec3 position;
	glm::vec3 color;
};

class SPointCloudAsset : public SObject
{
protected:
	std::vector<CloudPoint> Points;

public:
	GENERATED_BODY(SPointCloudAsset)
};