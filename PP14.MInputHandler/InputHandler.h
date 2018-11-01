#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"

class InputHandler
{
public:
	// keyboard spcific
	const Uint8* m_keystates;

	// mouse spcific
	enum mouse_button {
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	// mouse button events
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event
	Vector2D* m_mousePosition;

	static InputHandler* Instance();

	void update();
	void clean();

	bool isKeyDown(SDL_Scancode Key);

	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

