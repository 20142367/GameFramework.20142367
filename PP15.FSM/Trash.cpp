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
	SDLGameObject::draw(); // SDLGameObject�� draw�Լ��� ���
}

void Trash::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);		// ��������Ʈ �̹����� ������ŭ ��ȯ

	SDLGameObject::update();
}

void Trash::clean()
{
}