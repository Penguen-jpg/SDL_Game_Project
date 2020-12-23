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
		
		static AssetManager* assetManager;//�޲z��
		std::map<const char*, SDL_Texture*> textures;//�x�stexture
		std::map<int, TTF_Font*> fonts;//�x�s�r��
		std::map<std::string, SDL_Texture*> texts;//�x�s��r
		std::map<const char*, Mix_Music*> musics;//�x�s����
		std::map<const char*, Mix_Chunk*> SFX;//�x�s����

		TTF_Font* getFont(const char* path, int size);//�����r��
};