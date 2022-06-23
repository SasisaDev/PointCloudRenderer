#include "Camera.h"

CameraModel SCameraActor::CalculateModel()
{
	CameraModel model;

	model.Projection = glm::perspective(60.0f, Width / Height, 1.0f, 150.0f);
	model.View = glm::translate(glm::mat4(1.0f), ActorConfig.transform.Location);

	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.x, glm::vec3(1, 0, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.y, glm::vec3(0, 1, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.z, glm::vec3(0, 0, 1));

	return model;
}

void SCameraActor::Update(float DeltaTime)
{

}

void SCameraActor::OnEvent(const Event& event)
{
	if (event.EventAction == EVENT_WINDOW_RESIZE && event.Parameters.size() >= 0)
	{
		Width = (float)reinterpret_cast<int>(event.Parameters[0]);
		Height = (float)reinterpret_cast<int>(event.Parameters[1]);
	}
}
