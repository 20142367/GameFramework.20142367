#include "Obstacle.h"
#include "Game.h"
#include "PlayState.h"

Obstacle::Obstacle(const LoaderParams* pParams) : SDLGameObject(pParams)
{
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