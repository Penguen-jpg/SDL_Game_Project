#include "AudioManager.h"
AudioManager* AudioManager::audioManager = NULL;

AudioManager::AudioManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "failed to open audio!\n";
	}
}

AudioManager::~AudioManager()
{
	Mix_Quit();
}

AudioManager * AudioManager::getAudioManager()
{
	if (audioManager == NULL)
	{
		audioManager = new AudioManager();
	}
	return audioManager;
}

void AudioManager::release()
{
	delete audioManager;
	audioManager = NULL;
}

void AudioManager::playMusic(const char * path, int loop)
{
	Mix_PlayMusic(AssetManager::getAssetManager()->getMusic(path), loop);
}

void AudioManager::pauseMusic()
{
	if (Mix_PlayingMusic() != 0)//如果正在播放音樂
	{
		Mix_PauseMusic();
	}
}

void AudioManager::resumeMusic()
{
	if (Mix_PausedMusic() != 0)//如果正在暫停播放
	{
		Mix_ResumeMusic();
	}
}

void AudioManager::playSFX(const char * path, int loop, int channel)
{
	Mix_PlayChannel(channel, AssetManager::getAssetManager()->getSFX(path), loop);
}
