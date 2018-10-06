#include "Player.h"
#include "Game.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::on_enter()
{
	m_playerTexture.Load(Game::m_Renderer, "Assets/Graphics/knight.png");

	m_playerRect.x = 100;
	m_playerRect.y = 100;
	m_playerRect.w = m_playerTexture.m_TextureRect.w;
	m_playerRect.h = m_playerTexture.m_TextureRect.h;

	m_cropRect.x = 0;
	m_cropRect.y = 64;
	m_cropRect.w = m_playerRect.w / 9;
	m_cropRect.h = m_playerRect.h / 4;

	m_frameWidth = m_cropRect.w;
	m_frameHeight = m_cropRect.h;

	m_textureWidth = m_cropRect.w;

	m_frameCounter = 0.0f;
}

void Player::on_exit()
{
	
}

void Player::update()
{
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_D])
	{
		m_playerRect.x += static_cast<int>(m_moveSpeed * Game::m_deltaTime);
		m_cropRect.y = 196;
	}
	else if (keyState[SDL_SCANCODE_A])
	{
		m_playerRect.x -= static_cast<int>(m_moveSpeed * Game::m_deltaTime);
		m_cropRect.y = 64;
	}
	else if (keyState[SDL_SCANCODE_S])
	{
		m_playerRect.y += static_cast<int>(m_moveSpeed * Game::m_deltaTime);
		m_cropRect.y = 128;
	}
	else if (keyState[SDL_SCANCODE_W])
	{
		m_playerRect.y -= static_cast<int>(m_moveSpeed * Game::m_deltaTime);
		m_cropRect.y = 0;
	}

	//m_frameCounter += Game::m_deltaTime;
	//if (m_frameCounter >= 0.05f)
	//{
	//	m_frameCounter = 0;
	//	m_cropRect.x += m_frameWidth;
	//	if (m_cropRect.x >= m_textureWidth)
	//	{
	//		m_cropRect.x = 0;
	//	}
	//}
}

void Player::draw()
{
	SDL_RenderCopy(Game::m_Renderer, m_playerTexture.m_Texture, &m_cropRect, &m_playerRect);
}