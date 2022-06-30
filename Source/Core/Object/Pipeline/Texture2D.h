#pragma once

#include "../Object.h"
#include "../../Renderer/Texture/Texture.h"

class STexture2D : public SObject
{
protected:
	Texture2D* texture = nullptr;
public:
	GENERATED_BODY(STexture2D)
	STexture2D(std::string name, std::string texturePath);
	~STexture2D();

	void Bind(int tex);
	void Unbind();

	unsigned int GetTextureID() { return texture->GetTextureID(); }
};