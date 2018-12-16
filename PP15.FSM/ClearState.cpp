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

void ClearState::s_clearToMain()		// MainMenu 버튼 선택 시, MenuState로 전환
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void ClearState::s_restartPlay()		// Restart 버튼 선택 시, PlayState로 전환
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

bool ClearState::onEnter()		// GameOverState 진입 시 실행
{
	// 게임오버창에서 사용하는 이미지 로드
	GameState::loadTexture("assets/clear_.png", "cleartext");
	GameState::loadTexture("assets/main.png", "mainbutton");
	GameState::loadTexture("assets/restart.png", "restartbutton");

	// 객체 생성
	GameObject* clearText = new AnimatedGraphic(new  LoaderParams(175, 40, 250, 120, "cleartext"), 5);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), s_clearToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), s_restartPlay);

	// 배열에 push
	GameState::push(clearText, button1, button2);

	std::cout << "entering clearState\n";
	return true;
}

bool ClearState::onExit()		// GameOverState 종료 시 실행
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