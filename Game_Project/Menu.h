#pragma once
#include "AssetManager.h"
#include "EventManager.h"
class Menu 
{
	public:
		static Menu* getMenu();
		void release();
		void checkClicked();//檢查是否有點選按鈕
		void drawMenu();//畫出主選單
		bool isPlaying();//是否正在遊玩
	private:
		Menu();
		~Menu();

		static Menu* menu;//主選單
		bool playing;//是否點選play
		SDL_Texture* texture;//主選單圖片
};