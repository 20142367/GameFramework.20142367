#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;	// Game�� �����ϱ� ���� �ν��Ͻ� ����

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) 
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);	// â ����

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);		// 2D ������ ���ؽ�Ʈ ����
		}
		m_bRunning = true;		// ���� ��

		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);		// (������, R, G, B, Alpha) �� ���� �̿��Ͽ� �� ����(���⼭�� ����)
	}
	else
	{
		return false;
	}

	return true;
}

void Game::render()
{
	// draw color�� render �����
	SDL_RenderClear(m_pRenderer);

	m_pGameStateMachine->render();

	//for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)		// vector<GameOjbect*>�� ���ִ� ��ü���� ����(�׷���)
	//	m_gameObjects[i]->draw();

	// ȭ�� ����
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() 
{
	m_pGameStateMachine->update();
	//for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)		// vector<GameObject*>�� ���ִ� ��ü���� ������Ʈ ������
	//	m_gameObjects[i]->update();

}

void Game::clean() 
{
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);		// ������(â) ����
	SDL_DestroyRenderer(m_pRenderer);	// ������ ����
	SDL_Quit();							// ���α׷� ����
}

void Game::handleEvents() 
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
	TheInputHandler::Instance()->update();
}

Game *Game::Instance() 
{
	if (s_pInstance == 0) {

		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;
}

void Game::quit()		// ���� ����
{
	m_bRunning = false;
}