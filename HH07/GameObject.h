#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
	// vector�迭(?)�� ��������ν� �� Ŭ�������� ��������� �����Ű���� virtual�� ����ؾ� ��(=������)
	// clean()�� virtual�� ��� �� ���ǰ� ������ �ʿ�(GameObject�Ӹ� �ƴ϶� �ڽ� Ŭ���� ���)
	// ������� ���� �ÿ��� ���� �ʿ�ġ ����

	// ���� ���� �Լ�
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:
	GameObject(const LoaderParams* pParams) {}
};
