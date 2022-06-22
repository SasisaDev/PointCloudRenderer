#pragma once

#include "../Object.h"

class STexture2D : public SObject
{
public:
	GENERATED_BODY(STexture2D)
	STexture2D(std::string name, std::string texturePath);
};