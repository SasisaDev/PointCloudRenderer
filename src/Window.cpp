#include "Window.h"

Window::Window(String title, int width, int height)
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	Handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	
	glfwSetWindowUserPointer(Handle, this);

	glfwSetWindowSizeCallback(Handle, [](GLFWwindow* window, int width, int height) {
		Window* pw = (Window*)glfwGetWindowUserPointer(window);
		if (pw)
		{
			if (pw->GetEngine())
			{
				pw->GetEngine()->CleanupSwapChain();
				pw->GetEngine()->RecreateSwapChain();
				pw->GetEngine()->DrawFrame();
					Logger::Log("Window resized");
				}
			}
		});

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
