#include "DebugActor.h"

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

SDebugActor::SDebugActor(std::string name)
	: SActor(name)
{
	someShader = new Shader("Shaders/Debug/Debug");

	float positions[9] = {
		-0.5f, -0.5f, 0,
		0, 0.5f, 0,
		0.5f, -0.5f, 0
	};

	//model = glm::scale(glm::mat4(1.0f), glm::vec3(1, 1, 1));
	//model = glm::translate(model, glm::vec3(0, 0, -10));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int indices[3] = {
		0, 1, 2
	};

	glGenBuffers(1, &vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void SDebugActor::Update(float dt)
{
	ActorConfig.transform.Rotation.y += 0.005 * dt;

	model = glm::translate(glm::mat4(1.0f), ActorConfig.transform.Location);
	model = glm::rotate(model, ActorConfig.transform.Rotation.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, ActorConfig.transform.Rotation.y, glm::vec3(0, 1, 0));
	model = glm::rotate(model, ActorConfig.transform.Rotation.z, glm::vec3(0, 0, 1));
	model = glm::scale(model, ActorConfig.transform.Scale);

	//model = glm::scale(glm::mat4(1.0f), glm::vec3(1, 1, 1));
}

int SDebugActor::Render()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glUseProgram(someShader->GetProgramID());

	glUniformMatrix4fv(glGetUniformLocation(someShader->GetProgramID(), "Model"), 1, GL_FALSE, reinterpret_cast<float*>(&model));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glUseProgram(0);

	glDisableVertexAttribArray(0);

	return 1;
}
