#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";

PlayState* PlayState::s_pInstance = 0;

PlayState::PlayState()
{
}

void PlayState::update()
{
	GameState::update();

	for (int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles[i]->update();
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		m_obstacles[i]->update();
	}

	for (int i = 1; i < m_gameObjects.size(); i++)
	{
		for (int j = 0; j < m_tiles.size(); j++)
		{
			if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[i]), dynamic_cast<SDLGameObject*>(m_tiles[j])))
			{
				m_tiles[j]->clean();
				m_gameObjects[i]->clean();
			}
		}
	}

	for (int i = 1; i < m_gameObjects.size(); i++)
	{
		if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[i])))		// �浹 üũ
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
		}
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_obstacles[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
		}
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))		// ESC Ű �ٿ� ��, PauseState�� �̵�
	{
		TheGame::Instance()->getStateMachine()->changeState(new PauseState());
	}
}

void PlayState::render()
{
	GameState::render();

	for (int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles[i]->draw();
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		m_obstacles[i]->draw();
	}
}

bool PlayState::onEnter()		// PlayState ���� ��
{

	// ��������Ʈ �ε�
	GameState::loadTexture("assets/helicopter_.png", "helicopter");
	GameState::loadTexture("assets/helicopter2.png", "helicopter2");
	GameState::loadTexture("assets/projectile.png", "tile");
	GameState::loadTexture("assets/obstacle1.png", "obstacle1");

	// ��ü ����
	GameObject* player = new Player(new LoaderParams(50, 220, 50, 30, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(50, 0, 128, 55, "helicopter2"));
	Obstacle* obstacle = new Obstacle(new LoaderParams(200, 100, 100, 300, "obstacle1"));

	// �迭�� push
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	m_obstacles.push_back(obstacle);

	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()		// PlayState ���� ��
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	TheTextureManager::Instance()->clearFromTextureMap("tile");

	m_tiles.clear();

	std::cout << "exiting PlayState" << std::endl;
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)		// �浹üũ �Լ� ����
{
	int leftA, leftB;		// �簢���� ���� ��ǥ�� x��
	int rightA, rightB;		// �簢���� ������ ��ǥ�� x��
	int topA, topB;			// �簢���� ���� ��ǥ�� y��
	int bottomA, bottomB;	// �簢���� �Ʒ��� ��ǥ�� y��

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

PlayState* PlayState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new PlayState();
		return s_pInstance;
	}
	return s_pInstance;
}