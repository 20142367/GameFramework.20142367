#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public :

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	int getVelocityX();
	int getVelocityY();

	int getX();
	int getY();

	SDLGameObject* body = 0;

	void makeBody();

	int bodycount = 0;

private :
	void handleInput();		// �÷��̾� �̵��� ���� �ڵ鷯 �Լ�

};