#pragma once
#include "GameState.h"
#include "SDLGameObject.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	std::vector<Ball*> m_balls;

	static PlayState* Instance();

private:
	PlayState();

	static const std::string s_playID;

	std::vector<GameObject*> m_gameObjects;

	static PlayState* s_pInstance;
};