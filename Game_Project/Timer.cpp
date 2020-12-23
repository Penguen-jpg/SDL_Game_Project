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
	deltaTime = frameTime * 0.001f;//�ഫ����
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
	if (!pause && start)//�p�G���Ȱ��B�C���i�椤
	{
		pause = true;//�аO���Ȱ�
		pauseTime = SDL_GetTicks() - frameStart;//�����Ȱ��ɶ�
		frameStart = 0;
	}
}

void Timer::unpauseTimer()
{
	if (pause&&start)//�p�G�Ȱ��B�C���i�椤
	{
		pause = false;//�аO�����Ȱ�
		frameStart = SDL_GetTicks() - pauseTime;//����W���Ȱ����᪺�ɶ��~��
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
