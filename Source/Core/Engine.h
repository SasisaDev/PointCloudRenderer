#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

#include "Window/Window.h"
#include "Renderer/Renderers/OpenGLRenderer.h"
#include "Debug/Logger.h"
#include "Renderer/Layers/LayerStack.h"
#include "Renderer/Layers/Layers/SceneLayer.h"

class Engine
{
protected:
	Window* window;
	SScene* Scene = nullptr;
	LayerStack* layerStack;
public:
	Engine();

	void SetWindow(Window* window);
	Window* GetWindow() { return window; }

	void SetScene(SScene* scene);
	SScene* GetScene() { return Scene; }

	void EngineLoop();
};