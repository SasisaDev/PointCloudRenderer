#pragma once

#include "../Core/Scene/Actor/Actor.h"
#include <GL/glew.h>

#include "PointCloudAsset.h"
#include "../Core/Object/Pipeline/Material.h"
#include "../Core/Object/Pipeline/Texture2D.h"
#include "../Core/Renderer/Buffers/Buffers.h"

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
		std::vector < glm::vec3 > positions;
		std::vector < glm::vec4 > colors;
	} PointCloudSSBO;

	struct BytedPointCloudSSBO
	{
		glm::vec3* positions;
		glm::vec4* colors;
	};
public:
	GENERATED_ACTOR_BODY(SPointCloudActor)
	{
		material = new SMaterial("PointCloudMaterial", "Shaders/PointCloud/Point");
		texture = new STexture2D("PointTexture", "Textures/PointCloud/Point");

		vertices = new VertexBuffer();
		indices = new IndexBuffer();

		ssbo = new ShaderStorageBuffer(0, 0, 3);

		//glGenVertexArrays(1, &VAO);
	}
	
	void RebuildMesh();

	SPointCloudAsset* PointCloud;

	virtual int Render() override;
};