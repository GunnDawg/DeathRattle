#include "GameStateMachine.h"

void GameStateMachine::push(std::unique_ptr<GameState> states)
{
	m_gameStates.push_back(std::move(states));
}

void GameStateMachine::pop()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->on_exit();
		m_gameStates.pop_back();
	}
}

void GameStateMachine::update(double dt)
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update(dt);
	}
}