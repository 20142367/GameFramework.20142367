#include "MenuState.h"
#include "PlayState.h"
#include "Game.h"
#include "MenuButton.h"
#include "LevelState.h"

const std::string MenuState::s_menuID = "MENU";

MenuState* MenuState::s_pInstance = 0;

MenuState::MenuState()
{
}

void MenuState::update()
{
	GameState::update();
}

void MenuState::render()
{
	GameState::render();
}

bool MenuState::onEnter()		// MenuState 진입 시
{
	// 스프라이트 로드
	GameState::loadTexture("assets/button.png", "playbutton");
	GameState::loadTexture("assets/exit.png", "exitbutton");

	// 객체 설정
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToLevel);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);

	// 배열에 push
	GameState::push(button1, button2);

	std::cout << "entering MenuState" << std::endl;

	return true;
}

bool MenuState::onExit()		// MenuState 종료 시
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	std::cout << "Exiting MenuState" << std::endl;

	return true;
}

void MenuState::s_menuToLevel()		// Play 버튼 선택 시, PlayState로 전환
{
	TheGame::Instance()->getStateMachine()->changeState(LevelState::Instance());

	std::cout << "Play button clicked\n";
}

void MenuState::s_exitFromMenu()		// Exit 버튼 선택 시, 게임종료
{
	TheGame::Instance()->quit();

	std::cout << "Exit button clicked\n";
}

MenuState* MenuState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new MenuState();
		return s_pInstance;
	}
	return s_pInstance;
}