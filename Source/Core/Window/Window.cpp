#include "Window.h"

Window::Window(std::string title, int w, int h)
	: Title(title), Width(w), Height(h)
{
	Handle = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetWindowUserPointer(Handle, this);

	glfwSetWindowSizeCallback(Handle, [](GLFWwindow* win, int w, int h) 
		{
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(win));
			if (window)
			{
				window->GetRenderer()->RendererResized(w, h);
			}
		});

	glfwMakeContextCurrent(Handle);

	if (glewInit() != GLEW_OK)
	{
		Logger::Log("Glew initialization failed");
	}
}

void Window::SetScene(SScene* scene)
{ 
	Scene = scene;

	Logger::Log("Loaded scene: " + scene->ObjectName);
	Logger::Log("Loaded actors: ");
	for (auto actor : scene->GetActors())
	{
		Renderer->AddRenderObject(actor);
		std::stringstream stream;
		stream << std::dec << actor->RenderPriority;
		Logger::Log("\t" + actor->ObjectName + " (" + stream.str() + ")");
	}
}