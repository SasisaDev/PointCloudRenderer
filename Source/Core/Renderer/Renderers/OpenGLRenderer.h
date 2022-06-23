#pragma once
#include "../Renderer.h"
#include <GL/glew.h>
#include "../../Window/Window.h"

#include "../Shader/Shader.h"
#include "../../Camera/CameraSubsystem.h"

class OpenGLRenderer : public IRenderer
{
protected:
	unsigned int framebuffer;
	unsigned int framebufferTexture;
	unsigned int renderbufferDepth;

	GLuint vbo_fbo_vertices;

	Shader* postProcessShader;

	unsigned int attribute_v_coord_postproc, uniform_fbo_texture;

	SCameraSubsystem* Camera;
	
public:
	OpenGLRenderer(unsigned int w, unsigned int h);
	~OpenGLRenderer();

	virtual void SetWindowPointer(Window* win);

	virtual void RendererResized(unsigned int w, unsigned int h) override;
	virtual int Render() override;

	int GuardedRender();

	void SetPostProcessShader(Shader* shader);
};