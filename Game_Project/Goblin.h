#pragma once
#include "Mob.h"
class Goblin :public Mob
{
	public:
		Goblin(const char* path, bool isAnimated);

		void init() override;
	private:
		const int GOBLIN_WIDTH = 125;
		const int GOBLIN_HIEGHT = 150;
		const int GOBLIN_HITBOX_WIDTH = 34;
		const int GOBLIN_HITBOX_HEIGHT = 36;
};