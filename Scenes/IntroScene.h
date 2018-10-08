#pragma once
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "../Audio/Sound.h"
#include <memory>

class IntroSceneState : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_background;
	Texture m_keepIt;
	Texture m_alive;
	Texture m_pressEnter;
	Texture m_plug;
	Texture m_website;

	Texture m_cursor;

	SDL_Rect m_plugBox;
	SDL_Rect m_websiteBox;
	SDL_Rect m_pressEnterBox;

	Sound m_introSound;
};