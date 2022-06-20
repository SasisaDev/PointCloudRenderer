#pragma once

#include "Window.h"
#include "VulkanEngine/VulkanEngine.h"
#include "Core/Scene/Scene.h"
#include <vector>

class Engine
{
	std::vector<Window*> windows;
	bool bShouldExit = false;

	SScene* CurrentScene;

public:

	Engine();
	~Engine();

	void AddWindow(Window* window);
	void RemoveWindow(Window* window);

	void LoadScene(SScene* Scene);

	void RenderLoop();
};