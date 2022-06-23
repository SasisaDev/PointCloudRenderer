#include "LayerStack.h"

LayerStack::LayerStack(unsigned int width, unsigned int height)
	: Width(width), Height(height)
{
	layers = std::vector<Layer*>();
	LayerStackShader = new Shader("Shaders/LayerStack");

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &framebufferTexture);
	glBindTexture(GL_TEXTURE_2D, framebufferTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);

	/* Depth buffer */
	glGenRenderbuffers(1, &renderbufferDepth);
	glBindRenderbuffer(GL_RENDERBUFFER, renderbufferDepth);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, Width, Height);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	/* Framebuffer to link everything together */
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferTexture, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbufferDepth);
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

LayerStack::~LayerStack()
{
	glDeleteRenderbuffers(1, &renderbufferDepth);
	glDeleteTextures(1, &framebufferTexture);
	glDeleteFramebuffers(1, &framebuffer);
	glDeleteBuffers(1, &vbo_fbo_vertices);
}

void LayerStack::AddLayer(Layer* layer, int index)
{
	layers.push_back(layer);
}

void LayerStack::RenderAll()
{
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

	glClearColor(0.075, 0.075, 0.075, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto layer : layers)
	{
		layer->OnUpdate();
		layer->Render(framebuffer);
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_fbo_vertices);
	glUseProgram(LayerStackShader->GetProgramID());
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, framebufferTexture);
	glUniform1i(glGetUniformLocation(LayerStackShader->GetProgramID(), "fbo_texture\0"), 0);
	glEnableVertexAttribArray(glGetAttribLocation(LayerStackShader->GetProgramID(), "v_coord"));
	glVertexAttribPointer(
		glGetAttribLocation(LayerStackShader->GetProgramID(), "v_coord"),  // attribute
		2,                  // number of elements per vertex, here (x,y)
		GL_FLOAT,           // the type of each element
		GL_FALSE,           // take our values as-is
		0,                  // no extra data between each position
		0                   // offset of first element
	);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glUseProgram(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableVertexAttribArray(glGetAttribLocation(LayerStackShader->GetProgramID(), "v_coord"));
}

void LayerStack::DispatchAll(const Event& e)
{
	if (e.EventAction == EVENT_WINDOW_RESIZE && e.Parameters.size() >= 2)
	{
		Width = reinterpret_cast<int>(e.Parameters[0]);
		Height = reinterpret_cast<int>(e.Parameters[1]);

		glViewport(0, 0, Width, Height);

		glBindTexture(GL_TEXTURE_2D, framebufferTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);

		glBindRenderbuffer(GL_RENDERBUFFER, renderbufferDepth);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, Width, Height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	for (auto layer : layers)
	{
		layer->OnEvent(e);
	}
}
