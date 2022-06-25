#pragma once

#include "Engine.h"

class Application
{
protected:
	std::vector<Engine*> engines;
public:
	float MaxFPS = 120;

	Application();
	Engine* CreateEngine(std::string Title, int width, int height);

	void Loop();
};

Application* GApplication = nullptr;