#include "TextureManager.h"

SDL_Texture * TextureManager::LoadTexture(const char * path)
{
	SDL_Texture* texture = IMG_LoadTexture(Game::getInstance()->getRenderer(), path);//載入圖片
	if (texture == NULL)
	{
		std::cout << "failed to load texture\n";
		return NULL;
	}
	return texture;
}

void TextureManager::draw(SDL_Texture * texture, SDL_Rect* src, SDL_Rect* dest, SDL_RendererFlip flip)
{
	//相對於鏡頭做平移
	//dest->x -= Game::camera.x;
	//dest->y -= Game::camera.y;

	SDL_RenderCopyEx(Game::getInstance()->getRenderer(), texture, src, dest, NULL, NULL, flip);
}

