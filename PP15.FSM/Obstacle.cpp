#include "Obstacle.h"
#include "Game.h"
#include "PlayState.h"

Obstacle::Obstacle(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}

void Obstacle::draw()
{
	SDLGameObject::draw(); // SDLGameObject�� draw�Լ��� ���
}

void Obstacle::update()
{
	SDLGameObject::update();
}

void Obstacle::clean()
{
}