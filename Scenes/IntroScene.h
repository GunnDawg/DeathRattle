#pragma once
#include <memory>
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Audio/Sound.h"
#include "Time/Timer.h"

class IntroSceneState : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	bool m_isBlood = false;
	bool m_isSkull = false;
	bool m_isClicked = false;

	Timer m_timer;

	Texture m_background;
	Texture m_keepIt;
	Texture m_alive;
	Texture m_plug;
	Texture m_version;

	Texture m_press;
	Texture m_enter;

	Texture m_blood;
	Texture m_skull;
	Texture m_skullWhite;

	Texture m_cursor;

	SDL_Rect m_plugBox = {};
	SDL_Rect m_skullBox = {};
	SDL_Rect m_skullCollider = {};

	Sound m_introSound;
	Sound m_scare;
};