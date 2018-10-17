#pragma once

#include <SDL.h>
#include <cassert>
#include <cstdio>
#include <memory>
#include <random>

#include "Graphics/Texture.h"
#include "Game.h"

class Ball
{
public:
	Ball()=default;
	Ball(unsigned int speed);
	~Ball()=default;

	void Load();
	void Unload();
	void Draw();
	void Update();
	void setAngle(double angle);

	inline const SDL_Rect& getRect() { return m_ballRect; }
	inline float getSpeed() const { return m_speed; }
	inline unsigned int getX() const { return m_posX; }
	inline unsigned int getY() const { return m_posY; }

	inline void setSpeed(unsigned int speed) { m_speed = speed; }

	inline void setDead(bool dead) { m_isDead = dead; }

	inline void addSpeed(float speed) { m_speed += speed; }
	inline void removeSpeed(float speed) { m_speed -= speed; }

	void resetBall(unsigned int w, unsigned int h, unsigned int difficulty);
	double randomizeAng();

	unsigned int m_posX = (Game::screenWidth / 2) - 40;
	unsigned int m_posY = (Game::screenHeight / 2) - 25;

	double m_angle;

private:
	//Ball(const Ball& obj)=delete;
	//Ball& operator=(const Ball&)=delete;

	Texture m_ballTexture;

	SDL_Rect m_ballRect;
	const unsigned int m_ballWidth;
	const unsigned int m_ballHeight;

	double m_velocityX;
	double m_velocityY;

	float m_speed;

	bool m_isDead;
};