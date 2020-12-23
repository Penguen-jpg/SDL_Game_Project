#pragma once
#include "Object.h"
#include "Animation.h"
#include "Vector2D.h"
#include "Timer.h"
#include "State.h"
#include "Status.h"
#include <map>
class Sprite :public Object
{
	public:
		Sprite();
		Sprite(const char* path);
		~Sprite();

		//SDL_Rect getHitbox() const;
		//SDL_Rect getAttackRange() const;
		//void setHitbox(int x, int y, int w, int h);
		//void setAttackRange(int x, int y, int w, int h);
		Status getStatus() const;
			
		virtual void init() = 0;//初始化
		virtual void update() = 0;//更新位置及資訊
		virtual void move() = 0;//移動
		virtual void attack() = 0;//攻擊
		virtual void wasHit() = 0;//移動
		virtual void die() = 0;//死亡
		void playAnimation(int index);//播放指定動畫
		void resetAnimation(int index);//重製指定動畫
		bool isDead() const;//是否死亡
	protected:
		std::map<int, Animation> animations;//儲存動畫圖片
		bool facingLeft;//是否面向左邊
		Vector2D position;//位置
		Vector2D velocity;//速度向量
		/*SDL_Rect hitbox;//攻擊判定區
		SDL_Rect attackRange;//攻擊範圍
		int hp;//血量
		int movingSpeed;//移動速度*/
		/*bool attacking;//是否攻擊中
		bool active;//是否能移動
		bool hit;//是否被打到
		bool dead;//是否死亡
		float hitTimer;//被擊中動畫的計時器
		float attackTimer;//攻擊動畫的計時器
		float deathTimer;//死亡動畫的計時器*/
		Status status;//能力值
		State state;//狀態
	private:
		int lastIndex;//紀錄上一個index
};