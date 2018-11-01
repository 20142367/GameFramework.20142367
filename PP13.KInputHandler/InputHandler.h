#pragma once
#include <SDL.h>

class InputHandler
{
public:
	// keyboard spcific
	const Uint8* m_keystates;

	static InputHandler* Instance();

	void update();
	void clean();

	bool isKeyDown(SDL_Scancode Key);

private:
	InputHandler() {};

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

