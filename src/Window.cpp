#include "Window.h"

Window::Window(String title, int width, int height)
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	Handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	Engine = new VulkanEngine(Handle);
}

Window::~Window()
{
	glfwDestroyWindow(Handle);
}

int Window::Render()
{
	Engine->DrawFrame();

	return 0;
}
