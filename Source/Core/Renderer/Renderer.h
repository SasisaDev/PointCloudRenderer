#pragma once

#include <vector>
#include "../Debug/Logger.h"
#include <algorithm>
#include "IRenderable.h"

class Window;

class IRenderer
{
protected:
	std::vector<IRenderable*> RenderObjects;
	Window* ParentWindow;

	unsigned int CanvasWidth, CanvasHeight;
public:

	bool ShouldResize = false;

	virtual void SetWindowPointer(Window* win) { ParentWindow = win; }

	virtual void AddRenderObject(IRenderable* renderable);
	virtual void ClearRenderObjects() { RenderObjects.clear(); }

	virtual void RendererResized(unsigned int w, unsigned int h) { CanvasWidth = w; CanvasHeight = h; }
	virtual int Render();

	unsigned int GetCnavasWidth() { return CanvasWidth; }
	unsigned int GetCnavasHeight() { return CanvasHeight; }
};