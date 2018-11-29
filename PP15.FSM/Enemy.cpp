#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0.001);

	m_numFrames = 5;
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	if (m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}

	Enemy::handleInput();

	SDLGameObject::update();
}

void Enemy::clean()
{
}

void Enemy::handleInput()
{
	/*
	// 마우스 입력
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - m_position);
	m_velocity.normalize();				// normalize사용 시, 오브젝트와 마우스의 거리에 상관없이 일정한 속도로 이동(사용 안하면 멀면 빠르고, 가까우면 느려짐)
	m_velocity *= 3.0f;
	m_position += m_velocity;
	*/

}
