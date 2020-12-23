#include "EventManager.h"
EventManager* EventManager::eventManager = NULL;

EventManager::EventManager()
{

}

EventManager::~EventManager()
{
	
}

EventManager * EventManager::getEventManager()
{
	if (eventManager == NULL)
	{
		eventManager = new EventManager();
	}
	return eventManager;
}

void EventManager::release()
{
	delete eventManager;
	eventManager = NULL;
}

void EventManager::pollEvent()
{
	SDL_PollEvent(&event);
}

bool EventManager::mouseClicked()
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EventManager::play()
{
	if (event.button.x >= 110 && event.button.x <= 340 && event.button.y >= 400 && event.button.y <= 500 && mouseClicked())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EventManager::quit()
{
	if (event.type == SDL_QUIT)
	{
		return true;
	}
	else if (event.button.x >= 465 && event.button.x <= 700 && event.button.y >= 400 && event.button.y <= 500 && mouseClicked())
	{
		return true;	
	}
	else
	{
		return false;
	}
}
