#include "SceneLayer.h"

void SceneLayer::OnAttach()
{
}

void SceneLayer::OnDetach()
{
}

void SceneLayer::OnUpdate()
{
}

void SceneLayer::Render(unsigned int framebuffer)
{
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glEnable(GL_DEPTH_TEST);

	for (SActor* actor : _scene->GetActors())
	{
		actor->Render();
	}

	glDisable(GL_DEPTH_TEST);
}

void SceneLayer::OnEvent(const Event& e)
{
}
