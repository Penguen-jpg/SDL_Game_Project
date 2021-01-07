#pragma once
#include "AssetManager.h"
class Object
{
	public:
		Object(const char *path);
		~Object();

		void draw();//�e�X����

		SDL_Rect getSrc() const;
		SDL_Rect getDest() const;
		SDL_Texture* getTex() const;
		void setSrc (int x, int y, int w, int h);
		void setDest(int x, int y, int w, int h);
		void setTex(const char *path);
	protected:
		SDL_Rect src;//�ӷ����
		SDL_Rect dest;//�ؼФ��
		SDL_Texture *texture;//�Ϥ�
		int SCALE_FACTOR;//�Y�񭿼�
		SDL_RendererFlip flip;//½���
};