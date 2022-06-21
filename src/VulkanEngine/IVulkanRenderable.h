#pragma once

#include <vulkan/vulkan.hpp>

class IVulkanRenderable
{
public:

	virtual int CreateResources() { return 0; }
	virtual int ReleaseResources() { return 0; }
	virtual int Render(VkCommandBuffer* CmdBuffer) { return 0; }
};