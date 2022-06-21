#pragma once
#include "../Renderer.h"
#include <GL/glew.h>

class OpenGLRenderer : public IRenderer
{
public:

	virtual void RendererResized(unsigned int w, unsigned int h) override;
	virtual int Render() override;
};