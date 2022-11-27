#pragma once

#include "../Core/Scene/Actor/Actor.h"
#include <GL/glew.h>

#include "PointCloudAsset.h"
#include "../Core/Object/Pipeline/Material.h"
#include "../Core/Object/Pipeline/Texture2D.h"
#include "../Core/Renderer/Buffers/Buffers.h"

#include <glm/gtc/matrix_transform.hpp>

class SPointCloudActor : public SActor
{
protected:
	SMaterial* material;
	STexture2D* texture;

	unsigned int VAO;

	VertexBuffer* vertices;
	IndexBuffer* indices;

	unsigned int instances = 0;

	ShaderStorageBuffer* ssbo;

	struct
	{
		std::vector < glm::mat4 > positions;
		std::vector < glm::vec4 > colors;
	} PointCloudSSBO;

	struct BytedPointCloudSSBO
	{
		glm::mat4 positions;
		glm::vec4 colors;
	};
public:
	GENERATED_ACTOR_BODY(SPointCloudActor)
	{
		material = new SMaterial("PointCloudMaterial", "Shaders/PointCloud/Point");
		texture = new STexture2D("PointTexture", "Textures/PointCloud/Point");

		vertices = new VertexBuffer();
		indices = new IndexBuffer();

		ssbo = new ShaderStorageBuffer(0, 0, 3);

		vertices->SetData(std::vector<float> {
			-0.5, 0.5, 0, //0, 0,
				0.5, 0.5, 0, //1, 0,
				-0.5, -0.5, 0, //0, 1,
				0.5, -0.5, 0, //1, 1,
		});

		indices->SetData(std::vector<int> {
			0, 1, 2, 3, 2, 1
		});

		glGenVertexArrays(1, &VAO);
	}
	
	void RebuildMesh();

	SPointCloudAsset* PointCloud;

	virtual int Render() override;
};