#include "PointCloudCamera.h"

#include <GLFW/glfw3.h>

CameraModel SPointCloudCameraActor::CalculateModel()
{
	CameraModel model;

	model.Projection = glm::perspective(glm::radians(60.0f), Width / std::clamp(Height, std::numeric_limits<float>::epsilon(), 9169.0f), 0.01f, 100000.0f);
	//const float aspect = Width / Height;
	//glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, 0.1f, 100.0f);

	//model.Projection = glm::mat4(1.0f);

	model.View = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -RodDistance));

	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.x / 45, glm::vec3(1, 0, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.y / 45, glm::vec3(0, 1, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.z / 45, glm::vec3(0, 0, 1));

	model.View = glm::translate(model.View, ActorConfig.transform.Location);

	return model;
}

void SPointCloudCameraActor::Update(float dt)
{
	//ActorConfig.transform.Rotation.y += 1;
}

void SPointCloudCameraActor::OnEvent(const Event& e)
{
	switch (e.EventAction)
	{
	case EVENT_MOUSEBUTTON_DOWN:
		if (e.IsMouseButton(GLFW_MOUSE_BUTTON_RIGHT))
		{
			oldX = (float)reinterpret_cast<int>(e.Parameters[0]);
			oldY = (float)reinterpret_cast<int>(e.Parameters[1]);

			bRotateMouse = true;
		}
		break;
	case EVENT_MOUSEBUTTON_UP:
		if (e.IsMouseButton(GLFW_MOUSE_BUTTON_RIGHT))
		{
			bRotateMouse = false;
		}
		break;
	case EVENT_CURSOR_POSITION:
		if (bRotateMouse)
		{
			float x = (float)reinterpret_cast<int>(e.Parameters[0]);
			float y = (float)reinterpret_cast<int>(e.Parameters[1]);

			float dx = x - oldX;
			float dy = y - oldY;

			if (dy > 0)
			{
				if (ActorConfig.transform.Rotation.x < 90.0f)
				{
					ActorConfig.transform.Rotation.x += dy;
				}
			}
			else
			{
				if (ActorConfig.transform.Rotation.x > -90.0f)
				{
					ActorConfig.transform.Rotation.x += dy;
				}
			}

			ActorConfig.transform.Rotation.y += dx;

			oldX = x;
			oldY = y;
		}
		break;
	case EVENT_SCROLL:
		int y = reinterpret_cast<int>(e.Parameters[0]);

		if (y > 0)
		{
			if (RodDistance > 2)
			{
				RodDistance -= y;
			}
		}
		else
		{
			if (RodDistance < 150)
			{
				RodDistance -= y;
			}
		}
		break;
	}
}
