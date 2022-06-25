#include "Mesh.h"

Mesh::Mesh(std::vector<float> v, std::vector<int> i, std::vector<glm::vec2> uvs)
{
	vertices = new VertexBuffer(v);
	indices = new IndexBuffer(i);
	UVs = uvs;

	// Build Mesh
}


Mesh::Mesh(const MeshData& data)
{
	meshData = data;

	vertices = new VertexBuffer(data.vertices);
	indices = new IndexBuffer(data.indices);
	UVs = data.UVs;
}

void Mesh::SetData(std::vector<float> v, std::vector<int> i, std::vector<glm::vec2> uvs)
{
	meshData;
}

void Mesh::RebuildMesh()
{
	// Build mesh
	if (vertices)
	{
		vertices->SetData(meshData.vertices);
	}
	else
	{
		vertices = new VertexBuffer(meshData.vertices);
	}

	if (indices)
	{
		indices->SetData(meshData.indices);
	}
	else
	{
		indices = new IndexBuffer(meshData.indices);
	}

	UVs = meshData.UVs;
}

void Mesh::Bind()
{
}

void Mesh::Unbind()
{
}
