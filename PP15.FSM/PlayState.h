#pragma once
#include "GameState.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	static PlayState* Instance();

private:
	PlayState();

	static const std::string s_playID;

	std::vector<GameObject*> m_gameObjects;

	static PlayState* s_pInstance;
};