#include "Texture2D.h"
#include "..\..\Renderer\Texture\Texture.h"

STexture2D::STexture2D(std::string name, std::string texturePath)
	:SObject(name)
{
}

STexture2D::~STexture2D()
{
	delete texture;
}

void STexture2D::Bind(int tex)
{
}

void STexture2D::Unbind()
{
}