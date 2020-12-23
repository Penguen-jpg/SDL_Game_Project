#pragma once
#include "AssetManager.h"
class Label
{
	public:
		Label(std::string text, const char * path, int size, SDL_Color color, int x, int y);
		~Label();

		void setText(std::string text, SDL_Color color, const char* path, int size);
		void drawLabel();
	private:
		SDL_Rect labelRect;//字的方塊
		SDL_Texture* labelTexture;//字的圖片
};