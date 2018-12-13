#pragma once
#include "SDLGameObject.h"

class Obstacle : public SDLGameObject
{
public:

	Obstacle(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
};