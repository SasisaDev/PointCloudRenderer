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
}

void SBrush::Unbind()
{
	//glDisableVertexAttribArray(glGetAttribLocation(material->GetProgramID(), "Position"));
	//material->Unuse();
	//texture->Unbind();
	//ssbo->Unbind();
}
