#include "AssetManager.h"
AssetManager* AssetManager::assetManager = NULL;

AssetManager::AssetManager()
{
	
}

AssetManager::~AssetManager()
{
	std::map<const char*, SDL_Texture*>::iterator it;
	std::map<int, TTF_Font*>::iterator it2;
	std::map<std::string, SDL_Texture*>::iterator it3;
	std::map<const char*, Mix_Music*>::iterator it4;
	std::map<const char*, Mix_Chunk*>::iterator it5;
	for (it=textures.begin();it!=textures.end();it++)
	{
		SDL_DestroyTexture(it->second);
	}
	textures.clear();
	for (it2 = fonts.begin(); it2 != fonts.end(); it2++)
	{
		TTF_CloseFont(it2->second);
	}
	fonts.clear();
	for (it3 = texts.begin(); it3 != texts.end(); it3++)
	{
		SDL_DestroyTexture(it3->second);
	}
	texts.clear();
	for (it4 = musics.begin(); it4 != musics.end(); it4++)
	{
		Mix_FreeMusic(it4->second);
	}
	musics.clear();
	for (it5 = SFX.begin(); it5 != SFX.end(); it5++)
	{
		Mix_FreeChunk(it5->second);
	}
	SFX.clear();
}

AssetManager * AssetManager::getAssetManager()
{
	if (assetManager == NULL)
	{
		assetManager = new AssetManager();
	}
	return assetManager;
}

void AssetManager::release()
{
	delete assetManager;
	assetManager = NULL;
}

SDL_Texture * AssetManager::getTexture(const char * path)
{
	if (textures[path] == NULL)
	{
		textures[path] = Graphics::getGraphics()->loadTexture(path);
	}
	return textures[path];
}

SDL_Texture * AssetManager::getText(std::string text, SDL_Color color, const char * path, int size)
{
	TTF_Font* font = getFont(path, size);
	if (texts[text] == NULL)
	{
		texts[text] = Graphics::getGraphics()->loadTextTexture(font, text, color);
	}
	return texts[text];
}

Mix_Music * AssetManager::getMusic(const char * path)
{
	if (musics[path] == NULL)
	{
		musics[path] = Mix_LoadMUS(path);
	}
	return musics[path];
}

Mix_Chunk * AssetManager::getSFX(const char * path)
{
	if (SFX[path] == NULL)
	{
		SFX[path] = Mix_LoadWAV(path);
	}
	return SFX[path];
}

TTF_Font * AssetManager::getFont(const char* path, int size)
{
	if (fonts[size] == NULL)
	{
		fonts[size] = TTF_OpenFont(path, size);
	}
	return fonts[size];
}
