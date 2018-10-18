#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	/*
	// GameObject - Player(상속관계)관계에서 Player에 변경하지 않은것은 GameObject에서 실행되기 때문에 특별히 변경해줄 것만 Player에 선언해주면 됨
	void load(int x, int y, int width, int height,
		std::string textureID);

	void draw(SDL_Renderer* pRenderer);*/
	void update();
	void clean();
};