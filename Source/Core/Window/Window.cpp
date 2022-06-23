#include "Window.h"

Window::Window(std::string title, int w, int h)
	: Title(title), Width(w), Height(h)
{
	Handle = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetWindowUserPointer(Handle, this);

	glfwSetWindowSizeCallback(Handle, [](GLFWwindow* win, int w, int h) 
		{
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(win));
			if (window)
			{
				if (auto dispatcher = window->GetEventDispatcher())
				{
					dispatcher->Dispatch(Event(EVENT_WINDOW_RESIZE, std::vector<void*>{reinterpret_cast<void*>(w), reinterpret_cast<void*>(h)}));
				}
			}
		});

	glfwMakeContextCurrent(Handle);

	if (glewInit() != GLEW_OK)
	{
		Logger::Log("Glew initialization failed");
	}
}

