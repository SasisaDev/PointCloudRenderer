#pragma once

#include "../Layer.h"
#include "../../../Scene/Scene.h"
#include "../../Buffers/Buffers.h"
#include "../../../Camera/Camera.h"
#include <GL/glew.h>

// TODO: Make it accessable directly from Camera
struct SceneUniformBuffer
{
	glm::mat4 Projection;
	glm::mat4 View;
};

class SceneLayer : public Layer
{
protected:
	SScene* _scene;

	UniformBuffer* Uniform;
public:
	SceneLayer();

	void SetScene(SScene* scene) { _scene = scene; }

	virtual void OnAttach();
	virtual void OnDetach();
	virtual void OnUpdate();
	virtual void Render(unsigned int framebuffer);
	virtual void OnEvent(const Event& e);
};