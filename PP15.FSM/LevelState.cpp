#include "LevelState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "PlayState.h"

const std::string LevelState::s_levelID = "Level";

LevelState* LevelState::s_pInstance = 0;

LevelState::LevelState()
{
}

void LevelState::s_normalPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	LevelState::Instance()->level = "normal";
}

void LevelState::s_hardPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	LevelState::Instance()->level = "hard";
}

void LevelState::update()
{
	GameState::update();
}

void LevelState::render()
{
	GameState::render();
}

bool LevelState::onEnter()		// PauseState 진입 시
{
	// 스프라이트 로드
	GameState::loadTexture("assets/normal.png", "normal");
	GameState::loadTexture("assets/hard.png", "hard");

	// 객체 생성
	GameObject* button2 = new MenuButton(new LoaderParams(200, 100, 200, 80, "normal"), s_normalPlay);
	GameObject* button3 = new MenuButton(new LoaderParams(200, 300, 200, 80, "hard"), s_normalPlay);

	// 배열에 push
	GameState::push(button2, button3);

	std::cout << "entering LevelState" << std::endl;
	return true;
}

bool LevelState::onExit()		// PauseState 종료 시
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("normal");
	TheTextureManager::Instance()->clearFromTextureMap("hard");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting LevelState" << std::endl;
	return true;
}

LevelState* LevelState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new LevelState();
		return s_pInstance;
	}
	return s_pInstance;
}