#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

#include "Window/Window.h"
#include "Renderer/Renderers/OpenGLRenderer.h"
#include "Debug/Logger.h"

class Engine
{
protected:
	std::vector<Window*> Windows;
public:
	Engine();
	static Engine* GEngine;

	void AddWindow(Window* window);
	void RemoveWindow(Window* window);

	void EngineLoop();
};