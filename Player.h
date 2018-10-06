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

	void on_enter();
	void on_exit();
	void update();
	void draw();

private:
	SDL_Rect m_playerRect;
	SDL_Rect m_cropRect;
	Texture m_playerTexture;
	int m_textureWidth;
	int m_textureHeight;

	double m_frameCounter = 0.0f;
	int m_frameWidth = 0;
	int m_frameHeight = 0;

	float m_moveSpeed = 0.50f;
};