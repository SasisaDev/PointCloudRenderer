#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

#include "Window/Window.h"
#include "Renderer/Renderers/OpenGLRenderer.h"
#include "Debug/Logger.h"
#include "Events/EventDispatcher.h"
#include "Renderer/Layers/LayerStack.h"
#include "Renderer/Layers/Layers/SceneLayer.h"
#include "Renderer/Layers/Layers/WidgetLayer.h"

enum AttachedLayers : uint8_t
{
	LAYER_SCENE = 1u << 0,
	LAYER_POSTPROCESS = 1u << 1,
	LAYER_WIDGET = 1u << 2
};

class Engine
{
protected:
	Window* window;
	SScene* scene = nullptr;
	LayerStack* layerStack;
	std::vector<UWidget*> widgets;
	EventDispatcher eventDispatcher;
public:
	static Engine* GEngine;

	Engine(std::string Title, int width, int height, uint8_t layers = LAYER_SCENE | LAYER_WIDGET);

	void SetWindow(Window* window);
	Window* GetWindow() { return window; }

	void SetScene(SScene* Scene);
	SScene* GetScene() { return scene; }

	void DispatchEvents(const Event& event);
	EventDispatcher* GetEventDispatcher() { return &eventDispatcher; }

	void EngineLoop(float DeltaTime);
};