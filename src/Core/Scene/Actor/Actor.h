#pragma once

#include "../../../VulkanEngine/IVulkanRenderable.h"
#include "../../Object.h"

class SActor : public SObject, public IVulkanRenderable
{

public:

	virtual int CreateResources() override { return 0; }
	virtual int ReleaseResources() override { return 0; }
	virtual int Render(VkCommandBuffer* Buffer) override;
};