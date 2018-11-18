#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private :
	void handleInput();		// 적을 이동하기 위한 핸들러 함수
};