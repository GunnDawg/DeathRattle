#pragma once
#include <memory>
#include <array>
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Audio/Sound.h"

class MainMenuScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	std::array<Texture, 2> m_skulls = {
		Texture("Assets/Graphics/common/skull.png"),
		Texture("Assets/Graphics/common/skull.png")
	};

	Texture m_cursor                = Texture("Assets/Graphics/common/cursor.png");
	Texture m_title                 = Texture("Assets/Graphics/common/title.png");
	Texture m_background            = Texture("Assets/Graphics/common/main_background.png");
	Texture m_devName               = Texture("Assets/Graphics/common/dev_name.png");
	Texture m_newGame               = Texture("Assets/Graphics/main_menu_scene/new_game.png");
	Texture m_newGameWhite          = Texture("Assets/Graphics/main_menu_scene/new_game_white.png");
	Texture m_options               = Texture("Assets/Graphics/main_menu_scene/options.png");
	Texture m_optionsWhite          = Texture("Assets/Graphics/main_menu_scene/options_white.png");
	Texture m_leaderBoard           = Texture("Assets/Graphics/main_menu_scene/leaderboard.png");
	Texture m_leaderBoardWhite      = Texture("Assets/Graphics/main_menu_scene/leaderboard_white.png");
	Texture m_credits               = Texture("Assets/Graphics/main_menu_scene/credits.png");
	Texture m_creditsWhite          = Texture("Assets/Graphics/main_menu_scene/credits_white.png");
	Texture m_exit                  = Texture("Assets/Graphics/main_menu_scene/exit.png");
	Texture m_exitWhite             = Texture("Assets/Graphics/main_menu_scene/exit_white.png");
	Texture m_version               = Texture("Assets/Graphics/common/version.png");


	SDL_Rect m_titleBox             = { 0 };
	SDL_Rect m_menuBox              = { 0 };
	SDL_Rect m_menuBoxOutline       = { 0 };
	SDL_Rect m_devNameBox           = { 0 };

	Sound m_swoosh                  = Sound("Assets/Audio/swoosh.wav");

	bool m_isNewGame                = false;
	bool m_isOptions                = false;
	bool m_isLeaderBoard            = false;
	bool m_isCredits                = false;
	bool m_isExit                   = false;
};