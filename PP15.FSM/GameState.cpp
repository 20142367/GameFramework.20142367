#include "GameState.h"
#include "Game.h"

void GameState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool GameState::onExit()
{

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	return true;
}

void GameState::push(GameObject* object)		// 1���� ��ü�� �Ѳ����� Ǫ��
{
	m_gameObjects.push_back(object);
}

void GameState::push(GameObject* object1, GameObject* object2)		// 2���� ��ü�� �Ѳ����� Ǫ��
{
	m_gameObjects.push_back(object1);
	m_gameObjects.push_back(object2);
}

void GameState::push(GameObject* object1, GameObject* object2, GameObject* object3)		// 3���� ��ü�� �Ѳ����� Ǫ��
{
	m_gameObjects.push_back(object1);
	m_gameObjects.push_back(object2);
	m_gameObjects.push_back(object3);
}

bool GameState::loadTexture(std::string fileName, std::string id)		// �ڽ�Ŭ���������� ������?�� ���� �Լ�
{
	if (!TheTextureManager::Instance()->load(fileName, id))
	{
		return false;
	}
}