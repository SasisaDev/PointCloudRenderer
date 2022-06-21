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

void Engine::AddWindow(Window* window)
{
	Windows.push_back(window); 
	window->AttachRenderer(new OpenGLRenderer());

	Logger::Log("New window created: " + window->GetTitle());
}

void Engine::RemoveWindow(Window* window)
{
	std::vector<Window*> newWins;
	for (auto win : Windows)
	{
		if (win != window)
		{
			newWins.push_back(win);
		}
		else
		{
			glfwDestroyWindow(win->GetHandle());
			Logger::Log("Window destroyed: " + window->GetTitle());
			delete win;
		}
	}
	Windows = newWins;
}

void Engine::EngineLoop()
{
	if (Windows.size() > 0)
	{
		while (!glfwWindowShouldClose(Windows[0]->GetHandle()))
		{
			for (auto window : Windows)
			{
				if (glfwWindowShouldClose(window->GetHandle()))
				{
					RemoveWindow(window);
				}
				else
				{
					glfwMakeContextCurrent(window->GetHandle());

					glClearColor(0.075f, 0.075f, 0.075f, 1);
					glClear(GL_COLOR_BUFFER_BIT);

					if (IRenderer* Renderer = window->GetRenderer())
					{
						if (Renderer->ShouldResize)
						{
							glViewport(0, 0, Renderer->GetCnavasWidth(), Renderer->GetCnavasHeight());
							Renderer->ShouldResize = false;
						}

						Renderer->Render();
					}

					glfwSwapBuffers(window->GetHandle());
					glfwPollEvents();
				}
			}
		}
	}
}
