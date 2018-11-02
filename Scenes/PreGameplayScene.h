#pragma once
#include <memory>
#include <array>
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Audio/Sound.h"
#include "Time/Timer.h"
#include "Graphics/Animation.h"

class PreGameplayScene : public GameState
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

	std::array<Texture, 2> m_skulls;

	Texture m_cursor;
	Texture m_title;
	Texture m_background;
	Texture m_devName;
	Texture m_version;

	std::array<Animation, 2> m_Flames =          { Animation("Assets/Graphics/Animations/flames.png", 8, 4),
												   Animation("Assets/Graphics/Animations/flames.png", 8, 4) };

	SDL_Rect m_difficultyBox;
	SDL_Rect m_difficultyBoxOUtline;
	SDL_Rect m_titleBox;
	SDL_Rect m_devNameBox;

	Sound m_thud = Sound("Assets/Audio/thud.wav");
};