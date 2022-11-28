#pragma once

#include <map>
#include <vector>
#include <string>
#include <ft2build.h>
#include "../../Renderer/Texture/Texture.h"
#include "../../Types/SmartPointers.h"

#pragma comment(lib, "freetype.lib")

struct FontCharacter
{
	unsigned int X, Y;
	unsigned int Width, Height;
};

struct Font
{
	std::string Name;
	std::map<char, FontCharacter> Characters;
	TObject<Texture2D> Atlas;

	Font(int){}
};

class ITextManager
{
	static ITextManager* Singleton;
	ITextManager();

	friend class Engine;
protected:
	std::vector<Font> Fonts;
public:

	static ITextManager* Get() { return Singleton; }

	const Font& GetFont(std::string Name);

	const Font& LoadFont(/*TODO*/);
};

