#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"

Uint32 startTime, currentTime;
const float coolTime = 400.0f;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 5;
}

void Player::draw()
{
	SDLGameObject::draw(); // SDLGameObject�� draw�Լ��� ���
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// ��������Ʈ �̹����� ������ŭ ��ȯ

	handleInput();	// �Է��� ���������� ������Ʈ

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() 
{
	//Vector2D* target = TheInputHandler::Instance()->getMousePosition();		// ���콺 ��ǥ�� ���� ĳ���� �̵�
	//m_velocity = *target - m_position;
	//m_velocity /= 50;

	// Ű���� �Է�
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		startTime = SDL_GetTicks();

		if (coolTime <= startTime - currentTime)
		{
			Projectile* projectile = new Projectile(new LoaderParams(Player::m_position.getX() + 128, Player::m_position.getY() + 10, 32, 32, "tile"));
			PlayState::Instance()->m_tiles.push_back(projectile);
			currentTime = SDL_GetTicks();
		}
	}
}