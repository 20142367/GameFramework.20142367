#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include "Projectile.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	std::vector <Projectile*> m_tile;

	static PlayState* Instance();

private:
	PlayState();

	static const std::string s_playID;

	static PlayState* s_pInstance;
};