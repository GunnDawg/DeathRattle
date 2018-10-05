#include "Player.h"

Player::Player(SDL_Renderer* passedRenderer)
{
	assert(passedRenderer != nullptr);

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

Player::~Player()
{

}

void Player::on_enter()
{
	
}

void Player::on_exit()
{
	
}

void Player::update(double dt)
{
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_D])
	{
		m_playerRect.x += (int)(m_moveSpeed * dt);
		m_cropRect.y = 196;
	}
	else if (keyState[SDL_SCANCODE_A])
	{
		m_playerRect.x -= (int)(m_moveSpeed * dt);
		m_cropRect.y = 64;
	}
}

void Player::draw(SDL_Renderer* passedRenderer)
{
	SDL_RenderCopy(passedRenderer, m_playerTexture.m_Texture, &m_cropRect, &m_playerRect);
}