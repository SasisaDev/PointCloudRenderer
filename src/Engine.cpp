#include "Engine.h"

Engine::Engine()
{
	if (!glfwInit())
	{
		exit(-1);
	}
}

Engine::~Engine()
{
	glfwTerminate();
}

void Engine::AddWindow(Window* window)
{
	for (auto win : windows)
	{
		if (win == window)
		{
			return;
		}
	}

	windows.push_back(window);
}

void Engine::RemoveWindow(Window* window)
{
	std::vector<Window*> newWindows;

	for (auto win : windows)
	{
		if (win != window)
		{
			newWindows.push_back(win);
		}
	}

	windows = newWindows;
}

void Engine::RenderLoop()
{
	while (!bShouldExit && (windows.size() > 0) ? !glfwWindowShouldClose(windows[0]->GetWindow()) : true)
	{
		for (auto window : windows)
		{
			glfwMakeContextCurrent(window->GetWindow());
			window->Render();
			glfwSwapBuffers(window->GetWindow());
		}

		glfwPollEvents();
	}
}
