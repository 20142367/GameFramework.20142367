#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	Enemy::handleInput();

	SDLGameObject::update();
}

void Enemy::clean()
{
}

void Enemy::handleInput()
{
	// ���콺 �Է�
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - m_position);
	m_velocity.normalize();				// normalize��� ��, ������Ʈ�� ���콺�� �Ÿ��� ������� ������ �ӵ��� �̵�(��� ���ϸ� �ָ� ������, ������ ������)
	m_velocity *= 3.0f;
	m_position += m_velocity;

}
