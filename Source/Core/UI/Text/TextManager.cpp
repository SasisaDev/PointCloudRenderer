#include "TextManager.h"

std::vector<Font> TextManager::Fonts = std::vector<Font>();

const Font& TextManager::GetFont(std::string Name)
{
	for (const Font& font: Fonts)
	{
		if (font.Name._Equal(Name))
		{
			return font;
		}
	}

	return NULL;
}
