#pragma once
#include "SDL.h"
#include <iostream>
class InputManager
{
	public:
		static InputManager* getInputManager();
		static void release();
		bool initKeystate();//初始化keystate
		void updateKeystate();//更新keystae
		bool isTriggered(const SDL_Scancode keycode) const;//觸發對應的key
		bool isKeyPressed(const SDL_Scancode keycode) const;//按下對應的key
		bool isKeyReleased(const SDL_Scancode keycode) const;//放開對應的key
	private:
		InputManager();
		~InputManager();

		static InputManager* inputManager;//處理鍵盤和滑鼠輸入
		Uint8 keystate[SDL_NUM_SCANCODES];//這一幀的keystate
		Uint8 preKeystate[SDL_NUM_SCANCODES];//上一幀的keystate
};