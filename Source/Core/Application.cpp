#include "Application.h"

Application::Application()
{
	if (!glfwInit())
	{
		throw std::exception("GLFW initialization failed");
	}
}

Engine* Application::CreateEngine(std::string Title, int width, int height)
{
	Engine* engine = new Engine(Title, width, height);
	glfwMakeContextCurrent(engine->GetWindow()->GetHandle());
	engines.push_back(engine);

	return engine;
}

void Application::Loop()
{
	while (!glfwWindowShouldClose(engines[0]->GetWindow()->GetHandle()))
	{
		for (auto engine : engines)
		{
			if (glfwWindowShouldClose(engine->GetWindow()->GetHandle()))
			{
				// Remove engine
			}
			else
			{
				engine->EngineLoop();
			}
		}
	}
}
