#include "Game.h"
Game* Game::game = NULL;
/*
未來目標:
1.做出記分板(ScoreBoard.h)
2.可能會多做幾種怪物
*/
Game::Game()
{
	running = false;
	graphics = Graphics::getGraphics();
	if (graphics->isInitialized())
	{
		running = true;
	}
	AudioManager::getAudioManager()->playMusic("music/bgm2.wav", -1);
	menu = Menu::getMenu();
	eventManager = EventManager::getEventManager();
	goal = 10;
	map = Map::getMap();
	player = Player::getPlayer();
	Mob::spawn();
	gameOverLabel = new Label("Game Over!!", "font/joystix.ttf", 35, { 255, 255, 255 }, Graphics::WINDOW_WIDTH / 2 - 120, Graphics::WINDOW_HEIGHT / 2 - 100);
	winLabel = new Label("Victory!!", "font/joystix.ttf", 35, { 255, 255, 255 }, Graphics::WINDOW_WIDTH / 2 - 90, Graphics::WINDOW_HEIGHT / 2 - 100);
	playerHp = new Label("HP: ", "font/joystix.ttf", 35, { 255, 255, 255 }, 0, 0);
}
Game::~Game()
{
	menu->release();
	AssetManager::release();
	InputManager::release();
	AudioManager::release();
	Timer::release();
	player->release();
	Mob::release();
	map->release();
	delete gameOverLabel;
	gameOverLabel = NULL;
	delete winLabel;
	winLabel = NULL;
	graphics->release();
}

Game * Game::getInstance()
{
	if (game == NULL)
	{
		game = new Game();
	}
	return game;
}

void Game::release()
{
	delete game;
	game = NULL;
}

bool Game::isRunning() const
{
	return running;
}

void Game::handleEvent()
{
	eventManager->pollEvent();
	if (eventManager->quit())
	{
		running = false;
	}
	if (!menu->isPlaying())
	{
		menu->checkClicked();
	}
	if (InputManager::getInputManager()->isTriggered(SDL_SCANCODE_R))
	{
		re = true;
	}
	else
	{
		re = false;
	}
}

void Game::update()
{
	if (menu->isPlaying())
	{
		InputManager::getInputManager()->updateKeystate();
		if (!player->isDead())
		{
			player->update();
		}
		graphics->moveCamera(player->getDest().x, player->getDest().y);
		if (Timer::getTimer()->getFrameCount() % 200 == 0 && Mob::NUMBER_OF_MOBS < goal)
		{
			Mob::spawn();
		}
		for (int n = 0; n < Mob::NUMBER_OF_MOBS; n++)
		{
			if (!Mob::mobs[n]->isDead())
			{
				Mob::mobs[n]->update();
			}
		}
		map->updateMap();
	}
}

void Game::render()
{
	graphics->renderClear();
	if (menu->isPlaying())
	{
		map->drawMap();

		player->draw();
		for (int n = 0; n < Mob::NUMBER_OF_MOBS; n++)
		{
			if (!Mob::mobs[n]->isDead())
			{
				Mob::mobs[n]->draw();
			}
		}
		playerHp->setText("HP: " + std::to_string(player->getStatus().hp), { 255,255,255 }, "font/joystix.tff", 35);
		playerHp->drawLabel();
		if (victory())
		{
			winLabel->drawLabel();
		}
		else if (gameOver())
		{
			gameOverLabel->drawLabel();
		}
	}
	else
	{
		menu->drawMenu();
	}
	graphics->renderPresent();
}

void Game::restart()//暫定為完成
{
	Mob::release();
	Timer::getTimer()->resetTimer();
	player->resetAnimation(3);
	player->init();
	Mob::spawn();
}

bool Game::wantToRestart()
{
	if (re)
	{
		re = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::gameOver() const
{
	if (player->getStatus().hp < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::victory() const
{
	if (Mob::NUMBER_OF_KILLED_MOBS == goal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

