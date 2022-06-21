#pragma once
#include "../Core/Scene/Actor/Actor.h"
#include <vulkan/vulkan.hpp>

class SPointCloudActor : public SActor
{
public:

	virtual int CreateResources() override;
	virtual int ReleaseResources() override;
	virtual int Render(VkCommandBuffer* CmdBuffer) override;
};