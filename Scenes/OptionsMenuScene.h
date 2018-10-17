#pragma once
#include <memory>
#include <array>
#include "Audio/Sound.h"
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"

class OptionsMenuScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_options;
	Texture m_apply;
	Texture m_applyRed;
	Texture m_back;
	Texture m_backRed;

	Texture m_displayCheckMark;
	Texture m_menuMusicCheckMark;
	Texture m_gameplayMusicCheckMark;
	Texture m_soundEffectsCheckMark;

	Texture m_displayMode;
	Texture m_fullScreen;
	Texture m_windowed;

	Texture m_audioSettings;
	Texture m_menuMusic;
	Texture m_gameplayMusic;
	Texture m_soundEffects;

	SDL_Rect m_optionsBox = {};
	SDL_Rect m_optionsBoxOutline = {};

	SDL_Rect m_fullScreenBox = {};
	SDL_Rect m_fullScreenBoxOutline = {};
	SDL_Rect m_windowedBox = {};
	SDL_Rect m_windowedBoxOutline = {};
	SDL_Rect m_soundEffectsBox = {};
	SDL_Rect m_soundEffectsBoxOutline = {};
	SDL_Rect m_menuMusicBox = {};
	SDL_Rect m_menuMusicBoxOutline = {};
	SDL_Rect m_gameplayMusicBox = {};
	SDL_Rect m_gameplayMusicBoxOutline = {};

	bool m_isFullScreen = false;
	bool m_fullScreenEnabled = false;
	bool m_isWindowed = true;
	bool m_windowedEnabled = true;
	bool m_isApply = false;
	bool m_isBack = false;
	bool m_isSoundEffects = true;
	bool m_isMenuMusic = true;
	bool m_isGameplayMusic = true;
	bool m_soundEffectsEnabled = true;
	bool m_menuMusicEnabled = true;
	bool m_gameplayMusicEnabled = true;

	//Common types
	Texture m_background;
	Texture m_title;
	Texture m_devName;
	Texture m_version;
	Texture m_cursor;

	std::array<Texture, 2> m_skulls;

	SDL_Rect m_devNameBox = {};
	SDL_Rect m_titleBox = {};

	Sound m_thud;
};