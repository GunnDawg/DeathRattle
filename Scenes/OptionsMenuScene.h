#pragma once
#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include <memory>

class OptionsMenuScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;
	void unload_All() override;

private:
	Texture m_background;
	Texture m_title;

	SDL_Rect m_titleBox;
};