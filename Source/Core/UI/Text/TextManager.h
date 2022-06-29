#pragma once

#include <map>
#include <vector>
#include <string>
#include <ft2build.h>

#pragma comment(lib, "freetype.lib")

struct FontCharacter
{
	unsigned int TextureID;
	unsigned int Width, Height;
};

struct Font
{
	std::string Name;
	std::map<char, FontCharacter> Characters;

	Font(int){}
};

class TextManager
{
public:
	static std::vector<Font> Fonts;

	static const Font& GetFont(std::string Name);

	static const Font& LoadFont(/*TODO*/);
};

