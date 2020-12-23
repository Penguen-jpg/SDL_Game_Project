#pragma once
#include "AssetManager.h"
class AudioManager
{
	public:
		static AudioManager* getAudioManager();
		static void release();

		void playMusic(const char* path, int loop = -1);//���񭵼�(loop = -1�N��`������)
		void pauseMusic();//�Ȱ�����
		void resumeMusic();//�~�򼽩�
		void playSFX(const char* path, int loop = 0, int channel = 2);//���񭵮�(loop = 0�N���`������Achannel = 2�N�����n�D)

	private:
		AudioManager();
		~AudioManager();

		static AudioManager* audioManager;//���ĺ޲z��
};