#pragma once
#include "../Renderer/Renderer.h"
#include <GLFW/glfw3.h>

#pragma comment(lib, "glfw3.lib")

#include <string>
#include "../Scene/Scene.h"

class Window
{
protected:
	GLFWwindow* Handle;

	IRenderer* Renderer = nullptr;
	
	SScene* Scene = nullptr;

	std::string Title;
	int Width = 0, Height = 0;
public:
	Window(std::string title, int w, int h);

	void AttachRenderer(IRenderer* renderer) { Renderer = renderer; }
	void SetScene(SScene* scene) { Scene = scene; }

	GLFWwindow* GetHandle() { return Handle; }
};