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

		static std::vector<Mob*> mobs;//儲存怪物
		static int NUMBER_OF_MOBS;//怪物總數量
		static int NUMBER_OF_KILLED_MOBS;//被殺掉的怪物數量

		static void release();
		void init() override;
		void update() override;
		void move() override;
		void attack() override;
		void wasHit() override;
		void die() override;
		void loseHealth(int amount);//扣血
		static void spawn();//生成怪物
		static void clearMobs();//清除場面怪物

		int getHp() const;
	private:
		int hp;//血量
		static const int MOB_WIDTH = 64;
		static const int MOB_HEIGHT = 64;
		static const int MOB_HITBOX_WIDTH = 18;
		static const int MOB_HITBOX_HEIGHT = 40;
		float reactTime;//怪物反應時間
		float dx;//與玩家的x座標差
		float dy;//與玩家的y座標差
		float distance;//斜邊(與玩家的距離差形成的三角形)
		int tag;//記錄這是第幾隻怪物

		void lockPlayer();//怪物追蹤玩家
		bool isActive();//是否可移動
};