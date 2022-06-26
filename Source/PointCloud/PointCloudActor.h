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

	VertexBuffer* vertices;
	IndexBuffer* indices;

	unsigned int instances;

	VertexBuffer* models;
	VertexBuffer* colors;
public:
	GENERATED_ACTOR_BODY(SPointCloudActor)
	{
		material = new SMaterial("PointCloudMaterial", "Shaders/PointCloud/Point");
		texture = new STexture2D("PointTexture", "Textures/PointCloud/Point");
	}
	
	void RebuildMesh();

	SPointCloudAsset* PointCloud;

	virtual int Render() override;
};