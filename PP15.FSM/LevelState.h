#pragma once
#include "GameObject.h"
#include "GameState.h"

class LevelState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_levelID; }

	static LevelState* Instance();

private:
	LevelState();

	static LevelState* s_pInstance;

	std::string level;

	static void s_normalPlay();
	static void s_hardPlay();

	static const std::string s_levelID;
};