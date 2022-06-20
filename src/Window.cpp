#include "Window.h"

Window::Window(String title, int width, int height)
{
	Engine = new VulkanEngine();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	Handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (glfwCreateWindowSurface(Engine->instance, Handle, nullptr, &Engine->surface) != VK_SUCCESS)
	{
		Logger::Log("Failed creating VkSurfaceKHR");
	}
	Logger::Log("Created VkSurfaceKHR");
}

Window::~Window()
{
	glfwDestroyWindow(Handle);
}

int Window::Render()
{
	return 0;
}
