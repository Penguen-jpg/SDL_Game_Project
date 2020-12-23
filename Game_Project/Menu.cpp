#include "Menu.h"
Menu* Menu::menu = NULL;

Menu::Menu()
	:playing(false)
{
	texture = AssetManager::getAssetManager()->getTexture("assets/menu.png"); //¸ü¤J¹Ï¤ù
}

Menu::~Menu()
{

}

Menu * Menu::getMenu()
{
	if (menu == NULL)
	{
		menu = new Menu();
	}
	return menu;
}

void Menu::release()
{
	delete menu;
	menu = NULL;
}

void Menu::checkClicked()
{
	if (EventManager::getEventManager()->play())
	{
		playing = true;
	}
	else
	{
		playing = false;
	}
}

void Menu::drawMenu()
{
	Graphics::getGraphics()->draw(texture);
}

bool Menu::isPlaying()
{
	return playing;
}
