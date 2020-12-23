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
		bool init(const char * title, int x, int y, bool fullscreen);//��l��
		bool isInitialized() const;//�^�Ǫ�l�ƬO�_���\
		SDL_Texture* loadTexture(const char* path);//���Jtexture
		void draw(SDL_Texture* texture, SDL_Rect* src = NULL, SDL_Rect* dest = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);//�e�Xtexture
		SDL_Texture* loadTextTexture(TTF_Font* font, std::string text, SDL_Color color);//���J�T��texture
		void moveCamera(int x, int y);//�������Y(��e�����߰�����)
		void renderClear();//�M�Ŵ�V��
		void renderPresent();//�e�{�e��
		void fillRect(SDL_Rect* rect);
		
		//�����e�B��
		static const int WINDOW_WIDTH = 800;
		static const int WINDOW_HEIGHT = 640;
		static const int LEVEL_WIDTH = 1280;
		static const int LEVEL_HEIGHT = 960;
	private:
		Graphics();
		~Graphics();

		static Graphics* graphics;//�C���e��
		SDL_Window* window;//����
		SDL_Renderer* renderer;//��V��
		SDL_Rect camera;//���Y
		bool initialized;//�O�_��l�Ʀ��\
};