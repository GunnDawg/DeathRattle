#include "Ball.h"
#include "Game.h"

Ball::Ball(Settings::GamePlay::GameDifficulty speed)
{
	game = &Game::GetInstance();

	switch (speed)
	{
		case Settings::GamePlay::GameDifficulty::EASY:
		{
			m_speed = 0.35f;
		} break;

		case Settings::GamePlay::GameDifficulty::MEDIUM:
		{
			m_speed = 0.50f;
		} break;

		case Settings::GamePlay::GameDifficulty::HARD:
		{
			m_speed = 0.70f;
		} break;

	default:
		break;
	}

	m_ballTexture = Texture("Assets/Graphics/gameplay_scene/ball.png");

	setAngle(randomizeAng());
}

void Ball::resetBall(Settings::GamePlay::GameDifficulty speed)
{
	m_posX = (Settings::Display::WindowWidth / 2) - 40;
	m_posY = (Settings::Display::WindowHeight / 2) - 25;

	setAngle(randomizeAng());
	m_isDead = false;

	switch (speed)
	{
		case Settings::GamePlay::GameDifficulty::EASY:
		{
			m_speed = 0.35f;
		} break;

		case Settings::GamePlay::GameDifficulty::MEDIUM:
		{
			m_speed = 0.50f;
		} break;

		case Settings::GamePlay::GameDifficulty::HARD:
		{
			m_speed = 0.70f;
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

	SDL_RenderCopy(game->Renderer, m_ballTexture.getTexture(), nullptr, &m_ballRect);
}

void Ball::Update()
{
	m_posX += static_cast<int>(m_velocityX * game->avgDeltaTime);
	m_posY += static_cast<int>(m_velocityY * game->avgDeltaTime);
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
	static std::uniform_real_distribution<double> dis(-3.0f, 3.0f);

	double r = dis(gen);

	return r;
}