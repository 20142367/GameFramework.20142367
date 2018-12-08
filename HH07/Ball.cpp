#include "Ball.h"
#include "Vector2D.h"
#include "Player.h"
#include "Game.h"
#include "PlayState.h"

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(2);
}

void Ball::draw()
{
	SDLGameObject::draw();
}

void Ball::update()
{
	m_position += m_velocity;
}

void Ball::clean()
{
}

void Ball::Frame(int change)
{
	this->m_currentFrame = change;
}