#pragma once
#include "../Audio/Sound.h"
#include "../StateMachine/GameState.h"
#include "../Graphics/Texture.h"

class CreditsScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_background;
	Texture m_title;

	Texture m_leadProgramming;
	Texture m_calvin;

	Texture m_additionalProgramming;
	Texture m_kelson;
	Texture m_panda;
	Texture m_jeff;

	Texture m_thanks;

	Texture m_devName;
	Texture m_version;

	Texture m_cursor;

	SDL_Rect m_devNameBox;
	SDL_Rect m_creditsBox;
	SDL_Rect m_creditBoxOutline;
	SDL_Rect m_titleBox;

	Sound m_thud;
};