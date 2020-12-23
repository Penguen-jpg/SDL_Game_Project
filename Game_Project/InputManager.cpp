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
	//1.�N�����W�@�V���}�C��l�Ʀ�0  2.�Nkeyboard state�ƻs��keystate�}�C
	return (memset(&preKeystate, 0, sizeof(Uint8)* SDL_NUM_SCANCODES) 
		 && memcpy(&keystate, SDL_GetKeyboardState(NULL), sizeof(Uint8) *SDL_NUM_SCANCODES));
}

void InputManager::updateKeystate()
{
	//�N�o�@�V��keystate�ƻs��W�@�V��keystate
	memcpy(&preKeystate, &keystate, sizeof(Uint8)* SDL_NUM_SCANCODES);

	//�Nkeyboard state�ƻs��keystate�}�C
	memcpy(&keystate, SDL_GetKeyboardState(NULL), sizeof(Uint8) *SDL_NUM_SCANCODES);
}

bool InputManager::isTriggered(const SDL_Scancode keycode) const
{
	//�p�G�W�@�V�S���A���o�@�V���F�A�N��Ĳ�o������
	return (keystate[keycode] == 1 && preKeystate[keycode] == 0);
}

bool InputManager::isKeyPressed(const SDL_Scancode keycode) const
{
	//������Q���U
	return (keystate[keycode] == 1);
}

bool InputManager::isKeyReleased(const SDL_Scancode keycode) const
{
	//�p�G�W�@�V�����A���o�@�V�S���A�N���}������
	return (keystate[keycode] == 0 && preKeystate[keycode] == 1);
}
