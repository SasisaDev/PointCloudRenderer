#include "Application.h"

Application* Application::GApplication = nullptr;

Application::Application()
{
	if (GApplication == nullptr)
	{
		GApplication = this;
	}

	if (!glfwInit())
	{
		throw std::exception("GLFW initialization failed");
	}
}

Engine* Application::CreateEngine(std::string Title, int width, int height, int layers)
{
	Engine* engine = new Engine(Title, width, height, layers);
	glfwMakeContextCurrent(engine->GetWindow()->GetHandle());
	engines.push_back(engine);

	return engine;
}

void Application::Loop()
{
	clock_t begin_time = clock();
	float dt = 0;
	while (!glfwWindowShouldClose(engines[0]->GetWindow()->GetHandle()))
	{
		clock_t elapsed_time = clock();
		dt = elapsed_time - begin_time;
		if (dt >= 1000 / MaxFPS)
		{
			begin_time = elapsed_time;

			for (auto engine : engines)
			{
				if (glfwWindowShouldClose(engine->GetWindow()->GetHandle()))
				{
					// Remove engine
				}
				else
				{
					engine->EngineLoop(dt);
				}
			}
		}
	}
}
