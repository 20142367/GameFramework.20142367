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
	void handleInput();		// �÷��̾� �̵��� ���� �ڵ鷯 �Լ�
	
	int bodycount = 0;
};