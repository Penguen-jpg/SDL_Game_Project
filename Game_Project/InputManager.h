#pragma once
#include "SDL.h"
#include <iostream>
class InputManager
{
	public:
		static InputManager* getInputManager();
		static void release();
		bool initKeystate();//��l��keystate
		void updateKeystate();//��skeystae
		bool isTriggered(const SDL_Scancode keycode) const;//Ĳ�o������key
		bool isKeyPressed(const SDL_Scancode keycode) const;//���U������key
		bool isKeyReleased(const SDL_Scancode keycode) const;//��}������key
	private:
		InputManager();
		~InputManager();

		static InputManager* inputManager;//�B�z��L�M�ƹ���J
		Uint8 keystate[SDL_NUM_SCANCODES];//�o�@�V��keystate
		Uint8 preKeystate[SDL_NUM_SCANCODES];//�W�@�V��keystate
};