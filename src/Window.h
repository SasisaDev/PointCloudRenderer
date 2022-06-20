#pragma once

#include <string>

#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.lib")

typedef std::string String;

class Window
{
protected:
	GLFWwindow* Handle;
public:

	Window(String title, int width, int height);

	GLFWwindow* GetWindow() { return Handle; }

	int Render();
};