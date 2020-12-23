#pragma once
#include "SDL.h"
class Timer
{
	public:
		static Timer* getTimer();
		static void release();
		void startTimer();//�}�l�p��
		void resetTimer();//���]�ɶ�
		void calFrameTime();//�p��1�V�ɶ�
		//void capFPS();//����̰�FPS(�S�Ψ�A�]�������}�����P�B�F)
		//void pauseTimer();//�Ȱ��p�ɾ�
		//void unpauseTimer();//���ҭp�ɾ�
		void increaseFrameCount();

		float getDeltaTime();
		int getFrameTime();
		Uint32 getFrameCount();

		//bool isPausing();
		//bool isStarting();
	private:
		Timer();
		~Timer();

		static Timer* timer;//�p�ɾ�
		//const int FPS = 60;//1��/60�i(60�V)
		//const int frameDelay = 1000 / FPS;//�V�Ʃ���(1��/60�i -> 1/60��/1�i)
		Uint32 frameStart;//�`�ɶ�
		Uint32 frameTime;//1�V���ɶ�
		float deltaTime;//�PframeTime(�ഫ����)
		Uint32 frameCount;//�p��i��
		//bool pause;//�Ȱ�
		//bool start;//�}�l
		//Uint32 pauseTime;//�Ȱ����ɶ�
};