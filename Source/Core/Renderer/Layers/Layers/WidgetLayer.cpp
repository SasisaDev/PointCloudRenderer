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

void WidgetLayer::Render(unsigned int framebuffer)
{
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glDisable(GL_DEPTH_TEST);

	for (UWidget* widget : _widgets)
	{
		widget->Render();
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void WidgetLayer::OnEvent(const Event& e)
{
}
