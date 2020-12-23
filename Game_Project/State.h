#pragma once
struct State
{
	bool attacking;//是否攻擊中
	bool active;//是否能移動
	bool hit;//是否被打到
	bool dead;//是否死亡
	float hitTimer;//被擊中動畫的計時器
	float attackTimer;//攻擊動畫的計時器
	float deathTimer;//死亡動畫的計時器
};