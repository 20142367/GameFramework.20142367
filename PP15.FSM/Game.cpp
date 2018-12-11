#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;	// Game에 접근하기 위한 인스턴스 변수

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) 
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);	// 창 생성

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);		// 2D 렌더링 컨텍스트 생성
		}
		m_bRunning = true;		// 루프 온

		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);		// (렌더러, R, G, B, Alpha) 각 값을 이용하여 색 설정(여기서는 배경색)
	}
	else
	{
		return false;
	}

	return true;
}

void Game::render()
{
	// draw color로 render 지우기
	SDL_RenderClear(m_pRenderer);

	m_pGameStateMachine->render();

	//for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)		// vector<GameOjbect*>에 들어가있는 객체들을 렌더(그려줌)
	//	m_gameObjects[i]->draw();

	// 화면 제시
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() 
{
	m_pGameStateMachine->update();
	//for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)		// vector<GameObject*>에 들어가있는 객체들을 업데이트 시켜줌
	//	m_gameObjects[i]->update();

}

void Game::clean() 
{
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);		// 윈도우(창) 삭제
	SDL_DestroyRenderer(m_pRenderer);	// 렌더러 삭제
	SDL_Quit();							// 프로그램 종료
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

void Game::quit()		// 루프 종료
{
	m_bRunning = false;
}