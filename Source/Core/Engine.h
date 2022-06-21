#pragma once
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

	void AddWindow(Window* window) { Windows.push_back(window); window->AttachRenderer(new OpenGLRenderer()); }

	void EngineLoop();
};