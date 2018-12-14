#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Obstacle.h"
#include "Map.h"
#include "Feed.h"

class GameState
{
public:
	std::vector<GameObject*> m_gameObjects;
	std::vector<Player*> m_players;
	std::vector<Feed*> m_feeds;
	std::vector <Projectile*> m_tiles;
	
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit();
	virtual std::string getStateID() const = 0;

	virtual void push(GameObject* object);
	virtual void push(GameObject* object1, GameObject* object2);
	virtual void push(GameObject* object1, GameObject* object2, GameObject* object3);

	virtual bool loadTexture(std::string fileName, std::string id);
};