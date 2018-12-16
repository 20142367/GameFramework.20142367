#pragma once
#include "GameObject.h"
#include "GameState.h"

class ClearState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }

	static ClearState* Instance();

private:
	ClearState();

	static ClearState* s_pInstance;

	static void s_clearToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
};