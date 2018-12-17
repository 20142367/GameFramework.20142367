#pragma once
#include "SDLGameObject.h"

class Trash : public SDLGameObject
{
public:

	Trash(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};