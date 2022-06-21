#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &framebufferTexture);
	glBindTexture(GL_TEXTURE_2D, framebufferTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, CanvasWidth, CanvasHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);

	/* Depth buffer */
	glGenRenderbuffers(1, &renderbufferDepth);
	glBindRenderbuffer(GL_RENDERBUFFER, renderbufferDepth);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, CanvasWidth, CanvasHeight);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	/* Framebuffer to link everything together */
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferTexture, 0);
	//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbufferDepth);
	GLenum status;
	if ((status = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE) {
		fprintf(stderr, "glCheckFramebufferStatus: error %p\n", status);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	/* init_resources */
	GLfloat fbo_vertices[] = {
	  -1, -1,
	   1, -1,
	  -1,  1,
	   1,  1,
	};
	glGenBuffers(1, &vbo_fbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_fbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(fbo_vertices), fbo_vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

OpenGLRenderer::~OpenGLRenderer()
{
	glDeleteRenderbuffers(1, &renderbufferDepth);
	glDeleteTextures(1, &framebufferTexture);
	glDeleteFramebuffers(1, &framebuffer);
	glDeleteBuffers(1, &vbo_fbo_vertices);
}

void OpenGLRenderer::RendererResized(unsigned int w, unsigned int h)
{
	IRenderer::RendererResized(w, h);

	glBindTexture(GL_TEXTURE_2D, framebufferTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, CanvasWidth, CanvasHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindRenderbuffer(GL_RENDERBUFFER, renderbufferDepth);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, CanvasWidth, CanvasHeight);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	ShouldResize = true;
}

int OpenGLRenderer::Render()
{
	if (postProcessShader)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		glClearColor(0.075f, 0.075f, 0.075f, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto renderable : RenderObjects)
		{
			renderable->Render();
		}
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glClearColor(0.0, 0.0, 0.0f, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(postProcessShader->GetProgramID());
		glBindTexture(GL_TEXTURE_2D, framebufferTexture);
		glUniform1i(uniform_fbo_texture, 0);
		glEnableVertexAttribArray(attribute_v_coord_postproc);

		glBindBuffer(GL_ARRAY_BUFFER, vbo_fbo_vertices);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glVertexAttribPointer(
			attribute_v_coord_postproc,  // attribute
			2,                  // number of elements per vertex, here (x,y)
			GL_FLOAT,           // the type of each element
			GL_FALSE,           // take our values as-is
			0,                  // no extra data between each position
			0                   // offset of first element
		);
		glDisableVertexAttribArray(attribute_v_coord_postproc);
	}
	else
	{
		for (auto renderable : RenderObjects)
		{
			renderable->Render();
		}
	}
	return 0;
}

void OpenGLRenderer::SetPostProcessShader(Shader* shader)
{
	postProcessShader = shader;
	if (shader)
	{
		attribute_v_coord_postproc = glGetAttribLocation(shader->GetProgramID(), "v_coord");
		if (attribute_v_coord_postproc == -1) {
			fprintf(stderr, "Could not bind attribute %s\n", "v_coord");
		}

		uniform_fbo_texture = glGetUniformLocation(shader->GetProgramID(), "fbo_texture\0");
		if (uniform_fbo_texture == -1) {
			fprintf(stderr, "Could not bind attribute %s\n", "fbo_texture");
		}
	}
}
