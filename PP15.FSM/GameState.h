#pragma once
#include <vector>
#include "GameObject.h"

class GameState
{
protected:
	std::vector<GameObject*> m_gameObjects;
	
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