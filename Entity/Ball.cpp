#include "Ball.h"
#include "Game.h"

Ball::Ball(unsigned int x, unsigned int y, unsigned int speed) :
m_posX((x / 2) - 40), m_posY((y/ 2) - 25), m_angle(0),
m_ballRect({0}),
m_ballWidth(50), m_ballHeight(50),
m_velocityX(0.0), m_velocityY(0.0),
m_speed(0), m_isDead(false)
{
	assert(typeid(x) == typeid(unsigned int) && x > 0 && "Ball must have an X value");
	assert(typeid(y) == typeid(unsigned int) && y > 0 && "Ball must have an Y value");

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

Ball::Ball(unsigned int w, unsigned int h, unsigned int x, unsigned int y) :
m_posX(x), m_posY(y), m_angle(0),
m_ballRect({ 0, 0, 0, 0 }),
m_ballWidth(w), m_ballHeight(h),
m_velocityX(0.0), m_velocityY(0.0),
m_speed(0), m_isDead(false)
{
	assert(w > 0);
	assert(h > 0);
	assert(x > 0);
	assert(y > 0);

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

	//printf("Speed: %i\n", m_speed);
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