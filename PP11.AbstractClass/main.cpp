#include "Game.h"

Game* g_game = 0;	// our Game object

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
	if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
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