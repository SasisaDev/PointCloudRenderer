#include "Camera.h"

#include <algorithm>
#include <GLFW/glfw3.h>

CameraModel SCameraActor::CalculateModel()
{
	CameraModel model;

	//model.Projection = glm::perspective(glm::radians(45.0f), Width / std::clamp(Height, std::numeric_limits<float>::epsilon(), 9169.0f), 0.1f, 150.0f);
	//const float aspect = Width / Height;
	//glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, 0.1f, 100.0f);

	model.Projection = glm::mat4(1.0f);

	model.View = glm::translate(glm::mat4(1.0f), ActorConfig.transform.Location);

	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.x, glm::vec3(1, 0, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.y, glm::vec3(0, 1, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.z, glm::vec3(0, 0, 1));

	return model;
}

void SCameraActor::Update(float DeltaTime)
{
	//ActorConfig.transform.Rotation.y += 0.0003;
}

void SCameraActor::OnEvent(const Event& event)
{
	switch (event.EventAction)
	{
	case EVENT_WINDOW_RESIZE:
		Width = (float)reinterpret_cast<int>(event.Parameters[0]);
		Height = (float)reinterpret_cast<int>(event.Parameters[1]);
		break;
	case EVENT_KEY_DOWN:
		if (event.IsKey(GLFW_KEY_W))
		{
			ActorConfig.transform.Location.z += 0.1f;
		}
		else if (event.IsKey(GLFW_KEY_S))
		{
			ActorConfig.transform.Location.z -= 0.1f;
		}
		else if (event.IsKey(GLFW_KEY_D))
		{
			ActorConfig.transform.Location.x += 0.1f;
		}
		else if (event.IsKey(GLFW_KEY_A))
		{
			ActorConfig.transform.Location.x -= 0.1f;
		}
		else if (event.IsKey(GLFW_KEY_SPACE))
		{
			ActorConfig.transform.Location.y += 0.1f;
		}
		else if (event.IsKey(GLFW_KEY_LEFT_SHIFT))
		{
			ActorConfig.transform.Location.y -= 0.1f;
		}
		break;
	default:
		break;
	}
}
