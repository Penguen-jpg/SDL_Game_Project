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
		Status status;//能力值
		State state;//狀態
	private:
		int lastIndex;//紀錄上一個index
};