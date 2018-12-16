#pragma once
#include "GameState.h"

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

	static MenuState* Instance();

private:
	MenuState();

	static const std::string s_menuID;
	static MenuState* s_pInstance;

	static void s_menuToLevel();
	static void s_exitFromMenu();
};

