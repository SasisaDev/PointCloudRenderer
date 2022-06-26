#include "PointCloudActor.h"

void SPointCloudActor::RebuildMesh()
{
	if (PointCloud)
	{
		
	}
}

int SPointCloudActor::Render()
{
	vertices->Bind();
	glEnableVertexArrayAttrib(vertices->GetID(), 0);
	glEnableVertexArrayAttrib(vertices->GetID(), 1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * 3));

	indices->Bind();

	glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, instances);

	indices->Unbind();

	glDisableVertexArrayAttrib(vertices->GetID(), 0);
	glDisableVertexArrayAttrib(vertices->GetID(), 1);
	vertices->Unbind();

	return 1;
}
