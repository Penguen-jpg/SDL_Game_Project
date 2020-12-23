#pragma once
#include "SDL.h"
class Timer
{
	public:
		static Timer* getTimer();
		static void release();
		void startTimer();//開始計時
		void resetTimer();//重設時間
		void calFrameTime();//計算1幀時間
		//void capFPS();//限制最高FPS(沒用到，因為直接開垂直同步了)
		//void pauseTimer();//暫停計時器
		//void unpauseTimer();//重啟計時器
		void increaseFrameCount();

		float getDeltaTime();
		int getFrameTime();
		Uint32 getFrameCount();

		//bool isPausing();
		//bool isStarting();
	private:
		Timer();
		~Timer();

		static Timer* timer;//計時器
		//const int FPS = 60;//1秒/60張(60幀)
		//const int frameDelay = 1000 / FPS;//幀數延遲(1秒/60張 -> 1/60秒/1張)
		Uint32 frameStart;//總時間
		Uint32 frameTime;//1幀的時間
		float deltaTime;//同frameTime(轉換成秒)
		Uint32 frameCount;//計算張數
		//bool pause;//暫停
		//bool start;//開始
		//Uint32 pauseTime;//暫停的時間
};