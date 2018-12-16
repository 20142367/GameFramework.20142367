#pragma once
#include "SDLGameObject.h"

class Manual : public SDLGameObject
{
public:

	Manual(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();		// 플레이어 이동을 위한 핸들러 함수
};