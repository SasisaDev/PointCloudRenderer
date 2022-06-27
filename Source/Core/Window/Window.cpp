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

	glfwSetKeyCallback(Handle, [](GLFWwindow* win, int key, int scancode, int action, int mods)
		{
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(win));
			if (window)
			{
				if (auto dispatcher = window->GetEventDispatcher())
				{
					if (action == GLFW_PRESS)
					{
						dispatcher->Dispatch(Event(EVENT_KEY_DOWN, std::vector<void*>{reinterpret_cast<void*>(key)}));
					}
					else if (action == GLFW_RELEASE)
					{
						dispatcher->Dispatch(Event(EVENT_KEY_UP, std::vector<void*>{reinterpret_cast<void*>(key)}));
					}
					dispatcher->Dispatch(Event(EVENT_KEY, std::vector<void*>{reinterpret_cast<void*>(key)}));
				}
			}
		});

	glfwSetMouseButtonCallback(Handle, [](GLFWwindow* win, int button, int action, int mods)
		{
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(win));
			if (window)
			{
				if (auto dispatcher = window->GetEventDispatcher())
				{
					double xpos, ypos;
					glfwGetCursorPos(win, &xpos, &ypos);
					if (action == GLFW_PRESS)
					{
						dispatcher->Dispatch(Event(EVENT_MOUSEBUTTON_DOWN, std::vector<void*>{reinterpret_cast<void*>((int)xpos), reinterpret_cast<void*>((int)ypos)}));
					}
					else if (action == GLFW_RELEASE)
					{
						dispatcher->Dispatch(Event(EVENT_MOUSEBUTTON_UP, std::vector<void*>{reinterpret_cast<void*>((int)xpos), reinterpret_cast<void*>((int)ypos)}));
					}
				}
			}
		});

	glfwMakeContextCurrent(Handle);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		Logger::Log("Glew initialization failed");
	}
}

