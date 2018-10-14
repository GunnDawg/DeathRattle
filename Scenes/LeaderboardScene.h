#pragma once
#include <memory>
#include "Audio/Sound.h"
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"

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
	Texture m_cursor;
	
	SDL_Rect m_comingSoonBox;

	Sound m_thud;
};