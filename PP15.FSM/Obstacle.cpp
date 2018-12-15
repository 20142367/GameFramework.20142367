#include "Obstacle.h"
#include "Game.h"
#include "PlayState.h"

Obstacle::Obstacle(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}

void Obstacle::draw()
{
	SDLGameObject::draw(); // SDLGameObject의 draw함수를 사용
}

void Obstacle::update()
{
	SDLGameObject::update();
}

void Obstacle::clean()
{
}