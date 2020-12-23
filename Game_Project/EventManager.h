#pragma once
#include "SDL.h"
class EventManager
{
	public:
		static EventManager* getEventManager();
		static void release();
		void pollEvent();
		bool mouseClicked();
		bool play();//�I��}�l
		bool quit();//�I��h�X�Τe�e
	private:
		EventManager();
		~EventManager();

		static EventManager* eventManager;//�ƥ�޲z��
		SDL_Event event;//�ƥ�
};