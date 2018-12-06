#include "Ball.h"
#include "Vector2D.h"
#include "Player.h"

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(5);
}

void Ball::draw()
{
	SDLGameObject::draw();
}

void Ball::clean()
{

}