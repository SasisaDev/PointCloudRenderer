#include "Engine.h"

Engine::Engine()
{
	if (!glfwInit())
	{
		throw std::exception("GLFW initialization failed");
	}
}

void Engine::SetWindow(Window* win)
{
	window = win;
}

void Engine::SetScene(SScene* scene)
{
	Scene = scene;

	if (SceneLayer* layer = layerStack->GetLayer<SceneLayer>())
	{
		layer->SetScene(scene);
	}

	Logger::Log("Loaded scene: " + scene->ObjectName);
	Logger::Log("Loaded actors: ");
	for (auto actor : scene->GetActors())
	{
		//Renderer->AddRenderObject(actor);
		std::stringstream stream;
		stream << std::dec << actor->RenderPriority;
		Logger::Log("\t" + actor->ObjectName + " (" + stream.str() + ")");
	}
	Logger::Log("Loaded Subsystems: ");
	for (auto Subsystem : scene->GetSubsystems())
	{
		Logger::Log("\t" + Subsystem->ObjectName);
	}
}

/*void Engine::AddWindow(Window* window)
{
	Windows.push_back(window); 
	window->AttachRenderer(new OpenGLRenderer(window->GetWidth(), window->GetHeight()));

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
}*/

void Engine::EngineLoop()
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

		if (SScene* scene = window->GetScene())
		{
			scene->Update(1);
		}

		Renderer->Render();
	}

	glfwSwapBuffers(window->GetHandle());
	glfwPollEvents();
}
