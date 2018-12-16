#include "ManualState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "LevelState.h"

const std::string ManualState::s_gameOverID = "Manual";

ManualState* ManualState::s_pInstance = 0;

ManualState::ManualState()
{

}

void ManualState::s_ManualToLevel()		// MenuState�� ��ȯ
{
	TheGame::Instance()->getStateMachine()->changeState(LevelState::Instance());
}

void ManualState::update()
{
	GameState::update();
}

void ManualState::render()
{
	GameState::render();
}

bool ManualState::onEnter()		// GameOverState ���� �� ����
{
	// ���ӿ���â���� ����ϴ� �̹��� �ε�
	GameState::loadTexture("assets/Manual.png", "Manual");

	// ��ü ����
	GameObject* manual = new MenuButton(new LoaderParams(0, 0, 640, 480, "Manual"), s_ManualToLevel);

	// �迭�� push
	GameState::push(manual);

	std::cout << "entering ManualState\n";
	return true;
}

bool ManualState::onExit()		// GameOverState ���� �� ����
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("Manual");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting ManualState" << std::endl;
	return true;
}

ManualState* ManualState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new ManualState();
		return s_pInstance;
	}
	return s_pInstance;
}