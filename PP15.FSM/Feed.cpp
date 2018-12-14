#include "Feed.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"

Feed::Feed(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 1;
}

void Feed::draw()
{
	SDLGameObject::draw(); // SDLGameObject의 draw함수를 사용
}

void Feed::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// 스프라이트 이미지의 개수만큼 순환

	SDLGameObject::update();
}

void Feed::clean()
{
}

void Feed::handleInput()
{
}

void Feed::Frame(int change)
{
	this->m_currentRow = change;
}