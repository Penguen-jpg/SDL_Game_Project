#pragma once
#include "Player.h"
#include "AudioManager.h"
#include <cmath>
#include <vector>
class Mob :public Sprite
{
	public:
		Mob();
		Mob(const char* path);
		~Mob();

		static std::vector<Mob*> mobs;//�x�s�Ǫ�
		static int NUMBER_OF_MOBS;//�Ǫ��`�ƶq
		static int NUMBER_OF_KILLED_MOBS;//�Q�������Ǫ��ƶq

		static void release();
		void init() override;
		void update() override;
		void move() override;
		void attack() override;
		void wasHit() override;
		void die() override;
		void loseHealth(int amount);//����
		static void spawn();//�ͦ��Ǫ�
		static void clearMobs();//�M�������Ǫ�

		int getHp() const;
	private:
		int hp;//��q
		static const int MOB_WIDTH = 64;
		static const int MOB_HEIGHT = 64;
		static const int MOB_HITBOX_WIDTH = 18;
		static const int MOB_HITBOX_HEIGHT = 40;
		float reactTime;//�Ǫ������ɶ�
		float dx;//�P���a��x�y�Юt
		float dy;//�P���a��y�y�Юt
		float distance;//����(�P���a���Z���t�Φ����T����)
		int tag;//�O���o�O�ĴX���Ǫ�

		void lockPlayer();//�Ǫ��l�ܪ��a
		bool isActive();//�O�_�i����
};