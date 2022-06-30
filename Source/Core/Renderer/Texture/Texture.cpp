#include "Texture.h"

Texture2D::Texture2D(int w, int h, int mode)
{
}

Texture2D::Texture2D(std::string filename)
{
	/*int width, height, channels;
	unsigned char* img = stbi_load(filename.c_str(), &width, &height, &channels, 4);
	if (img == nullptr)
	{
		Logger::Log("Unable to load image: " + std::string("\"") + filename + std::string("\""));
	}
	else
	{
		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE, TextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	}

	stbi_image_free(img);*/
}
