#pragma once
#include "AssetManager.h"
class AudioManager
{
	public:
		static AudioManager* getAudioManager();
		static void release();

		void playMusic(const char* path, int loop = -1);//播放音樂(loop = -1代表循環播放)
		void pauseMusic();//暫停播放
		void resumeMusic();//繼續播放
		void playSFX(const char* path, int loop = 0, int channel = 2);//播放音效(loop = 0代表不循環播放，channel = 2代表雙聲道)

	private:
		AudioManager();
		~AudioManager();

		static AudioManager* audioManager;//音效管理員
};