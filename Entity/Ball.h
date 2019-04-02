#pragma once
extern "C"
{
	#include <SDL.h>
}

#include "GameSettings.h"
#include "Graphics/Texture.h"

class Game;

class Ball
{
public:
	Ball()=default;
	Ball(Settings::GamePlay::GameDifficulty speed);

	void Load();
	void Unload();
	void Draw();
	void Update();
	void setAngle(double angle);

	inline SDL_Rect getRect() const { return mBallRect; }
	inline double getSpeed() const { return mSpeed; }
	inline unsigned int getX() const { return mPosX; }
	inline unsigned int getY() const { return mPosY; }

	inline void setDead(bool dead) { mIsDead = dead; }

	inline void addSpeed(float speed) { mSpeed += speed; }
	inline void removeSpeed(float speed) { mSpeed -= speed; }

	void resetBall(Settings::GamePlay::GameDifficulty speed);
	double randomizeAng();

	unsigned int mPosX = (Settings::Display::WindowWidth / 2) - 25;
	unsigned int mPosY = (Settings::Display::WindowHeight / 2) - 25;

private:
	Game* game                         = nullptr;
									   
	void setSpeed(Settings::GamePlay:: GameDifficulty speed);
									   
	Texture mBallTexture;			   
									   
	SDL_Rect mBallRect                 = { 0 };
	const unsigned int mBallWidth      = 50;
	const unsigned int mBallHeight     = 50;
									   
	double mSpeed                      = 0.0;
	double mVelocityX                  = 0.0;
	double mVelocityY                  = 0.0;
	double mAngle                      = 0.0;
	double mRotationAngle              = 0.0;
									   
	bool mIsDead                       = false;
};