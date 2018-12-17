#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "GameStateMachine.h"
#include <vector>

using namespace std;

class Game
{
public:
	vector<GameObject*> m_gameObjects;

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	static Game* Instance();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	Game() {};

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_RendererFlip* m_pRendererFlip;

	int m_currentFrame;
	TextureManager* m_textureManager;

	bool m_bRunning;

	// create the s_pInstance member variable
	static Game* s_pInstance;

	GameStateMachine* m_pGameStateMachine;
};
// create the typedef
typedef Game TheGame;