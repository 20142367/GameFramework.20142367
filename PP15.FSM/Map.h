#pragma once
#include "SDLGameObject.h"

class Map : public SDLGameObject
{
public:

	Map(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};