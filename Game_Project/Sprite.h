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
			
		virtual void init() = 0;//��l��
		virtual void update() = 0;//��s��m�θ�T
		virtual void move() = 0;//����
		virtual void attack() = 0;//����
		virtual void wasHit() = 0;//����
		virtual void die() = 0;//���`
		void playAnimation(int index);//������w�ʵe
		void resetAnimation(int index);//���s���w�ʵe
		bool isDead() const;//�O�_���`
	protected:
		std::map<int, Animation> animations;//�x�s�ʵe�Ϥ�
		bool facingLeft;//�O�_���V����
		Vector2D position;//��m
		Vector2D velocity;//�t�צV�q
		/*SDL_Rect hitbox;//�����P�w��
		SDL_Rect attackRange;//�����d��
		int hp;//��q
		int movingSpeed;//���ʳt��*/
		/*bool attacking;//�O�_������
		bool active;//�O�_�ಾ��
		bool hit;//�O�_�Q����
		bool dead;//�O�_���`
		float hitTimer;//�Q�����ʵe���p�ɾ�
		float attackTimer;//�����ʵe���p�ɾ�
		float deathTimer;//���`�ʵe���p�ɾ�*/
		Status status;//��O��
		State state;//���A
	private:
		int lastIndex;//�����W�@��index
};