#pragma once
#include <iostream>
struct Animation
{
	int frames;//動畫張數
	bool loop;//是否循環播放
	bool done;//是否播完了
	float animationTime;//總時間
	float timePerFrame;//每張的時間
	float animationTimer;//計時器
	Animation()
	{
		
	}
	Animation(float animationTime, int frames, bool loop = false)
		:animationTime(animationTime), frames(frames), loop(loop), done(false),animationTimer(0.0f)
	{
		timePerFrame = animationTime / frames;
	}
	Animation(const Animation& animation)
		:animationTime(animation.animationTime), frames(animation.frames), loop(animation.loop)
		, done(animation.done), animationTimer(0.0f), timePerFrame(animation.timePerFrame)
	{

	}
};