#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

MenuState* MenuState::s_pInstance = 0;

MenuState::MenuState()
{
}

void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState" << std::endl;

	return true;
}

bool MenuState::onExit()
{
	std::cout << "Exiting MenuState" << std::endl;

	return true;
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