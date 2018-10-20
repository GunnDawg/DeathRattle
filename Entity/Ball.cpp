#include "Ball.h"

Ball::Ball(unsigned int speed) :
m_speed(speed)
{
	assert(typeid(speed) == typeid(unsigned int) && speed > 0 && "Ball must have a speed/difficulty value");

	switch (speed)
	{
		case 0:
		{
			m_speed = 0.35f;
		} break;

		case 1:
		{
			m_speed = 0.50f;
		} break;

		case 2:
		{
			m_speed = 0.70f;
		} break;

	default:
		break;
	}

	m_ballTexture = Texture("Assets/Graphics/gameplay_scene/ball.png");

	setAngle(randomizeAng());
}

void Ball::resetBall(unsigned int w, unsigned int h, unsigned int difficulty)
{
	m_posX = (w / 2) - 40;
	m_posY = (h / 2) - 25;

	setAngle(randomizeAng());
	m_isDead = false;

	switch (difficulty)
	{
		case 0:
		{
			m_speed = 0.35f;
		} break;

		case 1:
		{
			m_speed = 0.50f;
		} break;

		case 2:
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
	else if (!m_isDead)
	{
		SDL_SetTextureColorMod(m_ballTexture.getTexture(), 255, 255, 255);
	}

	SDL_RenderCopy(Game::Renderer, m_ballTexture.getTexture(), nullptr, &m_ballRect);
}

void Ball::Update()
{
	m_posX += static_cast<int>(m_velocityX * Game::deltaTime);
	m_posY += static_cast<int>(m_velocityY * Game::deltaTime);
}

void Ball::setAngle(double angle)
{
	m_angle = angle;

	m_velocityX = ((cos(m_angle)) * m_speed);
	m_velocityY = ((sin(m_angle)) * m_speed);
}

double Ball::randomizeAng()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(-3.0f, 3.0f);

	double r = dis(gen);

	return(r);
}