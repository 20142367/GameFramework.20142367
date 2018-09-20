#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;

//		SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
		SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);


		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
	}
	else
	{
		return false;
	}



	return true;
}

void Game::render() {

	// 원본 사각형 : m_sourceRectangle, 대상 사각형 : m_destinationRectangle
	/*
	m_destinationRectangle.x = m_sourceRectangle.x;
	m_destinationRectangle.y = m_sourceRectangle.y;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;
	*/

	// clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);	// draw color로 render 지우기

									// 원본 사각형과 대상 사각형의 위치와 크기에 따라 화면에 다르게 나타남
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update() {

	m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
}

void Game::clean() {

	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);

	SDL_Delay(3000);
	SDL_Quit();
}

void Game::handleEvents() {

	SDL_Event event;
	if (SDL_PollEvent(&event)) {

		switch (event.type) {

		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}
