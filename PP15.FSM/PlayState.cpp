#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;

PlayState::PlayState()
{
}

void PlayState::update()
{
}

void PlayState::render()
{
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState" << std::endl;
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