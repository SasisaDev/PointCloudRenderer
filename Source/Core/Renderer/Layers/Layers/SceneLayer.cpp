#include "SceneLayer.h"

SceneLayer::SceneLayer()
{
	SceneUniformBuffer Object;
	Uniform = new UniformBuffer(reinterpret_cast<void*>(&Object), sizeof(Object), 0);
}

void SceneLayer::OnAttach()
{
}

void SceneLayer::OnDetach()
{
}

void SceneLayer::OnUpdate()
{
	if (_scene)
	{
		for (SActor* actor : _scene->GetActors<SActor>())
		{
			if (SCameraActor* camera = dynamic_cast<SCameraActor*>(actor))
			{
				CameraModel model = camera->CalculateModel();
				Uniform->UpdateBuffer(&model.Projection, offsetof(SceneUniformBuffer, Projection), sizeof(glm::mat4));
				Uniform->UpdateBuffer(&model.View, offsetof(SceneUniformBuffer, View), sizeof(glm::mat4));
			}
		}
	}
}

void SceneLayer::Render()
{
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	Uniform->Bind();

	for (SActor* actor : _scene->GetActors<SActor>())
	{
		actor->Render();
	}
}

void SceneLayer::OnEvent(const Event& e)
{
	if (e.EventAction == EVENT_WINDOW_RESIZE && e.Parameters.size() >= 2)
	{
		//Width = reinterpret_cast<int>(e.Parameters[0]);
		//Height = reinterpret_cast<int>(e.Parameters[1]);

	}
}
