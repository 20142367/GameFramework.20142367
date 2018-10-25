#pragma once

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	/*
	void update();
	void clean() {};
	*/

	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};