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

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))		// 충돌 체크
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))		// ESC 키 다운 시, PauseState로 이동
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

bool PlayState::onEnter()		// PlayState 진입 시
{
	// 스프라이트 로드
	GameState::loadTexture("assets/helicopter.png", "helicopter");
	GameState::loadTexture("assets/helicopter2.png", "helicopter2");
	GameState::loadTexture("assets/projectile.png", "tile");

	// 객체 생성
	GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));

	// 배열에 push
	GameState::push(player, enemy);

	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()		// PlayState 종료 시
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	TheTextureManager::Instance()->clearFromTextureMap("tile");

	std::cout << "exiting PlayState" << std::endl;
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)		// 충돌체크 함수 정의
{
	int leftA, leftB;		// 사각형의 왼쪽 좌표의 x값
	int rightA, rightB;		// 사각형의 오른쪽 좌표의 x값
	int topA, topB;			// 사각형의 위쪽 좌표의 y값
	int bottomA, bottomB;	// 사각형의 아래쪽 좌표의 y값

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