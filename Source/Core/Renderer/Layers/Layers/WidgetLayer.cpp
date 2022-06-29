#include "WidgetLayer.h"

#include <glm/gtc/matrix_transform.hpp>
#include "../../../Window/Window.h"

WidgetLayer::WidgetLayer()
{
	WidgetUniformBuffer Object;
	int w, h;
	glfwGetWindowSize(glfwGetCurrentContext(), &w, &h);

	const float aspect = w / std::clamp((float)h, std::numeric_limits<float>::epsilon(), 9169.0f);
	//Object.Projection = glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, -1000.0f, 1000.0f);
	//Object.Projection = glm::ortho(-1, 1, -1, 1, -100, 100);
	Object.Projection = glm::ortho(0.f, (float)w, 0.f, (float)h, -10.f, 10.f);

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
	//glDisable(GL_CULL_FACE);

	Uniform->Bind();

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
		buff.Projection = glm::ortho(0.f, (float)Width, 0.f, (float)Height, -10.f, 10.f);

		Uniform->UpdateBuffer(&buff.Projection, offsetof(WidgetUniformBuffer, Projection), sizeof(glm::mat4));
		break;
	}
}
