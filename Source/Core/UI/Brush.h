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
		glm::mat4 Model;
		glm::vec4 Tint;
	} ssboData;

	void UpdateSSBO();

	STexture2D* texture;
	TColor tint;
	static SMaterial* material;

public:
	SBrush(std::string name);
	SBrush(std::string name, STexture2D* tex, TColor Tint = glm::vec4(1.0f));
public:

	void SetTexture(STexture2D* tex) { texture = tex; UpdateSSBO(); }
	STexture2D* GetTexture() const { return texture; }

	void SetTint(TColor _tint) { tint = _tint; UpdateSSBO(); }
	TColor GetTint() const { return tint; }

	void SetModel(glm::mat4 model) { ssboData.Model = model; UpdateSSBO(); }

	void Bind(int textureSlot);
	void Unbind();
};

