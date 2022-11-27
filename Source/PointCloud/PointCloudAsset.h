#pragma once

#include "../Core/Object/Object.h"

#include <glm/glm.hpp>
#include <vector>

struct CloudPoint
{
	glm::vec3 position;
	glm::vec3 color;

	CloudPoint(glm::vec3 pos, glm::vec3 col) {
		position = pos;
		color = col;
	}
};

class SPointCloudAsset : public SObject
{
protected:
	std::vector<CloudPoint> Points;

public:
	GENERATED_BODY(SPointCloudAsset)
public:

	std::vector<CloudPoint> GetPoints() const { return Points; }
	void SetPoints(std::vector<CloudPoint> points) { Points = points; }
};