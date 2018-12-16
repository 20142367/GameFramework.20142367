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
	SDLGameObject::draw(); // SDLGameObject의 draw함수를 사용
}

void Player::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// 스프라이트 이미지의 개수만큼 순환

	handleInput();	// 입력을 지속적으로 업데이트

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() 
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();		// 마우스 좌표를 따라 캐릭터 이동
	m_velocity = *target - m_position;
	m_velocity /= 50;

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))		// z버튼으로 총알 발사
	{
		startTime = SDL_GetTicks();

		if (coolTime <= startTime - currentTime)
		{
			Projectile* projectile = new Projectile(new LoaderParams(Player::m_position.getX() + 128, Player::m_position.getY() + 10, 32, 32, "projectile"));
			PlayState::Instance()->m_tile.push_back(projectile);
			currentTime = SDL_GetTicks();
		}
	}
}