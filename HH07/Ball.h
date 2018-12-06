#pragma once
#include "SDLGameObject.h"

class Ball : public SDLGameObject
{
public:
	Ball(const LoaderParams* pParams);

	virtual void draw();
	virtual void clean();
};

