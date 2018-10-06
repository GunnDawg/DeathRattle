#pragma once
#include "StateMachine/GameStateMachine.h"
#include "StateMachine/GameState.h"
#include "../Graphics/Texture.h"
#include <memory>

class IntroSceneState : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

private:
	Texture m_gameNameTexture;
	Texture m_pressEnter;
};