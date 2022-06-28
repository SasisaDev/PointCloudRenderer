#include "Buffers.h"

UniformBuffer::UniformBuffer(void* data, size_t size, int binding)
	: Binding(binding)
{
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_UNIFORM_BUFFER, bufferID);
	glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, binding, bufferID);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void UniformBuffer::UpdateBuffer(void* data, size_t offset, size_t size)
{
	glBindBuffer(GL_UNIFORM_BUFFER, bufferID);
	//glMapBufferRange(GL_UNIFORM_BUFFER, offset, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);
	glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &bufferID);
}

VertexBuffer::VertexBuffer(std::vector<float> data)
{
	glGenBuffers(1, &bufferID);
	SetData(data);
}

VertexBuffer::~VertexBuffer()
{
	if (bufferID > 0)
	{
		glDeleteBuffers(1, &bufferID);
	}
}

void VertexBuffer::SetData(std::vector<float> data)
{
	vertices = data;
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer()
{
	glGenBuffers(1, &bufferID);
}

IndexBuffer::IndexBuffer(std::vector<int> data)
{
	glGenBuffers(1, &bufferID);
	SetData(data);
}

IndexBuffer::~IndexBuffer()
{
	if (bufferID > 0)
	{
		glDeleteBuffers(1, &bufferID);
	}
}

void IndexBuffer::SetData(std::vector<int> data)
{
	indices = data;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), indices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

ShaderStorageBuffer::ShaderStorageBuffer(void* data, size_t size, int binding)
	: Binding(binding)
{
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, binding, bufferID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void ShaderStorageBuffer::UpdateBuffer(void* data, size_t size)
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}
