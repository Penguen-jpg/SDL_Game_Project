#include "FontManager.h"

FontManager::FontManager()
{

}

FontManager::~FontManager()
{
	fonts.clear();
}

void FontManager::addFont(int index,const char * path, int size)
{
	fonts.emplace("0", TTF_OpenFont(path, size));
}

void FontManager::closeFonts()
{
	fonts.clear();
}

TTF_Font * FontManager::getFont(int size) const
{
	return fonts[size];
}
