#pragma once
#include "Audio/Sound.h"
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"

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

	Texture m_graphicsDesign;
	Texture m_mj;

	Texture m_sound;
	Texture m_jun;
	Texture m_savage;
	Texture m_reitanna;

	Texture m_pageOne;
	Texture m_pageTwo;
	Texture m_pageThree;

	Texture m_devName;
	Texture m_version;

	Texture m_cursor;

	Texture m_rightArrow;
	Texture m_rightArrowWhite;
	Texture m_leftArrow;
	Texture m_leftArrowWhite;

	SDL_Rect m_devNameBox;
	SDL_Rect m_creditsBox;
	SDL_Rect m_creditBoxOutline;
	SDL_Rect m_titleBox;

	bool m_isRight = false;
	bool m_isLeft = false;
	int m_pageNum = 0;

	Sound m_thud;
};