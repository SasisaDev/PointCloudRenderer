#pragma once
#include "../Renderer.h"
#include <GL/glew.h>

class OpenGLRenderer : public IRenderer
{
public:

	virtual int Render() override;
};