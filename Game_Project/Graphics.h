#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
class Graphics
{
	public:
		static Graphics* getGraphics();
		void release();
		bool init(const char * title, int x, int y, bool fullscreen);//初始化
		bool isInitialized() const;//回傳初始化是否成功
		SDL_Texture* loadTexture(const char* path);//載入texture
		void draw(SDL_Texture* texture, SDL_Rect* src = NULL, SDL_Rect* dest = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);//畫出texture
		SDL_Texture* loadTextTexture(TTF_Font* font, std::string text, SDL_Color color);//載入訊息texture
		void moveCamera(int x, int y);//移動鏡頭(對畫面中心做平移)
		void renderClear();//清空渲染器
		void renderPresent();//呈現畫面
		void fillRect(SDL_Rect* rect);
		
		//視窗寬、高
		static const int WINDOW_WIDTH = 800;
		static const int WINDOW_HEIGHT = 640;
		static const int LEVEL_WIDTH = 1280;
		static const int LEVEL_HEIGHT = 960;
	private:
		Graphics();
		~Graphics();

		static Graphics* graphics;//遊戲畫面
		SDL_Window* window;//視窗
		SDL_Renderer* renderer;//渲染器
		SDL_Rect camera;//鏡頭
		bool initialized;//是否初始化成功
};