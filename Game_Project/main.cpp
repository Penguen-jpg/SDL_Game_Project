#include <iostream>
#include "Game.h"
int main(int argc,char *argv[])
{
	Game* game = Game::getInstance();
	//game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT, 0);
	while (game->isRunning())
	{
		//開始計時
		if (game->wantToRestart())
		{
			game->restart();
		}
		Timer::getTimer()->startTimer();

		game->handleEvent();
		game->update();
		game->render();

		//計算一幀時間
		Timer::getTimer()->calFrameTime();
		//std::cout << "deltaTime: " << Timer::getTimer()->getDeltaTime() << std::endl;
		Timer::getTimer()->increaseFrameCount();
		//std::cout << "frameTime: " << Game::timer->getFrameTime() << std::endl;
		//std::cout << "deltaTime: " << Game::timer->getDeltaTime() << std::endl;

	}
	game->release();
	return 0;

}