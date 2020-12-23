#include "Goblin.h"

Goblin::Goblin(const char * path, bool isAnimated)
{
	init();
	animated = isAnimated;
	animations.emplace("idle", Animation(0, 100, 4));
	playAnimation("idle");
	setTex(path);
}

void Goblin::init()
{
	position.x = (float)(rand() % 800);
	position.y = (float)(rand() % 640);
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	setSrc(0, 0, GOBLIN_WIDTH, GOBLIN_HIEGHT);
	setDest(0, 0, GOBLIN_WIDTH, GOBLIN_HIEGHT);
	//setHitbox(dest.x + w_diff, dest.y + h_diff, MOB_HITBOX_WIDTH, MOB_HITBOX_HEIGHT);
	setHitbox(dest.x, dest.y + 13, GOBLIN_HITBOX_WIDTH, GOBLIN_HITBOX_HEIGHT);
	movingSpeed = 3;
	flip = SDL_FLIP_NONE;
	hp = 1;
	dx = 0;
	dy = 0;
}
