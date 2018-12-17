#pragma once
#include "SDLGameObject.h"

class Manual : public SDLGameObject
{
public:

	Manual(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};