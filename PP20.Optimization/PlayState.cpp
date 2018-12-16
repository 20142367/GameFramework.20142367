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

	for (int i = 0; i < m_tile.size(); i++)
	{
		m_tile[i]->update();
	}

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))		// �浹 üũ
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))		// ESC Ű �ٿ� ��, PauseState�� �̵�
	{
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
}

void PlayState::render()
{
	GameState::render();

	for (int i = 0; i < m_tile.size(); i++)
	{
		m_tile[i]->draw();
	}
}

bool PlayState::onEnter()		// PlayState ���� ��
{
	// ��������Ʈ �ε�
	GameState::loadTexture("assets/helicopter.png", "helicopter");
	GameState::loadTexture("assets/helicopter2.png", "helicopter2");
	GameState::loadTexture("assets/projectile.png", "tile");

	// ��ü ����
	GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));

	// �迭�� push
	GameState::push(player, enemy);

	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()		// PlayState ���� ��
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	TheTextureManager::Instance()->clearFromTextureMap("tile");

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