#pragma once
#include "SDL.h"
struct Status
{
	SDL_Rect hitbox;//�����P�w��
	SDL_Rect attackRange;//�����d��
	int hp;//��q
	int movingSpeed;//���ʳt��

	void setHitbox(int x, int y, int w, int h)
	{
		hitbox.x = x;
		hitbox.y = y;
		hitbox.w = w;
		hitbox.h = h;
	}
	void setAttackRange(int x, int y, int w, int h)
	{
		attackRange.x = x;
		attackRange.y = y;
		attackRange.w = w;
		attackRange.h = h;
	}
};