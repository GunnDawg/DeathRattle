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
	Texture m_cursor                = Texture("Assets/Graphics/common/cursor.png");
	Texture m_background            = Texture("Assets/Graphics/common/main_background.png");
	Texture m_comingSoon            = Texture("Assets/Graphics/leaderboard_scene/comingsoon.png");
	
	SDL_Rect m_comingSoonBox        = { 0 };

	Sound m_thud                    = Sound("Assets/Audio/thud.wav");
};