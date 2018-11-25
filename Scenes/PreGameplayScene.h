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

	std::array<Texture, 2> m_skulls    = { Texture("Assets/Graphics/common/skull.png"),
										   Texture("Assets/Graphics/common/skull.png") };

	Texture m_cursor                   = Texture("Assets/Graphics/common/cursor.png");
	Texture m_title                    = Texture("Assets/Graphics/common/title.png");
	Texture m_background               = Texture("Assets/Graphics/common/main_background.png");
	Texture m_devName                  = Texture("Assets/Graphics/common/dev_name.png");
	Texture m_version                  = Texture("Assets/Graphics/common/version.png");

	Texture m_selectDifficulty         = Texture("Assets/Graphics/pregameplay_scene/difficulty.png");
	Texture m_easyRed                  = Texture("Assets/Graphics/pregameplay_scene/easy_red.png");
	Texture m_easyWhite                = Texture("Assets/Graphics/pregameplay_scene/easy_white.png");
	Texture m_mediumRed                = Texture("Assets/Graphics/pregameplay_scene/medium_red.png");
	Texture m_mediumWhite              = Texture("Assets/Graphics/pregameplay_scene/medium_white.png");
	Texture m_hardRed                  = Texture("Assets/Graphics/pregameplay_scene/hard_red.png");
	Texture m_hardWhite                = Texture("Assets/Graphics/pregameplay_scene/hard_white.png");

	std::array<Animation, 2> m_Flames  = { Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00),
									       Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00) };

	SDL_Rect m_difficultyBox           = { 0 };
	SDL_Rect m_difficultyBoxOUtline    = { 0 };
	SDL_Rect m_titleBox                = { 0 };
	SDL_Rect m_devNameBox              = { 0 };

	Sound m_thud                       = Sound("Assets/Audio/thud.wav");
};