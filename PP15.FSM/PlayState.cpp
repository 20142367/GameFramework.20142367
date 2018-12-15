#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";
const float feedTime = 3000.0f;
Uint32 startFeed, currentFeed;

PlayState* PlayState::s_pInstance = 0;

PlayState::PlayState()
{
}

void PlayState::update()
{
	GameState::update();

	//for (int i = 0; i < m_tiles.size(); i++)
	//{
	//	m_tiles[i]->update();
	//}

	//for (int i = 1; i < m_gameObjects.size(); i++)
	//{
	//	for (int j = 0; j < m_tiles.size(); j++)
	//	{
	//		if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[i]), dynamic_cast<SDLGameObject*>(m_tiles[j])))
	//		{
	//			m_tiles[j]->clean();
	//			m_gameObjects[i]->clean();
	//		}
	//	}
	//}

	spawnFeed();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))		// ESC Ű �ٿ� ��, PauseState�� �̵�
	{
		TheGame::Instance()->getStateMachine()->changeState(new PauseState());
	}

	/*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_R))
	{
		TheGame::Instance()->getStateMachine()->changeState(new PlayState());
	}*/
}

void PlayState::render()
{
	GameState::render();

	/*for (int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles[i]->draw();
	}*/

}

bool PlayState::onEnter()		// PlayState ���� ��
{

	// ��������Ʈ �ε�
	GameState::loadTexture("assets/Background.png", "background");
	GameState::loadTexture("assets/map.png", "map");
	GameState::loadTexture("assets/head.png", "head");
	GameState::loadTexture("assets/body_.png", "body");
	GameState::loadTexture("assets/feed.png", "feed");
	GameState::loadTexture("assets/projectile.png", "tile");

	// ��ü ����
	GameObject* background = new Map(new LoaderParams(0, 0, 640, 480, "background"));
	GameObject* map = new Map(new LoaderParams(20, 30, 600, 420, "map"));
	Player* head = new Player(new LoaderParams(110, 210, 30, 30, "head"));

	// �迭�� push
	m_gameObjects.push_back(background);
	m_gameObjects.push_back(map);
	m_players.push_back(head);
	
	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()		// PlayState ���� ��
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("head");
	TheTextureManager::Instance()->clearFromTextureMap("body");
	//TheTextureManager::Instance()->clearFromTextureMap("tile");

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

bool PlayState::checkUnCollision(SDLGameObject* p1, SDLGameObject* p2)		// �浹üũ �Լ� ����
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
	if (bottomA <= topB) { return true; }
	if (topA >= bottomB) { return true; }
	if (rightA <= leftB) { return true; }
	if (leftA >= rightB) { return true; }
	return false;
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

void PlayState::spawnFeed()
{
	if (feedcount < 1)
	{
		Feed* feed = new Feed(new LoaderParams(((SDL_GetTicks() % 20) * 30) + 20, ((SDL_GetTicks() % 14) * 30) + 30, 30, 30, "feed"));
		m_feeds.push_back(feed);
		feedcount++;
	}
}