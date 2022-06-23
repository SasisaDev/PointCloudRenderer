#include "Camera.h"

CameraModel SCameraActor::CalculateModel()
{
	CameraModel model;

	model.Projection = glm::perspective(60.0f, 1280.0f / 720.0f, 0.0f, 150.0f);

	return model;
}

void SCameraActor::Update(float DeltaTime)
{

}
