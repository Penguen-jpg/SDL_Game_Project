#pragma once
#include "Timer.h"
#include "Map.h"
#include "Player.h"
#include "Mob.h"
#include "Label.h"
#include "AudioManager.h"
#include "EventManager.h"
#include "Menu.h"
#include <iostream>
#include <cmath>
class Game
{
	public:
		static Game* getInstance();
		static void release();
		bool isRunning() const;//遊戲是否進行中
		void handleEvent();//處理事件
		void update();//更新
		void render();//渲染
		void restart();//重新開始遊戲
		bool wantToRestart();//是否要重新開始
	private:
		Game();
		~Game();

		static Game* game;//遊戲本體
		Graphics* graphics;//畫面
		Menu* menu;//主選單
		EventManager* eventManager;//事件管理員
		Map* map;//地圖
		Player* player;//角色
		Label* gameOverLabel;//輸掉時顯示的文字
		Label* winLabel;//贏的時候顯示的文字
		Label* playerHp;//玩家血量
		int goal;//勝利條件

		bool running;//遊戲是否進行中
		bool gameOver() const;//檢查是否遊戲結束
		bool victory() const;//檢查是否勝利
		bool re;//是否要重新開始
};