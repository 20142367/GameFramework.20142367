#pragma once
#include "SDLGameObject.h"

class Feed : public SDLGameObject
{
public:

	Feed(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void Frame(int change);
private:
	void handleInput();		// 플레이어 이동을 위한 핸들러 함수
};