#pragma once

#include <GL/glew.h>
#include <cstddef>
#include <vector>

class VertexBuffer
{
protected:
	unsigned int bufferID;
	std::vector<float> vertices;
public:
	VertexBuffer();
	VertexBuffer(std::vector<float> data);

	~VertexBuffer();

	void SetData(std::vector<float> data);

	void Bind();
	void Unbind();

	unsigned int GetID() const { return bufferID; }
};

class IndexBuffer
{
protected:
	unsigned int bufferID;
	std::vector<int> indices;
public:
	IndexBuffer();
	IndexBuffer(std::vector<int> data);

	~IndexBuffer();

	void SetData(std::vector<int> data);

	void Bind();
	void Unbind();

	unsigned int GetID() const { return bufferID; }
};

class UniformBuffer
{
protected:
	unsigned int bufferID;
public:
	UniformBuffer(void* data, size_t size, int binding);

	void UpdateBuffer(void* data, size_t offset, size_t size);
};

class ShaderStorageBuffer
{
protected:
	unsigned int bufferID;
public:
	ShaderStorageBuffer(void* data, size_t size, int binding);

	void Bind() { glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID); }
	void Unbind() { glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); }

	void UpdateBuffer(void* data, size_t size);
};