#pragma once

#include "Window.h"
#include "VulkanEngine/VulkanEngine.h"
#include <vector>

class Engine
{
	std::vector<Window*> windows;
	bool bShouldExit = false;

public:

	Engine();
	~Engine();

	void AddWindow(Window* window);
	void RemoveWindow(Window* window);

	void RenderLoop();
};