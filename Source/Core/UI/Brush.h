#pragma once

#include "../Object/Object.h"
#include "../Object/Pipeline/Texture2D.h"
#include "../Object/Pipeline/Material.h"
#include "../Types/Color.h"
#include "../Renderer/Buffers/Buffers.h"

class SBrush : public SObject
{
protected:
	ShaderStorageBuffer* ssbo;

	struct {
		glm::vec4 Tint;
		glm::mat4 Model;
	} ssboData;

	STexture2D* texture;
	TColor tint;
	static SMaterial* material;

public:
	SBrush(std::string name);
	SBrush(std::string name, STexture2D* tex, TColor Tint = glm::vec4(1.0f));
public:

	void SetTexture(STexture2D* tex) { texture = tex; }
	STexture2D* GetTexture() const { return texture; }

	void SetTint(TColor _tint) { tint = _tint; }
	TColor GetTint() const { return tint; }

	void SetModel(glm::mat4 model) { ssboData.Model = model; ssbo->UpdateBuffer(&ssboData, sizeof(ssboData)); }
	glm::mat4 GetModel() const { return ssboData.Model; }

	void UpdateSSBO();

	void Bind(int textureSlot);
	void Unbind();
};

