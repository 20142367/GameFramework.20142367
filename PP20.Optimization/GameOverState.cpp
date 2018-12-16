#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "InputHandler.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState* GameOverState::s_pInstance = 0;

GameOverState::GameOverState()
{
}

void GameOverState::s_gameOverToMain()		// MainMenu ��ư ���� ��, MenuState�� ��ȯ
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void GameOverState::s_restartPlay()		// Restart ��ư ���� ��, PlayState�� ��ȯ
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

void GameOverState::update()
{
	GameState::update();
}

void GameOverState::render()
{
	GameState::render();
}

bool GameOverState::onEnter()		// GameOverState ���� �� ����
{
	// ���ӿ���â���� ����ϴ� �̹��� �ε�
	GameState::loadTexture("assets/gameover.png", "gameovertext");
	GameState::loadTexture("assets/main.png", "mainbutton");
	GameState::loadTexture("assets/restart.png", "restartbutton");

	// ��ü ����
	GameObject* gameOverText = new AnimatedGraphic(new  LoaderParams(200, 100, 190, 30, "gameovertext"), 10);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), s_restartPlay);

	// �迭�� push
	GameState::push(gameOverText, button1, button2);

	std::cout << "entering GameOverState\n";
	return true;
}

bool GameOverState::onExit()		// GameOverState ���� �� ����
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting GameOverState" << std::endl;
	return true;
}

GameOverState* GameOverState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new GameOverState();
		return s_pInstance;
	}
	return s_pInstance;
}
