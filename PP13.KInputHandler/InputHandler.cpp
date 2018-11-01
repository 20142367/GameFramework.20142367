#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYUP) {
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_KEYDOWN) {
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_QUIT) {
			//TheGame::Instance()->clean();
			
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode Key) {
	if (m_keystates != 0) {
		if (m_keystates[Key] == 1) {
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void InputHandler::clean() {

}

InputHandler* InputHandler::Instance() {
	if (s_pInstance == 0) {
		s_pInstance = new InputHandler();

		return s_pInstance;
	}
	return s_pInstance;
}