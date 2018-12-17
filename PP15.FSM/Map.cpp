#include "Map.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"

Map::Map(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 1;
}

void Map::draw()
{
	SDLGameObject::draw(); // SDLGameObject�� draw�Լ��� ���
}

void Map::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// ��������Ʈ �̹����� ������ŭ ��ȯ

	SDLGameObject::update();
}

void Map::clean()
{

}