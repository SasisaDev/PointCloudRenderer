#include "Window.h"

Window::Window(String title, int width, int height)
{
	Handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
}

int Window::Render()
{
	return 0;
}
