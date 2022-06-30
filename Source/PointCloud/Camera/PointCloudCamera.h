#pragma once

#include "../../Core/Camera/Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

class SPointCloudCameraActor : public SCameraActor
{
public:
	SPointCloudCameraActor(std::string name)
		: SCameraActor(name)
	{
		ActorConfig.transform.Location.z = -3;

		ActorConfig.transform.Rotation.x = 45.0f;
		//ActorConfig.transform.Rotation.y = 45.0f;
		RodDistance = 50;
	}

	float RodDistance, oldX = 0, oldY = 0;
	bool bRotateMouse = false;

	virtual CameraModel CalculateModel() override;

	virtual void Update(float dt) override;
	
	virtual void OnEvent(const Event& e) override;
};

