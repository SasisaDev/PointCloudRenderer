#include "Engine.h"

Engine* Engine::GEngine = nullptr;

Engine::Engine()
{
	if (GEngine == nullptr)
	{
		if (!glfwInit())
		{
			throw std::exception("GLFW initialization failed");
		}

		Engine::GEngine = this;
	}
}

void Engine::EngineLoop()
{
	if (Windows.size() > 0)
	{
		while (!glfwWindowShouldClose(Windows[0]->GetHandle()))
		{


			for (auto window : Windows)
			{
				glfwSwapBuffers(window->GetHandle());
			}
			glfwPollEvents();
		}
	}
}
