#pragma once
#include "AssetManager.h"
class Object
{
	public:
		Object(const char *path);
		~Object();

		void draw();//畫出物件

		SDL_Rect getSrc() const;
		SDL_Rect getDest() const;
		SDL_Texture* getTex() const;
		void setSrc (int x, int y, int w, int h);
		void setDest(int x, int y, int w, int h);
		void setTex(const char *path);
	protected:
		SDL_Rect src;//來源方塊
		SDL_Rect dest;//目標方塊
		SDL_Texture *texture;//圖片
		int SCALE_FACTOR;//縮放倍數
		SDL_RendererFlip flip;//翻轉用
};