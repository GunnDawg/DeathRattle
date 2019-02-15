#include "Ball.h"
#include "Game.h"

Ball::Ball(Settings::GamePlay::GameDifficulty speed)
{
	game = &Game::GetInstance();

	mBallTexture = Texture("Assets/Graphics/gameplay_scene/ball.png");

	setSpeed(speed);
	setAngle(randomizeAng());
}

void Ball::resetBall(Settings::GamePlay::GameDifficulty speed)
{
	mPosX = (Settings::Display::WindowWidth / 2) - 25;
	mPosY = (Settings::Display::WindowHeight / 2) - 25;

	mRotationAngle = 0.0;
	
	setSpeed(speed);
	setAngle(randomizeAng());

	mIsDead = false;
}

void Ball::setSpeed(Settings::GamePlay::GameDifficulty speed)
{
	switch (speed)
	{
		case Settings::GamePlay::GameDifficulty::EASY:
		{
			mSpeed = 0.35;
		} break;

		case Settings::GamePlay::GameDifficulty::MEDIUM:
		{
			mSpeed = 0.50;
		} break;

		case Settings::GamePlay::GameDifficulty::HARD:
		{
			mSpeed = 0.70;
		} break;

	default:
		break;
	}
}

void Ball::Load()
{
	mBallTexture.Load();
}

void Ball::Unload()
{
	mBallTexture.Unload();
}

void Ball::Draw()
{
	mBallRect.w = mBallWidth;
	mBallRect.h = mBallHeight;
	mBallRect.x = mPosX;
	mBallRect.y = mPosY;

	if (mIsDead)
	{
		SDL_SetTextureColorMod(mBallTexture.mTexture, 255, 0, 0);
	}
	else
	{
		SDL_SetTextureColorMod(mBallTexture.mTexture, 255, 255, 255);
	}

	SDL_RenderCopyEx(game->Renderer, mBallTexture.mTexture, nullptr, &mBallRect, mRotationAngle, nullptr, SDL_FLIP_NONE);
}

void Ball::Update()
{
	mPosX += static_cast<unsigned int>(mVelocityX * game->avgDeltaTime);
	mPosY += static_cast<unsigned int>(mVelocityY * game->avgDeltaTime);

	if (mVelocityX > 0)
	{
		mRotationAngle += (mSpeed * game->avgDeltaTime);
	}
	else
	{
		mRotationAngle -= (mSpeed * game->avgDeltaTime);
	}
}

void Ball::setAngle(double angle)
{
	mAngle = angle;

	mVelocityX = ((cos(mAngle)) * mSpeed);
	mVelocityY = ((sin(mAngle)) * mSpeed);
}

double Ball::randomizeAng()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<double> dis(-3.0, 3.0);

	double r = dis(gen);

	return r;
}