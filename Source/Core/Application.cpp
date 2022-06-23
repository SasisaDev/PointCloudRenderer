#include "Application.h"

Engine* Application::CreateEngine(std::string Title, int width, int height)
{
	return nullptr;
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
