#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public :

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	SDLGameObject* body = 0;

	void makeBody();

private :
	void handleInput();		// 플레이어 이동을 위한 핸들러 함수
	
	int bodycount = 0;
};