#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 5;
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);

	handleInput();	// 입력을 지속적으로 업데이트


	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() 
{
	/*
	// 키보드 입력
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	*/

	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;

	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{

		Ball* ball = new Ball(new LoaderParams(Player::m_position.getX(), Player::m_position.getY(), 32, 32, "ball"));
		PlayState::Instance()->m_balls.push_back(ball);

	}
}