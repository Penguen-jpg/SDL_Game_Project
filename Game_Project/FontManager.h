#pragma once
#include "Game.h"
#include <map>
class FontManager
{
	public:
		FontManager();
		~FontManager();

		void addFont(const char* path, int size);
		void closeFonts();

		TTF_Font* getFont(int size) const;
	private:
		std::map<std::string, TTF_Font*> fonts;
};