#include "Enemy.h"
#include "InputHandler.h"

/*
void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 150) % 6));
}
*/

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
	/*
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	*/
	m_position.setX(m_position.getX());
	m_position.setY(m_position.getY());

	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
	{
		m_velocity.setX(0);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position);
	m_velocity.normalize();
	m_velocity *= 3.0f;
	m_position += m_velocity;

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

}

void Enemy::clean()
{
}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
	{
		m_velocity.setX(0);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}
