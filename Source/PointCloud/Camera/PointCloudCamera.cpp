#include "PointCloudCamera.h"

CameraModel SPointCloudCameraActor::CalculateModel()
{
	CameraModel model;

	model.Projection = glm::perspective(glm::radians(60.0f), Width / std::clamp(Height, std::numeric_limits<float>::epsilon(), 9169.0f), 0.01f, 100000.0f);
	//const float aspect = Width / Height;
	//glm::ortho(-1.0f, 1.0f, -1.0f * aspect, 1.0f * aspect, 0.1f, 100.0f);

	//model.Projection = glm::mat4(1.0f);

	model.View = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -RodDistance));

	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.x / 90, glm::vec3(1, 0, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.y / 90, glm::vec3(0, 1, 0));
	model.View = glm::rotate(model.View, ActorConfig.transform.Rotation.z / 90, glm::vec3(0, 0, 1));

	model.View = glm::translate(model.View, ActorConfig.transform.Location);

	return model;
}

void SPointCloudCameraActor::Update(float dt)
{
	//ActorConfig.transform.Rotation.x += 1;
	ActorConfig.transform.Rotation.y += 1;
	//ActorConfig.transform.Rotation.z += 1;
}
