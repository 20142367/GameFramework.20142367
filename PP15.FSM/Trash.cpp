#include "Trash.h"
#include "InputHandler.h"
#include "Game.h"
#include "PlayState.h"

Trash::Trash(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 2;
}

void Trash::draw()
{
	SDLGameObject::draw(); // SDLGameObject의 draw함수를 사용
}

void Trash::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// 스프라이트 이미지의 개수만큼 순환

	SDLGameObject::update();
}

void Trash::clean()
{
}