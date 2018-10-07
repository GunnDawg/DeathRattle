#pragma once
#include "../StateMachine/GameState.h"
#include "../Player.h"

class GameplayState : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;
	void unload_All() override;

private:
	Player m_Player;
};