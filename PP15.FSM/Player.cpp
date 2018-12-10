#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

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

}