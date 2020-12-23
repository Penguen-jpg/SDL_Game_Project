#pragma once
#include "SDL.h"
class EventManager
{
	public:
		static EventManager* getEventManager();
		static void release();
		void pollEvent();
		bool mouseClicked();
		bool play();//點選開始
		bool quit();//點選退出或叉叉
	private:
		EventManager();
		~EventManager();

		static EventManager* eventManager;//事件管理員
		SDL_Event event;//事件
};