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
	bool checkUnCollision(SDLGameObject* p1, SDLGameObject* p2);

	void setType(int type);
	int getType();

	void spawnFeed();
	int feedcount = 0;

	Feed* feed;
	Trash* trash;

	static PlayState* Instance();

private:
	PlayState();

	int type;

	static const std::string s_playID;

	static PlayState* s_pInstance;
};