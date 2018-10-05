#pragma once
#include "GameState.h"
#include "../Player.h"

class PlayerSceneState : public GameState
{
public:
	void on_enter(SDL_Renderer* passedRenderer) override;
	void on_exit() override;
	void update(double dt) override;
	void handle_events() override;
	void draw(SDL_Renderer* passedRenderer) override;

private:
	Player m_Player;
};