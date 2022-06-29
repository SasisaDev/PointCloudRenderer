#include "Brush.h"

SMaterial* SBrush::material = nullptr;

void SBrush::UpdateSSBO()
{
	ssboData.Tint = tint;

	ssbo->UpdateBuffer(&ssboData, sizeof(ssboData));
}

SBrush::SBrush(std::string name)
	: SObject(name)
{
	if (SBrush::material == nullptr)
	{
		material = new SMaterial("BrushMaterial", "Shaders/UI/Brush");
	}

	ssbo = new ShaderStorageBuffer(0, 0, 3);
}

SBrush::SBrush(std::string name, STexture2D* tex, TColor Tint)
	: SObject(name)
{
	if (SBrush::material == nullptr)
	{
		material = new SMaterial("BrushMaterial", "Shaders/UI/Brush");
	}

	texture = tex;
	tint = Tint;

	ssbo = new ShaderStorageBuffer(0, 0, 3);
}

void SBrush::Bind(int textureSlot)
{
	//glActiveTexture(GL_TEXTURE0 + textureSlot);
	texture->Bind(textureSlot);
	ssbo->Bind();
	material->Use();
	//material->SetUniform1i("Texture", textureSlot);
	//material->SetUniform4f("Tint", tint.r, tint.g, tint.b, tint.a);
	glEnableVertexAttribArray(glGetAttribLocation(material->GetProgramID(), "Position"));
	glVertexAttribPointer(
		glGetAttribLocation(material->GetProgramID(), "Position"),  // attribute
		3,                  // number of elements per vertex, here (x,y)
		GL_FLOAT,           // the type of each element
		GL_FALSE,           // take our values as-is
		0,                  // no extra data between each position
		0                   // offset of first element
	);
}

void SBrush::Unbind()
{
	glDisableVertexAttribArray(glGetAttribLocation(material->GetProgramID(), "Position"));
	//material->Unuse();
	//texture->Unbind();
	//ssbo->Unbind();
}
