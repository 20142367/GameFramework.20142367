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
	void handleInput();		// �÷��̾� �̵��� ���� �ڵ鷯 �Լ�
};