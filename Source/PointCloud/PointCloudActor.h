#pragma once

#include "../Core/Scene/Actor/Actor.h"
#include <GL/glew.h>

#include "PointCloudAsset.h"

class SPointCloudActor : public SActor
{
public:
	GENERATED_ACTOR_BODY(SPointCloudActor)
	{}

	SPointCloudAsset* PointCloud;

	virtual int Render() override;
};