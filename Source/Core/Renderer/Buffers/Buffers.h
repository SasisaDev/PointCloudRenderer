#pragma once

#include <GL/glew.h>
#include <cstddef>

class VertexBuffer
{

};

class IndexBuffer
{

};

class UniformBuffer
{
protected:
	unsigned int bufferID;
public:
	UniformBuffer(void* data, size_t size, int binding);

	void UpdateBuffer(void* data, size_t offset, size_t size);
};