#include "Renderer.h"

void IRenderer::AddRenderObject(IRenderable* renderable)
{
	RenderObjects.push_back(renderable);

	std::sort(RenderObjects.begin(), RenderObjects.end(), [](IRenderable* first, IRenderable* last)
		{
			return first->RenderPriority > last->RenderPriority;
		});
}

int IRenderer::Render()
{
	return 0;
}
