#include "WidgetLayer.h"

#include <glm/gtc/matrix_transform.hpp>
#include "../../../Window/Window.h"

WidgetLayer::WidgetLayer()
{
	WidgetUniformBuffer Object;
	int w, h;
	glfwGetWindowSize(glfwGetCurrentContext(), &w, &h);

	const float aspect = w / std::clamp((float)h, std::numeric_limits<float>::epsilon(), 9169.0f);
	Object.Projection = glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, 0.1f, 100.0f);

	Uniform = new UniformBuffer(reinterpret_cast<void*>(&Object), sizeof(Object), 1);
}

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

	for (UWidget* widget : *_widgets)
	{
		widget->Render();
	}
}

void WidgetLayer::OnEvent(const Event& e)
{
	switch (e.EventAction)
	{
	case EVENT_WINDOW_RESIZE:
		float Width = (float)reinterpret_cast<int>(e.Parameters[0]);
		float Height = (float)reinterpret_cast<int>(e.Parameters[1]);

		WidgetUniformBuffer buff;
		const float aspect = Width / std::clamp(Height, std::numeric_limits<float>::epsilon(), 9169.0f);
		buff.Projection = glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, 0.1f, 100.0f);

		Uniform->UpdateBuffer(&buff.Projection, offsetof(WidgetUniformBuffer, Projection), sizeof(glm::mat4));
		break;
	}
}
