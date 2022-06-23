#pragma once

#include <GL/glew.h>
#include "../../Debug/Logger.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stbi_image.h>

class Texture2D
{
protected:
	unsigned int TextureID;
public:
	Texture2D(int w, int h, int mode);
	Texture2D(std::string filename);

	unsigned int GetTextureID() { return TextureID; }
};

