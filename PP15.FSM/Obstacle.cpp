#include "Obstacle.h"
#include "Game.h"
#include "PlayState.h"

Obstacle::Obstacle(const LoaderParams* pParams) : SDLGameObject(pParams)
{
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