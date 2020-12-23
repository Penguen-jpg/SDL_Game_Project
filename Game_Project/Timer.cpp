#include "Timer.h"
Timer* Timer::timer = NULL;

Timer::Timer()
	:frameStart(0), frameTime(0.0f), deltaTime(0.0f), frameCount(0)
{

}

Timer::~Timer()
{

}

Timer * Timer::getTimer()
{
	if (timer == NULL)
	{
		timer = new Timer();
	}
	return timer;
}

void Timer::release()
{
	delete timer;
	timer = NULL;
}

void Timer::startTimer()
{
	//start = true;
	//pause = false;
	frameStart = SDL_GetTicks();
	//pauseTime = 0;
}

void Timer::resetTimer()
{
	frameStart = 0;
	frameTime = 0.0f;
	deltaTime = 0.0f;
	frameCount = 0;
	//pauseTime = 0;
	//pause = false;
	//start = false;
}

void Timer::calFrameTime()
{
	frameTime = SDL_GetTicks() - frameStart;
	deltaTime = frameTime * 0.001f;//轉換成秒
}

/*void Timer::capFPS()
{
	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
}*/

/*void Timer::pauseTimer()
{
	if (!pause && start)//如果未暫停且遊戲進行中
	{
		pause = true;//標記為暫停
		pauseTime = SDL_GetTicks() - frameStart;//紀錄暫停時間
		frameStart = 0;
	}
}

void Timer::unpauseTimer()
{
	if (pause&&start)//如果暫停且遊戲進行中
	{
		pause = false;//標記為未暫停
		frameStart = SDL_GetTicks() - pauseTime;//接續上次暫停之後的時間繼續
		deltaTime = frameStart * 0.001f;
		pauseTime = 0;
	}
}*/

void Timer::increaseFrameCount()
{
	frameCount++;
}

float Timer::getDeltaTime()
{
	return deltaTime;
}

int Timer::getFrameTime()
{
	return frameTime;
}

Uint32 Timer::getFrameCount()
{
	return frameCount;
}

/*bool Timer::isPausing()
{
	return pause;
}

bool Timer::isStarting()
{
	return start;
}*/
