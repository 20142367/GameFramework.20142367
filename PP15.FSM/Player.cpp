#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

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
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// ��������Ʈ �̹����� ������ŭ ��ȯ

	handleInput();	// �Է��� ���������� ������Ʈ

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() 
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();		// ���콺 ��ǥ�� ���� ĳ���� �̵�
	m_velocity = *target - m_position;
	m_velocity /= 50;

}