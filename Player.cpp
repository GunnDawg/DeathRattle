#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::on_enter(SDL_Renderer* passedRenderer)
{
	m_playerTexture.Load(passedRenderer, "Assets/Graphics/knight.png");

	m_playerRect.x = 100;
	m_playerRect.y = 100;
	m_playerRect.w = m_playerTexture.m_TextureRect.w;
	m_playerRect.h = m_playerTexture.m_TextureRect.h;

	m_cropRect.x = 0;
	m_cropRect.y = 64;
	m_cropRect.w = m_playerRect.w / 9;
	m_cropRect.h = m_playerRect.h / 4;
}

void Player::on_exit()
{
	
}

void Player::update(double dt)
{
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_D])
	{
		m_playerRect.x += static_cast<int>(m_moveSpeed * dt);
		m_cropRect.y = 196;
	}
	else if (keyState[SDL_SCANCODE_A])
	{
		m_playerRect.x -= static_cast<int>(m_moveSpeed * dt);
		m_cropRect.y = 64;
	}
	else if (keyState[SDL_SCANCODE_S])
	{
		m_playerRect.y += static_cast<int>(m_moveSpeed * dt);
		m_cropRect.y = 128;
	}
	else if (keyState[SDL_SCANCODE_W])
	{
		m_playerRect.y -= static_cast<int>(m_moveSpeed * dt);
		m_cropRect.y = 0;
	}
}

void Player::draw(SDL_Renderer* passedRenderer)
{
	SDL_RenderCopy(passedRenderer, m_playerTexture.m_Texture, &m_cropRect, &m_playerRect);
}