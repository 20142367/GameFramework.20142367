#include "ClearState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "InputHandler.h"

const std::string ClearState::s_gameOverID = "CLEAR";

ClearState* ClearState::s_pInstance = 0;

ClearState::ClearState()
{

}

void ClearState::s_clearToMain()		// MainMenu ��ư ���� ��, MenuState�� ��ȯ
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void ClearState::s_restartPlay()		// Restart ��ư ���� ��, PlayState�� ��ȯ
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

void ClearState::update()
{
	GameState::update();
}

void ClearState::render()
{
	GameState::render();
}

bool ClearState::onEnter()		// GameOverState ���� �� ����
{
	// ���ӿ���â���� ����ϴ� �̹��� �ε�
	GameState::loadTexture("assets/clear_.png", "cleartext");
	GameState::loadTexture("assets/main.png", "mainbutton");
	GameState::loadTexture("assets/restart.png", "restartbutton");

	// ��ü ����
	GameObject* clearText = new AnimatedGraphic(new  LoaderParams(175, 40, 250, 120, "cleartext"), 5);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), s_clearToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), s_restartPlay);

	// �迭�� push
	GameState::push(clearText, button1, button2);

	std::cout << "entering clearState\n";
	return true;
}

bool ClearState::onExit()		// GameOverState ���� �� ����
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("cleartext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting clearState" << std::endl;
	return true;
}

ClearState* ClearState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new ClearState();
		return s_pInstance;
	}
	return s_pInstance;
}