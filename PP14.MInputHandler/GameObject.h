#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
	// vector배열(?)을 사용함으로써 각 클래스마다 변경사항을 적용시키려면 virtual를 사용해야 함(=다형성)
	// clean()에 virtual를 사용 시 정의가 무조건 필요(GameObject뿐만 아니라 자식 클래스 모두)
	// 사용하지 않을 시에는 정의 필요치 않음

	// 완전 가상 함수
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:
	GameObject(const LoaderParams* pParams) {}
};
