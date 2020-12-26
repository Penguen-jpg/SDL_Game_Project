#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(const char * path)
	:Object(path)
{
	
}

Sprite::~Sprite()
{
	
}

Status Sprite::getStatus() const
{
	return status;
}

void Sprite::playAnimation(int index)
{
	if (!animations[index].done)
	{
		if (index != lastIndex)
		{
			animations[lastIndex].animationTimer = 0.0f;
			lastIndex = index;
		}
		animations[index].animationTimer += Timer::getTimer()->getDeltaTime();
		if (animations[index].animationTimer >= animations[index].animationTime)
		{
			if (animations[index].loop)//如果是循環播放
			{
				animations[index].animationTimer -= animations[index].animationTime;//重製timer
			}
			else
			{
				animations[index].done = true;//標記為完成
				//因為已經超出原動畫時間，所以回到最後一張畫面
				animations[index].animationTimer = animations[index].animationTime - animations[index].timePerFrame;
			}
		}
		src.x = src.w * (int)(animations[index].animationTimer / animations[index].timePerFrame);//移到下一張畫面
	}
	src.y = index * src.h;
}

void Sprite::resetAnimation(int index)
{
	animations[index].done = false;
	animations[index].animationTimer = 0.0f;
}

bool Sprite::isDead() const
{
	return state.dead;
}
