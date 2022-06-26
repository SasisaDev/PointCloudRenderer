#include "PointCloudActor.h"

void SPointCloudActor::RebuildMesh()
{
	/*if (PointCloud)
	{
		for (auto point : PointCloud->GetPoints())
		{


			
		}

		BytedPointCloudSSBO bpc;
		bpc.positions = PointCloudSSBO.positions.data();
		bpc.colors = PointCloudSSBO.colors.data();
		ssbo->UpdateBuffer(&bpc, (sizeof(glm::vec3) + sizeof(glm::vec4) * instances));
	}*/

	vertices->SetData(std::vector<float> {
		0, 1, 0, 0, 0,
		1, 1, 0, 1, 0,
		0, 0, 0, 0, 1,
		1, 0, 0, 1, 1,
		1, 1, 0, 1, 0,
		0, 0, 0, 0, 1,
	});

	indices->SetData(std::vector<int> {
		0, 1, 2, 3, 4, 5
	});

	instances = 1;

	PointCloudSSBO.colors = { glm::vec4(1.0f) };
	PointCloudSSBO.positions = { glm::vec3(0.0f) };

	BytedPointCloudSSBO bpc;
	bpc.positions = PointCloudSSBO.positions.data();
	bpc.colors = PointCloudSSBO.colors.data();
	ssbo->UpdateBuffer(&bpc, (sizeof(glm::vec3) + sizeof(glm::vec4) * instances));
}

int SPointCloudActor::Render()
{
	if (instances > 0)
	{
		//glBindVertexArray(VAO);

		glUseProgram(material->GetProgramID());

		ssbo->Bind();

		vertices->Bind();
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * 3));

		texture->Bind(0);
		material->SetUniform1i("tex", 0);

		indices->Bind();

		glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, instances);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glUseProgram(0);

		vertices->Unbind();

		indices->Unbind();

		ssbo->Unbind();
		texture->Unbind();

		//glBindVertexArray(0);
	}
	return 1;
}
