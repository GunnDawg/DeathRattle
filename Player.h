#pragma once
#include <SDL.h>
#include <cstdio>
#include <cassert>
#include "StateMachine/GameState.h"
#include "StateMachine/GameStateMachine.h"
#include "Graphics/Texture.h"

class Player
{
public:
	Player();
	~Player();

	void on_enter(SDL_Renderer* passedRenderer);
	void on_exit();
	void update(double dt);
	void draw(SDL_Renderer* passedRenderer);

private:
	SDL_Rect m_playerRect;
	SDL_Rect m_cropRect;
	Texture m_playerTexture;

	float m_moveSpeed = 25.0f;
};