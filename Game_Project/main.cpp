#include <iostream>
#include "Game.h"
int main(int argc,char *argv[])
{
	Game* game = Game::getInstance();
	while (game->isRunning())
	{
		//���s�}�l
		if (game->wantToRestart())
		{
			game->restart();
		}

		//�}�l�p��
		Timer::getTimer()->startTimer();

		game->handleEvent();
		game->update();
		game->render();

		//�p��@�i�e�����ɶ�
		Timer::getTimer()->calFrameTime();
		Timer::getTimer()->increaseFrameCount();

	}
	game->release();
	return 0;

}