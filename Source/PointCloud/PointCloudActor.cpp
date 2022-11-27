#include "PointCloudActor.h"

void SPointCloudActor::RebuildMesh()
{
	if (!PointCloud)
	{
		//TODO: Log
		return;
	}
	

	instances = 0;
	for (CloudPoint point : PointCloud->GetPoints()) 
	{
		PointCloudSSBO.colors.push_back(glm::vec4(point.color, 1));
		PointCloudSSBO.positions.push_back(glm::translate(glm::mat4(1), point.position));
		instances++;
	}


	BytedPointCloudSSBO* bpc = new BytedPointCloudSSBO[instances];

	for (int i = 0; i < instances; i++)
	{
		bpc[i].positions = PointCloudSSBO.positions[i];
		bpc[i].colors = PointCloudSSBO.colors[i];
	}
	
	
	//memcpy_s(bpc->positions, sizeof(glm::vec3) * PointCloudSSBO.positions.size(), PointCloudSSBO.positions.data(), sizeof(glm::vec3) * PointCloudSSBO.positions.size());
	//memcpy_s(bpc->colors, sizeof(glm::vec4) * PointCloudSSBO.colors.size(), PointCloudSSBO.colors.data(), sizeof(glm::vec4) * PointCloudSSBO.colors.size());

	size_t sizeglm = sizeof(glm::vec4);
	size_t size = sizeof(BytedPointCloudSSBO) * instances;
	//ssbo = new ShaderStorageBuffer(bpc, size, 3);
	ssbo->UpdateBuffer(bpc, size);
}

int SPointCloudActor::Render()
{
	if (instances > 0)
	{
		glBindVertexArray(VAO);

		indices->Bind();
		vertices->Bind();
		glEnableVertexAttribArray(0);
		//glEnableVertexAttribArray(1);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(sizeof(float) * 3));

		texture->Bind(0);

		ssbo->Bind();

		glUseProgram(material->GetProgramID());

		//material->SetUniform1i("tex", 0);

		glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, instances);

		//glDisableVertexAttribArray(0);
		//glDisableVertexAttribArray(1);

		//glBindVertexArray(0);
	}
	return 1;
}
