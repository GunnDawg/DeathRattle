#pragma once
#include <SDL.h>
#include <cassert>
#include <random>

#include "GameSettings.h"
#include "Graphics/Texture.h"

class Game;

class Ball
{
public:
	Ball()=default;
	Ball(Settings::GamePlay::GameDifficulty speed);
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

	inline void setDead(bool dead) { m_isDead = dead; }

	inline void addSpeed(float speed) { m_speed += speed; }
	inline void removeSpeed(float speed) { m_speed -= speed; }

	void resetBall(Settings::GamePlay::GameDifficulty speed);
	double randomizeAng();

	unsigned int m_posX = (Settings::Display::WindowWidth / 2) - 25;
	unsigned int m_posY = (Settings::Display::WindowHeight / 2) - 25;

	double m_angle = 0.0;

private:
	Game* game                         = nullptr;

	void setSpeed(Settings::GamePlay::GameDifficulty speed);

	Texture m_ballTexture;

	SDL_Rect m_ballRect                = { 0 };
	const unsigned int m_ballWidth     = 50;
	const unsigned int m_ballHeight    = 50;

	double m_speed                     = 0.0;
	double m_velocityX                 = 0.0;
	double m_velocityY                 = 0.0;
	double m_rotationAngle             = 0.0;

	bool m_isDead                      = false;

	Ball(const Ball& obj) = delete;
	Ball& operator=(const Ball&) = delete;
};