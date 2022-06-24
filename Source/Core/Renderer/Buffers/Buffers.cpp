#include "Buffers.h"

UniformBuffer::UniformBuffer(void* data, size_t size, int binding)
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
