#pragma once

#include "../Object/Object.h"
#include "../Object/Pipeline/Texture2D.h"
#include "../Object/Pipeline/Material.h"
#include "../Types/Color.h"

class SBrush : public SObject
{
public:
	SBrush(std::string name);
	SBrush(std::string name, STexture2D* tex, TColor Tint = glm::vec4(1.0f));

	STexture2D* texture;
	static SMaterial* material;
	TColor tint;
public:

	void Bind(int textureSlot);
	void Unbind();
};

