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

		static Player* player;//���a
		bool isPressed[4] = { false };//������V��O�_�Q����
		InputManager* inputManager;//��J�޲z��
		const int PLAYER_WIDTH;
		const int PLAYER_HEIGHT;
		const int PLAYER_HITBOT_WIDTH;
		const int PLAYER_HITBOX_HEIGHT;

		bool isActive();//�O�_�i����
		void initPressedCheck();//��l�Ʋ����ˬd
};