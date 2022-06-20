#pragma once

#include <string>

#include "VulkanEngine/VulkanEngine.h"

#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.lib")

typedef std::string String;

class Window
{
protected:
	VulkanEngine* Engine;
	GLFWwindow* Handle;
public:

	Window(String title, int width, int height);
	~Window();

	GLFWwindow* GetWindow() { return Handle; }
	VulkanEngine* GetEngine() { return Engine; }

	int Render();
};