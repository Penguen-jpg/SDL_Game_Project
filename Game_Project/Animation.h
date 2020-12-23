#pragma once
#include <iostream>
struct Animation
{
	int frames;//�ʵe�i��
	bool loop;//�O�_�`������
	bool done;//�O�_�����F
	float animationTime;//�`�ɶ�
	float timePerFrame;//�C�i���ɶ�
	float animationTimer;//�p�ɾ�
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