#pragma once

#include <vector>
#include "../Buffers/Buffers.h"
#include <glm/glm.hpp>

class Mesh
{
public:
	typedef struct {
		std::vector<float> vertices;
		std::vector<int> indices;
		std::vector<glm::vec2> UVs;
	} MeshData;

	MeshData meshData;

	VertexBuffer* vertices;
	IndexBuffer* indices;
	std::vector<glm::vec2> UVs;

	Mesh(std::vector<float> v, std::vector<int> i, std::vector<glm::vec2> uvs);
	Mesh(const MeshData &data);

	void SetData(std::vector<float> v, std::vector<int> i, std::vector<glm::vec2> uvs);

	void RebuildMesh();
	
	void Bind();
	void Unbind();

	static MeshData Plane()
	{
		MeshData data;

		data.vertices = {
			0, 1, 0,
			1, 1, 0,
			0, 0, 0,
			1, 0, 0
		};

		data.indices = {
			0, 1, 2, 3, 2, 1
		};

		data.UVs = {
			glm::vec2(0, 0),
			glm::vec2(1, 0),
			glm::vec2(0, 1),
			glm::vec2(1, 1)
		};

		return data;
	}
};