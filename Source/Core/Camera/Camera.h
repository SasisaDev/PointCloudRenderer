#pragma once

#include "../Scene/Actor/Actor.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct CameraModel
{
	glm::mat4 Projection;
	glm::mat4 View;
};

class SCameraActor : public SActor
{
public:
	GENERATED_ACTOR_BODY(SCameraActor)
public:
	bool bTargetCamera = false;
	glm::vec3 cameraTarget;
public:
	
	CameraModel CalculateModel();

	virtual void Update(float DeltaTime) override;
};