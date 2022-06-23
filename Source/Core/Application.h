#pragma once

#include "Engine.h"

class Application
{
protected:
	std::vector<Engine*> engines;
public:

	Engine* CreateEngine(std::string Title, int width, int height);

	void Loop();
};