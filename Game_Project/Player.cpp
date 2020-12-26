#include "Player.h"
Player* Player::player = NULL;
//�ؼ�:
Player::Player(const char * path)
	:Sprite(path), PLAYER_WIDTH(50), PLAYER_HEIGHT(37), PLAYER_HITBOT_WIDTH(18)
	, PLAYER_HITBOX_HEIGHT(28)
{
	init();
	inputManager = InputManager::getInputManager();
	animations.emplace(0, Animation(0.5f, 4, true));//�R�m���ʵe
	animations.emplace(1, Animation(0.7f, 6, true));//�]�B���ʵe
	animations.emplace(2, Animation(0.5f, 6, true));//�������ʵe
	animations.emplace(3, Animation(0.8f, 6, false));//�������ʵe
	animations.emplace(4, Animation(0.3f, 3, true));//�Q�����ʵe
	playAnimation(0);
}

Player::~Player()
{
	
}

Player * Player::getPlayer()
{
	if (player == NULL)
	{
		player = new Player("assets/animation_sheet4.png");
	}
	return player;
}

void Player::release()
{
	delete player;
	player = NULL;
	inputManager = NULL;
}

void Player::init()
{
	//��l�Ʀ�m�γt�צV�q
	position.x = 400.0f;
	position.y = 300.0;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	//��l�ƨӷ��ΥؼФ��
	SCALE_FACTOR = 2;
	setSrc(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
	setDest(400, 300, PLAYER_WIDTH, PLAYER_HEIGHT);
	flip = SDL_FLIP_NONE;
	//��l�ƨ����O��
	status.movingSpeed = 3;
	status.hp = 10;
	status.setHitbox(0, 0, PLAYER_HITBOT_WIDTH * SCALE_FACTOR, PLAYER_HITBOX_HEIGHT * SCALE_FACTOR);
	status.setAttackRange(0, 0, 15 * SCALE_FACTOR, PLAYER_HEIGHT * SCALE_FACTOR);
	//��l�ƨ��⪬�A
	state.active = true;
	state.attacking = false;
	state.hit = false;
	state.dead = false;
	state.hitTimer = 0.0f;
	state.attackTimer = 0.0f;
	state.deathTimer = 0.0f;
}

void Player::update()
{
	
	if (InputManager::getInputManager()->isTriggered(SDL_SCANCODE_X))
	{
		state.attacking = true;
	}
	state.active = isActive();
	//std::cout << "active: " << active << std::endl;
	if (status.hp < 1 && !state.dead)
	{
		die();
	}
	else if (state.hit)
	{
		wasHit();
	}
	else if (state.attacking)
	{
		attack();
	}
	else if (state.active)
	{
		move();
	}
	//��s��m
	dest.x = (int)position.x;
	dest.y = (int)position.y;
	//�ˬd����O�_�W�X�e��
	if (dest.x > Graphics::WINDOW_WIDTH - PLAYER_WIDTH)
	{
		dest.x = Graphics::WINDOW_WIDTH - PLAYER_WIDTH;
	}
	else if (dest.x < 0)
	{
		dest.x = 0;
	}
	if (dest.y > Graphics::WINDOW_HEIGHT - PLAYER_HEIGHT)
	{
		dest.y = Graphics::WINDOW_HEIGHT - PLAYER_HEIGHT;
	}
	else if (dest.y < 0)
	{
		dest.y = 0;
	}
	//��s��T
	status.setHitbox(dest.x + 31, dest.y + 14, PLAYER_HITBOT_WIDTH * SCALE_FACTOR, PLAYER_HITBOX_HEIGHT * SCALE_FACTOR);
	if (facingLeft)
	{
		status.setAttackRange(dest.x + 5, dest.y, 15 * SCALE_FACTOR, PLAYER_HEIGHT * SCALE_FACTOR);
	}
	else
	{
		//���ۥk��ݦҼ{����e��
		status.setAttackRange(dest.x + PLAYER_WIDTH + 15, dest.y, 15 * SCALE_FACTOR, PLAYER_HEIGHT * SCALE_FACTOR);
	}
}

void Player::move()
{
	//����������Q���U�P��}�ɪ��ʧ@
	if (InputManager::getInputManager()->isKeyPressed(SDL_SCANCODE_UP))
	{
		velocity.y = -1.0f;
		isPressed[1] = true;
	}
	else if (InputManager::getInputManager()->isKeyReleased(SDL_SCANCODE_UP))
	{
		velocity.y = 0.0f;
		isPressed[1] = false;
	}
	if (InputManager::getInputManager()->isKeyPressed(SDL_SCANCODE_RIGHT))
	{
		velocity.x = 1.0f;
		isPressed[2] = true;
		facingLeft = false;
		flip = SDL_FLIP_NONE;
	}
	else if (InputManager::getInputManager()->isKeyReleased(SDL_SCANCODE_RIGHT))
	{
		velocity.x = 0.0f;
		isPressed[2] = false;;
	}
	if (InputManager::getInputManager()->isKeyPressed(SDL_SCANCODE_LEFT))
	{
		velocity.x = -1.0f;
		facingLeft = true;
		isPressed[0] = true;
		flip = SDL_FLIP_HORIZONTAL;//����½��
	}
	else if (InputManager::getInputManager()->isKeyReleased(SDL_SCANCODE_LEFT))
	{
		velocity.x = 0.0f;
		isPressed[0] = false;
	}
	if (InputManager::getInputManager()->isKeyPressed(SDL_SCANCODE_DOWN))
	{
		velocity.y = 1.0f;
		isPressed[3] = true;
	}
	else if (InputManager::getInputManager()->isKeyReleased(SDL_SCANCODE_DOWN))
	{
		velocity.y = 0.0f;
		isPressed[3] = false;
	}

	if (!isPressed[0] && !isPressed[1] && !isPressed[2] && !isPressed[3] && !state.attacking)
	{
		playAnimation(0);
	}
	else
	{
		playAnimation(1);
		position.x += velocity.x * status.movingSpeed;//x���첾
		position.y += velocity.y * status.movingSpeed;//y���첾
	}
}

void Player::loseHealth(int amount)
{
	status.hp -= amount;
	state.hit= true;
}

void Player::attack()
{
	state.attackTimer += Timer::getTimer()->getDeltaTime();
	playAnimation(2);
	for (int n = 0; n < Mob::NUMBER_OF_MOBS; n++)
	{
		if (SDL_HasIntersection(&status.attackRange, &(const SDL_Rect)Mob::mobs[n]->getStatus().hitbox) && Timer::getTimer()->getFrameCount() % 31 == 0)
		{
			if (!Mob::mobs[n]->isDead())
			{
				AudioManager::getAudioManager()->playSFX("SFX/slash.wav", 0, 2);
			}	
			//std::cout << "Mob's hp: " << Mob::mobs[n]->getHp() << std::endl;
			Mob::mobs[n]->loseHealth(1);

		}
	}
	if (state.attackTimer >= animations[2].animationTime)
	{
		state.attackTimer = 0.0f;
		state.attacking = false;
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		initPressedCheck();
	}
}

void Player::wasHit()
{
	state.hitTimer += Timer::getTimer()->getDeltaTime();
	playAnimation(4);
	if (state.hitTimer >= animations[4].animationTime)
	{
		state.hit = false;
		state.hitTimer = 0.0f;
		initPressedCheck();
	}
}

void Player::die()
{
	state.deathTimer += Timer::getTimer()->getDeltaTime();
	playAnimation(3);
	if (state.deathTimer >= animations[3].animationTime)
	{
		state.deathTimer = 0.0f;
		state.dead = true;
		initPressedCheck();
	}
}

bool Player::isActive()
{
	if (state.dead)
	{
		return false;
	}
	else if (state.attacking)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Player::initPressedCheck()
{
	for (int n = 0; n < 4; n++)
	{
		isPressed[n] = false;
	}
}