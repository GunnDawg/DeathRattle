#pragma once
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include <memory>

class LeaderBoardScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_background;
	Texture m_comingSoon;
	
	SDL_Rect m_comingSoonBox;
};