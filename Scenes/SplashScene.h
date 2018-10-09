#pragma once
#include "StateMachine/GameState.h"
#include "IntroScene.h"
#include "Graphics/Texture.h"
#include "Audio/Sound.h"
#include "Time/Timer.h"
#include <memory>

class SplashScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_background;
	Texture m_logo;
	Texture m_production;

	Sound m_introSound;

	SDL_Rect m_comingSoonBox;

	Timer m_timer;
};