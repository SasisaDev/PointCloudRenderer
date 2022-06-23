#pragma once

#include "../Scene/Actor/Actor.h"
#include <glm/glm.hpp>

struct CameraModel
{
	glm::mat4 Projection;
};

class SCameraActor : public SActor
{
public:
	GENERATED_ACTOR_BODY(SCameraActor)
public:
	bool bTargetCamera = false;
	glm::vec3 cameraTarget;
public:
	
	CameraModel CalculateModel() { return CameraModel(); }
};