#pragma once

#include "../Layer.h"
#include "../../../UI/Widget.h"
#include <GL/glew.h>

class WidgetLayer : public Layer
{
	std::vector<UWidget*> _widgets;
public:
	void SetWidgets(const std::vector<UWidget*>& widgets) { _widgets = widgets; }

	virtual void OnAttach();
	virtual void OnDetach();
	virtual void OnUpdate();
	virtual void Render(unsigned int framebuffer);
	virtual void OnEvent(const Event& e);
};