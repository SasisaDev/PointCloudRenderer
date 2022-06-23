#pragma once

#include "../Layer.h"
#include "../../../Scene/Scene.h"
#include <GL/glew.h>

class SceneLayer : public Layer
{
	SScene* _scene;
public:
	void SetScene(SScene* scene) { _scene = scene; }

	virtual void OnAttach();
	virtual void OnDetach();
	virtual void OnUpdate();
	virtual void Render(unsigned int framebuffer);
	virtual void OnEvent(const Event& e);
};