#pragma once
#include <memory>
#include "StateMachine/GameState.h"
#include "IntroScene.h"
#include "Graphics/Texture.h"
#include "Audio/Sound.h"
#include "Time/Timer.h"

class Game;

class SplashScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Game* game                      = nullptr;

	Texture m_background            = Texture("Assets/Graphics/splash_scene/background.png");
	Texture m_production            = Texture("Assets/Graphics/splash_scene/production.png");
	Texture m_logo                  = Texture("Assets/Graphics/common/GGlogo.png");

	Sound m_introSound              = Sound("Assets/Audio/intro.wav");

	SDL_Rect m_comingSoonBox        = { 0 };

	Timer m_timer;
};