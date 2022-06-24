#include "WidgetLayer.h"

void WidgetLayer::OnAttach()
{
}

void WidgetLayer::OnDetach()
{
}

void WidgetLayer::OnUpdate()
{
}

void WidgetLayer::Render()
{
	glDisable(GL_DEPTH_TEST);

	for (UWidget* widget : _widgets)
	{
		widget->Render();
	}
}

void WidgetLayer::OnEvent(const Event& e)
{
}
