#pragma once

#include <vector>
#include "IRenderable.h"

class IRenderer
{
protected:
	std::vector<IRenderable*> RenderObjects;
public:

	virtual int Render();
};