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
	std::array<Texture, 2> m_skulls;
	Texture m_title;
	Texture m_background;
	Texture m_devName;
	Texture m_newGame;
	Texture m_newGameWhite;
	Texture m_options;
	Texture m_optionsWhite;
	Texture m_leaderBoard;
	Texture m_leaderBoardWhite;
	Texture m_credits;
	Texture m_creditsWhite;
	Texture m_exit;
	Texture m_exitWhite;
	Texture m_version;

	Texture m_cursor;

	SDL_Rect m_titleBox = {};
	SDL_Rect m_menuBox = {};
	SDL_Rect m_menuBoxOutline = {};
	SDL_Rect m_devNameBox = {};

	Sound m_swoosh;

	bool m_isNewGame = false;
	bool m_isOptions = false;
	bool m_isLeaderBoard = false;
	bool m_isCredits = false;
	bool m_isExit = false;
};