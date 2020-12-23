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
		SDL_Rect labelRect;//�r�����
		SDL_Texture* labelTexture;//�r���Ϥ�
};