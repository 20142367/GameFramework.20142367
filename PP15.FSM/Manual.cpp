#include "Manual.h"
#include "InputHandler.h"
#include "Game.h"
#include "ManualState.h"

Manual::Manual(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_numFrames = 1;
}

void Manual::draw()
{
	SDLGameObject::draw(); // SDLGameObject�� draw�Լ��� ���
}

void Manual::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// ��������Ʈ �̹����� ������ŭ ��ȯ

	SDLGameObject::update();
}

void Manual::clean()
{
}