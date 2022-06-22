#pragma once
#include "../Renderer.h"
#include <GL/glew.h>

#include "../Shader/Shader.h"

class OpenGLRenderer : public IRenderer
{
protected:
	unsigned int framebuffer;
	unsigned int framebufferTexture;
	unsigned int renderbufferDepth;

	GLuint vbo_fbo_vertices;

	Shader* postProcessShader;

	unsigned int attribute_v_coord_postproc, uniform_fbo_texture;;
	
public:
	OpenGLRenderer(unsigned int w, unsigned int h);
	~OpenGLRenderer();

	virtual void RendererResized(unsigned int w, unsigned int h) override;
	virtual int Render() override;

	void SetPostProcessShader(Shader* shader);
};