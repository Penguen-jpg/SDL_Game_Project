#pragma once
#include "SDL.h"
struct Status
{
	SDL_Rect hitbox;//攻擊判定區
	SDL_Rect attackRange;//攻擊範圍
	int hp;//血量
	int movingSpeed;//移動速度

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