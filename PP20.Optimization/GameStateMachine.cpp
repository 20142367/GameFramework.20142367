#include "GameStateMachine.h"

void GameStateMachine::popState()		// 이전의 State로 돌아감
{
	changeState(m_prevState);
}

void GameStateMachine::changeState(GameState *pState)		// 새로운 State로 바꿔줌
{
	if (pState != NULL)
	{
		if (m_currentState != NULL)
		{
			m_prevState = m_currentState;
			m_currentState->onExit();
		}

		m_currentState = pState;
		m_currentState->onEnter();
	}
}

void GameStateMachine::update()
{
	if (m_currentState != NULL)
		m_currentState->update();
}

void GameStateMachine::render()
{
	if (m_currentState != NULL)
		m_currentState->render();
}