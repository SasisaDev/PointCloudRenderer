#pragma once

#include <vector>
#include "../Debug/Logger.h"
#include <algorithm>
#include "IRenderable.h"

class IRenderer
{
protected:
	std::vector<IRenderable*> RenderObjects;

	unsigned int CanvasWidth, CanvasHeight;
public:

	bool ShouldResize = false;

	virtual void AddRenderObject(IRenderable* renderable);
	virtual void ClearRenderObjects() { RenderObjects.clear(); }

	virtual void RendererResized(unsigned int w, unsigned int h) { CanvasWidth = w; CanvasHeight = h; }
	virtual int Render();

	unsigned int GetCnavasWidth() { return CanvasWidth; }
	unsigned int GetCnavasHeight() { return CanvasHeight; }
};