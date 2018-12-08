#include "Wall.h"
#include "PlayState.h"
#include "Game.h"
#include "Ball.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Wall::draw()
{
	SDLGameObject::draw();
}

void Wall::update()
{
	for (int i = 0; i < PlayState::Instance()->m_balls.size(); i++)
	{
		if (PlayState::Instance()->checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_gameObjects[1]), dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_balls[i])))
		{
			m_currentFrame = 1;

			PlayState::Instance()->m_balls[i]->m_currentFrame = 1;
		}
	}
}

void Wall::clean()
{

}