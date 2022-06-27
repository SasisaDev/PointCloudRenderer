#pragma once
#include <GL/glew.h>
#include "../Renderer/Renderer.h"
#include <GLFW/glfw3.h>

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")

#include <string>
#include "../Scene/Scene.h"
#include "../Debug/Logger.h"
#include "../Events/EventDispatcher.h"

class Window
{
protected:
	GLFWwindow* Handle;

	IRenderer* Renderer = nullptr;
	EventDispatcher* eventDispatcher;

	std::string Title;
	int Width = 0, Height = 0;

	InputMode inputMode;
public:
	Window(std::string title, int w, int h);

	void AttachRenderer(IRenderer* renderer) { Renderer = renderer; renderer->SetWindowPointer(this); }
	IRenderer* GetRenderer() { return Renderer; }

	void AttachEventDispatcher(EventDispatcher* dispatcher) { eventDispatcher = dispatcher; }
	EventDispatcher* GetEventDispatcher() { return eventDispatcher; }

	void SetInputMode(InputMode mode) { inputMode = mode; }
	InputMode GetInputMode() const { return inputMode; }

	std::string GetTitle() { return Title; }

	int GetWidth() const { return Width; }
	int GetHeight() const { return Height; }

	GLFWwindow* GetHandle() { return Handle; }
};