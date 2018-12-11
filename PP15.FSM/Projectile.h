#pragma once
#include "SDLGameObject.h"

class Projectile : public SDLGameObject
{
public:
	Projectile(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void Frame(int change);
};