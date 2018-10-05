#pragma once
#include <SDL.h>
#include <cstdio>
#include <cassert>
#include "StateMachine/GameState.h"
#include "StateMachine/GameStateMachine.h"
#include "Graphics/Texture.h"

class Player : public GameState
{
public:
	Player();
	~Player();

	void on_enter(SDL_Renderer* passedRenderer) override;
	void on_exit() override;
	void update(double dt) override;
	void handle_events() override;
	void draw(SDL_Renderer* passedRenderer);

private:
	SDL_Rect m_playerRect;
	SDL_Rect m_cropRect;
	Texture m_playerTexture;

	float m_moveSpeed = 25.0f;
};