#include "TextManager.h"

ITextManager* ITextManager::Singleton = nullptr;

const Font& ITextManager::GetFont(std::string Name)
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

ITextManager::ITextManager()
{
	if (ITextManager::Singleton) {
		ITextManager::Singleton = this;
	}
}
