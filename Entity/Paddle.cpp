#include "Paddle.h"

Paddle::Paddle(int x, int y, int w, int h) :
m_paddleRect({ w, h, x, y })
{
	assert(typeid(w) == typeid(int) && w > 0 && "Paddle width must be greater than 0");
	assert(typeid(h) == typeid(int) && h > 0 && "Paddle height must be greater than 0");
	assert(typeid(x) == typeid(int) && x > 0 && "Paddle must have an X value");
	assert(typeid(y) == typeid(int) && y > 0 && "Paddle must have an Y value");

	//m_paddleTexture = Texture("Assets/Graphics/gameplay_scene/paddle_blood.png");
	//m_paddleTexture.Load();

	//m_paddleTexture2 = Texture("Assets/Graphics/gameplay_scene/paddle_blood2.png");
	//m_paddleTexture2.Load();
}

Paddle::~Paddle()
{
	//m_paddleTexture.Unload();
	//m_paddleTexture2.Unload();
}

void Paddle::Draw()
{
	//Render a memey shadow on paddles
	SDL_Rect border;
	border.w = m_paddleRect.w + 3;
	border.h = m_paddleRect.h + 3;
	border.x = m_paddleRect.x;
	border.y = m_paddleRect.y;

	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(Game::Renderer, &border);

	if (m_paddleMarked)
	{
		//SDL_SetRenderDrawColor(passedRender, 136, 4, 7, 255);
		SDL_SetRenderDrawColor(Game::Renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(Game::Renderer, &m_paddleRect);
	}
	else
	{
		SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(Game::Renderer, &m_paddleRect);
	}

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);

	//Render a memey shadow on paddles
	//SDL_Rect border; 
	//border.w = m_paddleRect.w + 3;
	//border.h = m_paddleRect.h + 3;
	//border.x = m_paddleRect.x;
	//border.y = m_paddleRect.y;

	//SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	//SDL_RenderFillRect(Game::Renderer, &m_paddleRect);

	//if (m_paddleMarked)
	//{
	//	if (m_paddleRect.h == 15)
	//	{
	//		SDL_RenderCopy(Game::Renderer, m_paddleTexture2.m_Texture, NULL, &m_paddleRect);
	//	}
	//	else
	//	{
	//		SDL_RenderCopy(Game::Renderer, m_paddleTexture.m_Texture, NULL, &m_paddleRect);
	//	}
	//}
}

void Paddle::resetPaddles(int x, int y, int w, int h)
{
	m_paddleRect = { x, y, w, h };
	m_paddleMarked = false;
}

void Paddle::Heal()
{
	if (m_paddleRect.h > 15)
	{
		m_paddleRect.h += (m_paddleRect.h / 20);
	}
	else
	{
		m_paddleRect.w += (m_paddleRect.w / 20);
	}

	m_paddleMarked = false;
}

void Paddle::setHit(bool hit)
{
	m_paddleMarked = hit;
}