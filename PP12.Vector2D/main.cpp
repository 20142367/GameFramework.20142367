#include "Game.h"

// Game* g_game = 0;	// our Game object
// Game* Game::s_pInstance = 0;
const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;
Uint32 frameStart, frameTime;

int main(int argc, char* argv[]) {
	/*
	g_game = new Game();
	g_game->init("PP10.Polymorphism", 100, 100, 640, 480, false);

	while (g_game->running()) {

		g_game->handleEvents();
		g_game->update();
		g_game->render();
		SDL_Delay(10);
	}

	g_game->clean();

	return 0;
	*/

	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("PP12.Vector2D", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		/*
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
		}
		*/
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else {
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();
	return 0;
}