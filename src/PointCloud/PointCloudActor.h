#pragma once
#include "../Core/Scene/Actor/Actor.h"

class SPointCloudActor : public SActor
{
public:

	virtual int CreateResources() override;
	virtual int ReleaseResources() override;
	virtual int Render(VulkanEngine* Engine) override;
};