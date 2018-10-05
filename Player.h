#pragma once
#include <SDL.h>
#include <cstdio>
#include <cassert>

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
	int m_textureWidth;
	int m_textureHeight;

	float m_frameCounter = 0.0f;
	int m_frameWidth = 0;
	int m_frameHeight = 0;

	float m_moveSpeed = 0.25f;
};