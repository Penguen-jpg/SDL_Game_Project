#pragma once
#include "Timer.h"
#include "Map.h"
#include "Player.h"
#include "Mob.h"
#include "Label.h"
#include "AudioManager.h"
#include "EventManager.h"
#include "Menu.h"
#include <iostream>
#include <cmath>
class Game
{
	public:
		static Game* getInstance();
		static void release();
		bool isRunning() const;//�C���O�_�i�椤
		void handleEvent();//�B�z�ƥ�
		void update();//��s
		void render();//��V
		void restart();//���s�}�l�C��
		bool wantToRestart();//�O�_�n���s�}�l
	private:
		Game();
		~Game();

		static Game* game;//�C������
		Graphics* graphics;//�e��
		Menu* menu;//�D���
		EventManager* eventManager;//�ƥ�޲z��
		Map* map;//�a��
		Player* player;//����
		Label* gameOverLabel;//�鱼����ܪ���r
		Label* winLabel;//Ĺ���ɭ���ܪ���r
		Label* playerHp;//���a��q
		int goal;//�ӧQ����

		bool running;//�C���O�_�i�椤
		bool gameOver() const;//�ˬd�O�_�C������
		bool victory() const;//�ˬd�O�_�ӧQ
		bool re;//�O�_�n���s�}�l
};