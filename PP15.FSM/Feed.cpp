#include "Feed.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"

Feed::Feed(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 2;
}

void Feed::draw()
{
	SDLGameObject::draw(); // SDLGameObject�� draw�Լ��� ���
}

void Feed::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// ��������Ʈ �̹����� ������ŭ ��ȯ

	SDLGameObject::update();
}

void Feed::clean()
{
}