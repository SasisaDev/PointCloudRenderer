#include "Camera.h"

#include <algorithm>
#include <GLFW/glfw3.h>

CameraModel SCameraActor::CalculateModel()
{
	CameraModel model;

	model.Projection = glm::perspective(glm::radians(60.0f), Width / std::clamp(Height, std::numeric_limits<float>::epsilon(), 9169.0f), 0.01f, 100000.0f);
	//const float aspect = Width / Height;
	//glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, 0.1f, 100.0f);

	//model.Projection = glm::mat4(1.0f);

	model.View = glm::translate(glm::mat4(1.0f), ActorConfig.transform.Location);

	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.x, glm::vec3(1, 0, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.y, glm::vec3(0, 1, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.z, glm::vec3(0, 0, 1));

	return model;
}

void SCameraActor::Update(float DeltaTime)
{
	//ActorConfig.transform.Location += movementVector * DeltaTime;
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
		/*if (event.IsKey(GLFW_KEY_W))
		{
			movementVector.z = 0.005f;
		}
		else if (event.IsKey(GLFW_KEY_S))
		{
			movementVector.z = -0.005f;
		}
		else if (event.IsKey(GLFW_KEY_D))
		{
			movementVector.x = -0.005f;
		}
		else if (event.IsKey(GLFW_KEY_A))
		{
			movementVector.x = 0.005f;
		}
		else if (event.IsKey(GLFW_KEY_SPACE))
		{
			movementVector.y = -0.005f;
		}
		else if (event.IsKey(GLFW_KEY_LEFT_SHIFT))
		{
			movementVector.y = 0.005f;
		}*/
		break;
	case EVENT_KEY_UP:
		/*if (event.IsKey(GLFW_KEY_W))
		{
			movementVector.z = 0;
		}
		else if (event.IsKey(GLFW_KEY_S))
		{
			movementVector.z = 0;
		}
		else if (event.IsKey(GLFW_KEY_D))
		{
			movementVector.x = 0;
		}
		else if (event.IsKey(GLFW_KEY_A))
		{
			movementVector.x = 0;
		}
		else if (event.IsKey(GLFW_KEY_SPACE))
		{
			movementVector.y = 0;
		}
		else if (event.IsKey(GLFW_KEY_LEFT_SHIFT))
		{
			movementVector.y = 0;
		}*/
		break;
	default:
		break;
	}
}
