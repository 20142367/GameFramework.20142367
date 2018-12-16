#pragma once
#include "GameObject.h"
#include "GameState.h"

class ManualState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }

	static ManualState* Instance();

private:
	ManualState();

	static ManualState* s_pInstance;

	static void s_ManualToLevel();
	static const std::string s_gameOverID;
};