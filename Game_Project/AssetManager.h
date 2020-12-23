#pragma once
#include "Graphics.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <map>
#include <string>
class AssetManager
{
	public:
		static AssetManager* getAssetManager();
		static void release();
		SDL_Texture* getTexture(const char* path);
		SDL_Texture* getText(std::string text, SDL_Color color, const char* path, int size);
		Mix_Music* getMusic(const char* path);
		Mix_Chunk* getSFX(const char* path);
	private:
		AssetManager();
		~AssetManager();
		
		static AssetManager* assetManager;//管理員
		std::map<const char*, SDL_Texture*> textures;//儲存texture
		std::map<int, TTF_Font*> fonts;//儲存字型
		std::map<std::string, SDL_Texture*> texts;//儲存文字
		std::map<const char*, Mix_Music*> musics;//儲存音樂
		std::map<const char*, Mix_Chunk*> SFX;//儲存音效

		TTF_Font* getFont(const char* path, int size);//拿取字型
};