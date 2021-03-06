#include "Engine.h"

Engine* Engine::GEngine = nullptr;

Engine::Engine(std::string Title, int width, int height, uint8_t layers)
{
	window = new Window(Title, width, height);
	window->AttachEventDispatcher(&eventDispatcher);

	layerStack = new LayerStack(width, height);

	if ((layers & LAYER_SCENE) == LAYER_SCENE)
	{
		layerStack->AddLayer(new SceneLayer());
	}
	if ((layers & LAYER_WIDGET) == LAYER_WIDGET)
	{
		layerStack->AddLayer(new WidgetLayer());
		layerStack->GetLayer<WidgetLayer>()->SetWidgets(&widgets);
	}

	eventDispatcher.Subscribe([this](const Event& event) {
		DispatchEvents(event);
	});
}

void Engine::SetWindow(Window* win)
{
	window = win;
}

void Engine::SetScene(SScene* Scene)
{
	scene = Scene;

	if (SceneLayer* layer = layerStack->GetLayer<SceneLayer>())
	{
		layer->SetScene(scene);
	}

	Logger::Log("Loaded scene: " + scene->ObjectName);
	Logger::Log("Loaded actors: ");
	for (auto actor : scene->GetActors<SActor>())
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

void Engine::DispatchEvents(const Event& event)
{
	InputMode mode = window->GetInputMode();

	bool Handled = false;

	if (mode != InputMode::INPUT_GAME_CONSUME)
	{
		for (auto widget : widgets)
		{
			if (!Handled)
			{
				Handled |= widget->OnEvent(event);
			}
		}
	}

	if (mode != InputMode::INPUT_UI_CONSUME)
	{
		if (!Handled)
		{
			if (scene)
			{
				scene->DispatchEvent(event);
			}
		}
	}

	if (layerStack)
	{
		layerStack->DispatchAll(event);
	}
}

void Engine::AddWidget(UWidget* widget)
{
	if (widget)
	{
		widgets.push_back(widget);
		Logger::Log("Widget added to viewport: " + widget->ObjectName);
	}
}

void Engine::EngineLoop(float DeltaTime)
{
	GEngine = this;
	glfwMakeContextCurrent(window->GetHandle());

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	/*if (Renderer->ShouldResize)
	{
		glViewport(0, 0, Renderer->GetCnavasWidth(), Renderer->GetCnavasHeight());
		Renderer->ShouldResize = false;
	}*/

	if (scene)
	{
		scene->Update(DeltaTime);
	}
	
	for (UWidget* widget : widgets)
	{
		widget->Update(DeltaTime);
	}

	layerStack->RenderAll();

	glfwSwapBuffers(window->GetHandle());
	glfwPollEvents();
}
