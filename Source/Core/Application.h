#pragma once

#include "Engine.h"

class Application
{
protected:
	std::vector<Engine*> engines;
public:
	float MaxFPS = 120;

	static Application* GApplication;

	Application();
	Engine* CreateEngine(std::string Title, int width, int height, int layers = LAYER_SCENE | LAYER_WIDGET);

	void Loop();
};