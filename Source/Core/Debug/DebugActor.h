#pragma once

#include "../Scene/Actor/Actor.h"
#include "../Renderer/Shader/Shader.h"

class SDebugActor : public SActor
{
protected:
	Shader* someShader;
	glm::mat4 model;

	unsigned int vbo, vao;
public:
	SDebugActor(std::string name);

	virtual void Update(float dt) override;

	virtual int Render() override;
};