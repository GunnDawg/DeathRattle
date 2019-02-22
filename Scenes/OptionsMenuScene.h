#pragma once
#include <memory>
#include <array>
#include "Audio/Sound.h"
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Graphics/Animation.h"
#include "Audio/MusicManager.h"

class Game;

class OptionsMenuScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Game* game                               = nullptr;
									         
	std::array<Texture, 2> m_skulls          = { Texture("Assets/Graphics/common/skull.png"),
										         Texture("Assets/Graphics/common/skull.png") };
									         
	MusicManager* JukeBox                    = &MusicManager::getInstance();
									         
	Texture m_options                        = Texture("Assets/Graphics/options_menu/options.png");
	Texture m_apply                          = Texture("Assets/Graphics/options_menu/apply.png");
	Texture m_applyRed                       = Texture("Assets/Graphics/options_menu/apply_red.png");
	Texture m_back                           = Texture("Assets/Graphics/options_menu/back.png");
	Texture m_backRed                        = Texture("Assets/Graphics/options_menu/back_red.png");
									         
	Texture m_displayCheckMark               = Texture("Assets/Graphics/options_menu/checkmark.png");
	Texture m_menuMusicCheckMark             = Texture("Assets/Graphics/options_menu/checkmark.png");
	Texture m_gameplayMusicCheckMark         = Texture("Assets/Graphics/options_menu/checkmark.png");
	Texture m_soundEffectsCheckMark          = Texture("Assets/Graphics/options_menu/checkmark.png");
									         
	Texture m_displayMode                    = Texture("Assets/Graphics/options_menu/display_mode.png");
	Texture m_fullScreen                     = Texture("Assets/Graphics/options_menu/fullscreen.png");
	Texture m_windowed                       = Texture("Assets/Graphics/options_menu/windowed.png");
									         
	Texture m_audioSettings                  = Texture("Assets/Graphics/options_menu/audio_settings.png");
	Texture m_menuMusic                      = Texture("Assets/Graphics/options_menu/menu_music.png");
	Texture m_gameplayMusic                  = Texture("Assets/Graphics/options_menu/gameplay_music.png");
	Texture m_soundEffects                   = Texture("Assets/Graphics/options_menu/sound_effects.png");
									         
	//Common types					         
	Texture m_background                     = Texture("Assets/Graphics/common/main_background.png");
	Texture m_title                          = Texture("Assets/Graphics/common/title.png");
	Texture m_devName                        = Texture("Assets/Graphics/common/dev_name.png");
	Texture m_version                        = Texture("Assets/Graphics/common/version.png");
	Texture m_cursor                         = Texture("Assets/Graphics/common/cursor.png");
									         
	std::array<Animation, 2> m_Flames        = { Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00),
									             Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00) };
									         
	SDL_Rect m_optionsBox                    = { 0 };
	SDL_Rect m_optionsBoxOutline             = { 0 };
	SDL_Rect m_fullScreenBox                 = { 0 };
	SDL_Rect m_fullScreenBoxOutline          = { 0 };
	SDL_Rect m_windowedBox                   = { 0 };
	SDL_Rect m_windowedBoxOutline            = { 0 };
	SDL_Rect m_soundEffectsBox               = { 0 };
	SDL_Rect m_soundEffectsBoxOutline        = { 0 };
	SDL_Rect m_menuMusicBox                  = { 0 };
	SDL_Rect m_menuMusicBoxOutline           = { 0 };
	SDL_Rect m_gameplayMusicBox              = { 0 };
	SDL_Rect m_gameplayMusicBoxOutline       = { 0 };
	SDL_Rect m_devNameBox                    = { 0 };
	SDL_Rect m_titleBox                      = { 0 };
									         
	bool m_isFullScreen                      = false;
	bool m_isWindowed                        = true;
									         
	bool m_fullScreenEnabled                 = false;
	bool m_windowedEnabled                   = true;
									         
	bool m_isApply                           = false;
	bool m_isBack                            = false;
	bool m_isSoundEffects                    = true;
	bool m_isMenuMusic                       = true;
	bool m_isGameplayMusic                   = true;
									         
	bool m_soundEffectsEnabled               = true;
	bool m_menuMusicEnabled                  = true;
	bool m_gameplayMusicEnabled              = true;
									         
	Sound m_thud                             = Sound("Assets/Audio/thud.wav");
};