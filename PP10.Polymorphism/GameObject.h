#pragma once

#include "TextureManager.h"

class GameObject
{
public:
	// vector배열(?)을 사용함으로써 각 클래스마다 변경사항을 적용시키려면 virtual를 사용해야 함
	virtual void load(int x, int y, int width, int height,
		std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	// clean()에 virtual를 사용 시 정의가 무조건 필요(GameObject뿐만 아니라 자식 클래스 모두)
	// 사용하지 않을 시에는 정의 필요치 않음
	virtual void clean() {};

protected:
	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
