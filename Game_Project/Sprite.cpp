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
	//SDL_DestroyTexture(texture);
}

Status Sprite::getStatus() const
{
	return status;
}

/*SDL_Rect Sprite::getHitbox() const
{
	return hitbox;
}

SDL_Rect Sprite::getAttackRange() const
{
	return attackRange;
}

void Sprite::setHitbox(int x, int y, int w, int h)
{
	hitbox.x = x;
	hitbox.y = y;
	hitbox.w = w * SCALE_FACTOR;
	hitbox.h = h * SCALE_FACTOR;
}

void Sprite::setAttackRange(int x, int y, int w, int h)
{
	attackRange.x = x;
	attackRange.y = y;
	attackRange.w = w * SCALE_FACTOR;
	attackRange.h = h * SCALE_FACTOR;
}*/

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
			if (animations[index].loop)//�p�G�O�`������
			{
				animations[index].animationTimer -= animations[index].animationTime;//���stimer
			}
			else
			{
				animations[index].done = true;//�аO������
				//�]���w�g�W�X��ʵe�ɶ��A�ҥH�^��̫�@�i�e��
				animations[index].animationTimer = animations[index].animationTime - animations[index].timePerFrame;
			}
		}
		src.x = src.w * (int)(animations[index].animationTimer / animations[index].timePerFrame);//����U�@�i�e��
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
