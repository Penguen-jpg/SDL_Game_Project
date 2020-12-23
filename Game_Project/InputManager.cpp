#include "InputManager.h"
InputManager* InputManager::inputManager = NULL;

InputManager::InputManager()
{
	if (!initKeystate())
	{
		std::cout << "failed to initialize keystates!\n";
	}
}

InputManager::~InputManager()
{

}

InputManager * InputManager::getInputManager()
{
	if (inputManager == NULL)
	{
		inputManager = new InputManager();
	}
	return inputManager;
}

void InputManager::release()
{
	delete inputManager;
	inputManager = NULL;
}

bool InputManager::initKeystate()
{
	//1.將紀錄上一幀的陣列初始化成0  2.將keyboard state複製到keystate陣列
	return (memset(&preKeystate, 0, sizeof(Uint8)* SDL_NUM_SCANCODES) 
		 && memcpy(&keystate, SDL_GetKeyboardState(NULL), sizeof(Uint8) *SDL_NUM_SCANCODES));
}

void InputManager::updateKeystate()
{
	//將這一幀的keystate複製到上一幀的keystate
	memcpy(&preKeystate, &keystate, sizeof(Uint8)* SDL_NUM_SCANCODES);

	//將keyboard state複製到keystate陣列
	memcpy(&keystate, SDL_GetKeyboardState(NULL), sizeof(Uint8) *SDL_NUM_SCANCODES);
}

bool InputManager::isTriggered(const SDL_Scancode keycode) const
{
	//如果上一幀沒按，但這一幀按了，代表觸發此按鍵
	return (keystate[keycode] == 1 && preKeystate[keycode] == 0);
}

bool InputManager::isKeyPressed(const SDL_Scancode keycode) const
{
	//此按鍵被按下
	return (keystate[keycode] == 1);
}

bool InputManager::isKeyReleased(const SDL_Scancode keycode) const
{
	//如果上一幀有按，但這一幀沒按，代表放開此按鍵
	return (keystate[keycode] == 0 && preKeystate[keycode] == 1);
}
