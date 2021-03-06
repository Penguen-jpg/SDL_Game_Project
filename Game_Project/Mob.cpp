#include "Mob.h"
#include <iostream>
std::vector<Mob*> Mob::mobs;
int Mob::NUMBER_OF_MOBS = 0;
int Mob::NUMBER_OF_KILLED_MOBS = 0;
//目標:暫無
Mob::Mob(const char * path)
	:Sprite(path)
{
	init();
	animations.emplace(0, Animation(0.7f, 7, true));//靜置的動畫
	animations.emplace(1, Animation(0.5f, 6, true));//跑步的動畫
	animations.emplace(2, Animation(0.8f, 7, true));//攻擊的動畫
	animations.emplace(3, Animation(0.4f, 3, true));//被打和死掉的動畫
	playAnimation(0);
}

Mob::~Mob()
{
	
}

void Mob::release()
{
	for (int n = 0; n < NUMBER_OF_MOBS; n++)
	{
		delete mobs[n];
		mobs[n] = NULL;
	}
	mobs.clear();
	NUMBER_OF_MOBS = 0;
	NUMBER_OF_KILLED_MOBS = 0;
}

void Mob::loseHealth(int amount)
{
	status.hp -= amount;
	state.hit = true;
}

void Mob::spawn()
{
	NUMBER_OF_MOBS++;
	mobs.emplace_back(new Mob("assets/enemy1_sheet.png"));
}

void Mob::clearMobs()
{
	while (NUMBER_OF_MOBS != 0)
	{
		delete mobs[NUMBER_OF_MOBS - 1];
		mobs.erase(mobs.begin());
		NUMBER_OF_MOBS--;
	}
}

void Mob::attack()
{
	state.attackTimer += Timer::getTimer()->getDeltaTime();
	state.attacking = true;
	if (SDL_HasIntersection(&status.attackRange, &(const SDL_Rect)Player::getPlayer()->getStatus().hitbox) && Timer::getTimer()->getFrameCount() % 50 == 0)
	{
		AudioManager::getAudioManager()->playSFX("SFX/slash2.wav", 0, 2);
		Player::getPlayer()->loseHealth(1);
		//std::cout << "Player's hp: " << Player::getPlayer()->getStatus().hp << std::endl;
	}
	if (state.attackTimer >= reactTime)
	{
		playAnimation(2);
	}
	if (state.attackTimer >= animations[2].animationTime + reactTime)
	{
		state.active = true;
		state.attackTimer = 0.0f;
		state.attacking = false;
	}
}

void Mob::wasHit()
{
	state.hitTimer += Timer::getTimer()->getDeltaTime();
	playAnimation(3);

	if (state.hitTimer >= animations[3].animationTime)
	{
		state.hitTimer = 0.0f;
		state.hit = false;
	}
}

void Mob::die()
{
	state.deathTimer += Timer::getTimer()->getDeltaTime();
	playAnimation(3);
	if (state.deathTimer >= animations[3].animationTime)
	{
		state.deathTimer = 0.0f;
		state.dead = true;
		NUMBER_OF_KILLED_MOBS++;
		//std::cout << "number of killed mobs: " << NUMBER_OF_KILLED_MOBS << std::endl;
	}
}

void Mob::init()
{
	//初始化位置
	position.x = (float)(rand() % (Graphics::WINDOW_WIDTH - MOB_WIDTH));
	position.y = (float)(rand() % (Graphics::WINDOW_HEIGHT - MOB_HEIGHT));
	//初始化來源及目標方塊
	SCALE_FACTOR = 2;
	setSrc(0, 0, MOB_WIDTH, MOB_HEIGHT);
	setDest(0, 0, MOB_WIDTH, MOB_HEIGHT);
	flip = SDL_FLIP_NONE;
	//初始化怪物能力值
	status.hp = 5;
	status.movingSpeed = 1;
	status.setHitbox(dest.x + 15, dest.y + 50, MOB_HITBOX_WIDTH * SCALE_FACTOR, MOB_HITBOX_HEIGHT * SCALE_FACTOR);
	status.setAttackRange(0, 0, 22 * SCALE_FACTOR, 30 * SCALE_FACTOR);
	//初始化怪物狀態
	state.active = true;
	state.attacking = false;
	state.hit = false;
	state.dead = false;
	reactTime = 0.2f;
	state.attackTimer = 0.0f;
	state.hitTimer = 0.0f;
	state.deathTimer = 0.0f;
	//標記怪物
	tag = NUMBER_OF_MOBS;
}

