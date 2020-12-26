#pragma once
#include "Sprite.h"
#include "InputManager.h"
#include "Mob.h"
#include "AudioManager.h"
class Player :public Sprite
{
	public:
		static Player* getPlayer();
		void release();
		void init() override;
		void update() override;
		void move() override;
		void attack() override;
		void wasHit() override;
		void die() override;
		void loseHealth(int amount);
	private:
		Player(const char *path);
		~Player();

		static Player* player;//玩家
		bool isPressed[4] = { false };//對應方向鍵是否被按住
		InputManager* inputManager;//輸入管理員
		const int PLAYER_WIDTH;
		const int PLAYER_HEIGHT;
		const int PLAYER_HITBOT_WIDTH;
		const int PLAYER_HITBOX_HEIGHT;

		bool isActive();//是否可移動
		void initPressedCheck();//初始化移動檢查
};