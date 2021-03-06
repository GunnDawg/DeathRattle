#pragma once
#include <array>
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Audio/Sound.h"
#include "Time/Timer.h"
#include "Graphics/Animation.h"

class Game;

class IntroSceneState : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Game* game                                = nullptr;
									          
	Timer m_timer;					          
									          
	Texture m_cursor                          = Texture("Assets/Graphics/common/cursor.png");
									          
	Texture m_background                      = Texture("Assets/Graphics/common/main_background.png");
	Texture m_title                           = Texture("Assets/Graphics/intro_scene/title.png");
	Texture m_howLong                         = Texture("Assets/Graphics/intro_scene/how_long.png");
	Texture m_plug                            = Texture("Assets/Graphics/intro_scene/plug.png");
	Texture m_version                         = Texture("Assets/Graphics/common/version.png");
									          
	Texture m_press                           = Texture("Assets/Graphics/intro_scene/press.png");
	Texture m_enter                           = Texture("Assets/Graphics/intro_scene/enter.png");
									          
	Texture m_blood                           = Texture("Assets/Graphics/intro_scene/blood.png");
	Texture m_skull                           = Texture("Assets/Graphics/intro_scene/skull.png");
	Texture m_skullWhite                      = Texture("Assets/Graphics/intro_scene/skull_white.png");
									          
	std::array<Animation, 2> m_Flames         = { Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00),
									 	          Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00) };
									          
	SDL_Rect m_plugBox                        = { 0 };
	SDL_Rect m_skullBox                       = { 0 };
	SDL_Rect m_skullCollider                  = { 0 };
									          
	Sound m_introSound                        = Sound("Assets/Audio/splat.wav");
	Sound m_scare                             = Sound("Assets/Audio/scare.wav");
									          
	bool m_isBlood                            = false;
	bool m_isSkull                            = false;
	bool m_isClicked                          = false;
	bool mFadeIn                              = false;
	bool mFadeOut                             = true;
	float mFadeValue                          = 255.0f;
};