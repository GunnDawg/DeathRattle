#include "Ball.h"
#include "Game.h"

Ball::Ball(Settings::GamePlay::GameDifficulty speed)
{
	game = &Game::GetInstance();

	m_ballTexture = Texture("Assets/Graphics/gameplay_scene/ball.png");

	setSpeed(speed);
	setAngle(randomizeAng());
}

void Ball::resetBall(Settings::GamePlay::GameDifficulty speed)
{
	m_posX = (Settings::Display::WindowWidth / 2) - 25;
	m_posY = (Settings::Display::WindowHeight / 2) - 25;

	m_rotationAngle = 0.0;
	
	setSpeed(speed);
	setAngle(randomizeAng());

	m_isDead = false;
}

void Ball::setSpeed(Settings::GamePlay::GameDifficulty speed)
{
	switch (speed)
	{
		case Settings::GamePlay::GameDifficulty::EASY:
		{
			m_speed = 0.35;
		} break;

		case Settings::GamePlay::GameDifficulty::MEDIUM:
		{
			m_speed = 0.50;
		} break;

		case Settings::GamePlay::GameDifficulty::HARD:
		{
			m_speed = 0.70;
		} break;

	default:
		break;
	}
}

void Ball::Load()
{
	m_ballTexture.Load();
}

void Ball::Unload()
{
	m_ballTexture.Unload();
}

void Ball::Draw()
{
	m_ballRect.w = m_ballWidth;
	m_ballRect.h = m_ballHeight;
	m_ballRect.x = m_posX;
	m_ballRect.y = m_posY;

	if (m_isDead)
	{
		SDL_SetTextureColorMod(m_ballTexture.getTexture(), 255, 0, 0);
	}
	else
	{
		SDL_SetTextureColorMod(m_ballTexture.getTexture(), 255, 255, 255);
	}

	SDL_RenderCopyEx(game->Renderer, m_ballTexture.m_Texture, nullptr, &m_ballRect, m_rotationAngle, nullptr, SDL_FLIP_NONE);
}

void Ball::Update()
{
	m_posX += static_cast<unsigned int>(m_velocityX * game->avgDeltaTime);
	m_posY += static_cast<unsigned int>(m_velocityY * game->avgDeltaTime);

	if (m_velocityX > 0)
	{
		m_rotationAngle += (m_speed * game->avgDeltaTime);
	}
	else
	{
		m_rotationAngle -= (m_speed * game->avgDeltaTime);
	}
}

void Ball::setAngle(double angle)
{
	m_angle = angle;

	m_velocityX = ((cos(m_angle)) * m_speed);
	m_velocityY = ((sin(m_angle)) * m_speed);
}

double Ball::randomizeAng()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<double> dis(-3.0, 3.0);

	double r = dis(gen);

	return r;
}