#include "OpenGLRenderer.h"

void OpenGLRenderer::RendererResized(unsigned int w, unsigned int h)
{
	IRenderer::RendererResized(w, h);

	ShouldResize = true;
}

int OpenGLRenderer::Render()
{
	for (auto renderable : RenderObjects)
	{
		renderable->Render();
	}
	return 0;
}
