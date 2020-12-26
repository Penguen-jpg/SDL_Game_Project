#include <iostream>
#include "Game.h"
int main(int argc,char *argv[])
{
	Game* game = Game::getInstance();
	while (game->isRunning())
	{
		//重新開始
		if (game->wantToRestart())
		{
			game->restart();
		}

		//開始計時
		Timer::getTimer()->startTimer();

		game->handleEvent();
		game->update();
		game->render();

		//計算一張畫面的時間
		Timer::getTimer()->calFrameTime();
		Timer::getTimer()->increaseFrameCount();

	}
	game->release();
	return 0;

}