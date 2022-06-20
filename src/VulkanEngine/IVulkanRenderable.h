#pragma once

class VulkanEngine;

class IVulkanRenderable
{
public:

	virtual int CreateResources() { return 0; }
	virtual int ReleaseResources() { return 0; }
	virtual int Render(VulkanEngine* Engine) { return 0; }
};