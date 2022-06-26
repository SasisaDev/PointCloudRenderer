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

	static MeshData Plane(float x, float y, float w, float h)
	{
		MeshData data;

		data.vertices = {
			x, x+h, 0,
			x+w, x+h, 0,
			x, x, 0,
			x+w, x, 0
		};

		data.indices = {
			1, 2, 3, 2, 3, 4
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