void Mob::update()
{	
	//依照上一次的狀態做出動作
	if (status.hp < 1 && !state.dead)
	{
		die();
	}
	else if (state.active)
	{
		lockPlayer();
	}

	//更新狀態
	state.active = isActive();
	if (state.hit)
	{
		wasHit();
	}
	else if (!state.active)
	{
		attack();
	}
	else
	{
		move();
	}
	//更新位置
	dest.x = (int)position.x;
	dest.y = (int)position.y;
	//檢查有沒有超出畫面
	if (dest.x > Graphics::WINDOW_WIDTH - MOB_WIDTH)
	{
		dest.x = Graphics::WINDOW_WIDTH - MOB_WIDTH;
	}
	else if (dest.x < 0)
	{
		dest.x = 0;
	}
	if (dest.y > Graphics::WINDOW_HEIGHT - MOB_HEIGHT)
	{
		dest.y = Graphics::WINDOW_HEIGHT - MOB_HEIGHT;
	}
	else if (dest.y < 0)
	{
		dest.y = 0;
	}
	//更新資訊
	if (facingLeft)
	{
		status.setAttackRange(dest.x + 25, dest.y + MOB_HEIGHT - 10, 22 * SCALE_FACTOR, 30 * SCALE_FACTOR);
		//面向左邊時需要考慮角色寬度(圖片的關係)
		status.setHitbox(dest.x + MOB_WIDTH + 15 , dest.y + 50, MOB_HITBOX_WIDTH * SCALE_FACTOR, MOB_HITBOX_HEIGHT * SCALE_FACTOR);
	}
	else
	{
		status.setAttackRange(dest.x + 60, dest.y + MOB_HEIGHT - 10, 22 * SCALE_FACTOR, 30 * SCALE_FACTOR);
		status.setHitbox(dest.x + 15, dest.y + 50, MOB_HITBOX_WIDTH * SCALE_FACTOR, MOB_HITBOX_HEIGHT * SCALE_FACTOR);
	}
}

void Mob::move()
{
	//更新狀態
	state.active = true;

	//算出單位向量
	dx /= distance;
	dy /= distance;
	//std::cout << "unit dx: " << dx << " unit dy: " << dy << std::endl;
	playAnimation(1);

	//移動
	position.x += dx * status.movingSpeed;
	position.y += dy * status.movingSpeed;
}

void Mob::lockPlayer()
{
	if (status.hitbox.x < Player::getPlayer()->getStatus().hitbox.x)//玩家在怪物右邊
	{
		flip = SDL_FLIP_NONE;
		facingLeft = false;
	}
	else if (status.hitbox.x > Player::getPlayer()->getStatus().hitbox.x)//玩家在怪物左邊
	{
		flip = SDL_FLIP_HORIZONTAL;
		facingLeft = true;
	}
	dx = Player::getPlayer()->getStatus().hitbox.x - status.hitbox.x;
	dy = Player::getPlayer()->getStatus().hitbox.y - status.hitbox.y;
	distance = sqrt(dx*dx + dy*dy);
}

bool Mob::isActive()
{
	if (state.dead)
	{
		return false;
	}
	else if (state.attacking)
	{
		return false;
	}
	else if (distance < 45.0f)
	{
		return false;
	}
	else if(!state.active)
	{
		return false;
	}
	else
	{
		return true;
	}
}
