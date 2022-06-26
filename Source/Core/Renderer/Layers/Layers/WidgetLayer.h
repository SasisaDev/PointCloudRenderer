#pragma once

#include "../Layer.h"
#include "../../../UI/Widget.h"
#include "../../Buffers/Buffers.h"
#include <GL/glew.h>

struct WidgetUniformBuffer
{
	glm::mat4 Projection;
};

class WidgetLayer : public Layer
{
	std::vector<UWidget*>* _widgets;
	UniformBuffer* Uniform;
public:
	WidgetLayer();

	void SetWidgets(std::vector<UWidget*>* widgets) { _widgets = widgets; }

	virtual void OnAttach();
	virtual void OnDetach();
	virtual void OnUpdate();
	virtual void Render();
	virtual void OnEvent(const Event& e);
};