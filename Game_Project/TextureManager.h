#pragma once
#include "Game.h"
#include <iostream>
#include "SDL_image.h"
class TextureManager
{
	public:
		//���Jtextur
		static SDL_Texture* LoadTexture(const char* path);

		//�e�Xtexture
		static void draw(SDL_Texture* texture, SDL_Rect* src = NULL, SDL_Rect* dest = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};