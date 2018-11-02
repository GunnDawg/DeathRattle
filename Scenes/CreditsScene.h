#pragma once
#include <array>
#include "Audio/Sound.h"
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Graphics/Animation.h"

class CreditsScene : public GameState
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
	Texture m_logo                  = Texture("Assets/Graphics/common/GGlogo.png");

	Texture m_leadProgramming       = Texture("Assets/Graphics/credits_scene/lead_programming.png");
	Texture m_calvin                = Texture("Assets/Graphics/credits_scene/calvin.png");

	Texture m_additionalProgramming = Texture("Assets/Graphics/credits_scene/additional_programming.png");
	Texture m_kelson                = Texture("Assets/Graphics/credits_scene/kelson.png");
	Texture m_panda                 = Texture("Assets/Graphics/credits_scene/fancykillerpanda.png");
	Texture m_jeff                  = Texture("Assets/Graphics/credits_scene/jeff.png");

	Texture m_graphicsDesign        = Texture("Assets/Graphics/credits_scene/graphics_design.png");
	Texture m_mj                    = Texture("Assets/Graphics/credits_scene/mj.png");

	Texture m_sound                 = Texture("Assets/Graphics/credits_scene/sound.png");
	Texture m_jun                   = Texture("Assets/Graphics/credits_scene/jun.png");
	Texture m_savage                = Texture("Assets/Graphics/credits_scene/savage.png");
	Texture m_reitanna              = Texture("Assets/Graphics/credits_scene/reitanna.png");

	Texture m_pageOne               = Texture("Assets/Graphics/common/1of3.png");
	Texture m_pageTwo               = Texture("Assets/Graphics/common/2of3.png");
	Texture m_pageThree             = Texture("Assets/Graphics/common/3of3.png");

	Texture m_devName               = Texture("Assets/Graphics/common/dev_name.png");
	Texture m_version               = Texture("Assets/Graphics/common/version.png");

	Texture m_rightArrow            = Texture("Assets/Graphics/common/right_arrow.png");
	Texture m_rightArrowWhite       = Texture("Assets/Graphics/common/right_arrow_white.png");
	Texture m_leftArrow             = Texture("Assets/Graphics/common/left_arrow.png");
	Texture m_leftArrowWhite        = Texture("Assets/Graphics/common/left_arrow_white.png");

	std::array<Animation, 2> m_Flames =          { Animation("Assets/Graphics/Animations/flames.png", 8, 4),
												   Animation("Assets/Graphics/Animations/flames.png", 8, 4) };

	SDL_Rect m_devNameBox           = { 0 };
	SDL_Rect m_creditsBox           = { 0 };
	SDL_Rect m_creditBoxOutline     = { 0 };
	SDL_Rect m_titleBox             = { 0 };

	bool m_isRight                  = false;
	bool m_isLeft                   = false;
	int m_pageNum                   = 0;

	Sound m_thud                    = Sound("Assets/Audio/thud.wav");
};