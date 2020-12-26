#pragma once
#include "AssetManager.h"
#include "EventManager.h"
class Menu 
{
	public:
		static Menu* getMenu();
		void release();
		void checkClicked();//�ˬd�O�_���I����s
		void drawMenu();//�e�X�D���
		bool isPlaying();//�O�_���b�C��
	private:
		Menu();
		~Menu();

		static Menu* menu;//�D���
		bool playing;//�O�_�I��play
		SDL_Texture* texture;//�D���Ϥ�
};