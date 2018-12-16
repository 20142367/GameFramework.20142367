#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState* PauseState::s_pInstance = 0;

PauseState::PauseState()
{
}

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	GameState::update();
}

void PauseState::render()
{
	GameState::render();
}

bool PauseState::onEnter()		// PauseState 진입 시
{
	// 스프라이트 로드
	GameState::loadTexture("assets/resume.png", "resumebutton");
	GameState::loadTexture("assets/main.png", "mainbutton");

	// 객체 생성
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), s_resumePlay);

	// 배열에 push
	GameState::push(button1, button2);

	std::cout << "entering PauseState" << std::endl;
	return true;
}

bool PauseState::onExit()		// PauseState 종료 시
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting PauseState" << std::endl;
	return true;
}

PauseState* PauseState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new PauseState();
		return s_pInstance;
	}
	return s_pInstance;
}
