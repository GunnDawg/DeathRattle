#include "Animation.h"
#include "Game.h"

Animation::Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY, double speed) :
m_Texture(filePath),
m_numFramesX(numFramesX), m_numFramesY(numFramesY),
m_animSpeed(speed)
{
	game = &Game::GetInstance();

	m_Texture.Load();

	m_frameWidth = (m_Texture.m_TextureRect.w / m_numFramesX);
	m_frameHeight = (m_Texture.m_TextureRect.h / m_numFramesY);

	m_Texture.m_CropRect.w = m_frameWidth;
	m_Texture.m_CropRect.h = m_frameHeight;
}

void Animation::Load(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	m_Texture.m_PosRect.x = x;
	m_Texture.m_PosRect.y = y;
	m_Texture.m_PosRect.w = w;
	m_Texture.m_PosRect.h = h;
}

void Animation::Play(double dt)
{
	if (m_isPlaying)
	{
		m_frameTime += dt;
		if (m_frameTime >= m_animSpeed)
		{
			m_frameTime = 0;
			m_Texture.m_CropRect.x += m_frameWidth;
			if (m_Texture.m_CropRect.x >= m_Texture.m_TextureRect.w)
			{
				m_Texture.m_CropRect.x = 0;
				if (m_numFramesY > 1)
				{
					m_Texture.m_CropRect.y += m_frameHeight;
					if (m_Texture.m_CropRect.y >= m_Texture.m_TextureRect.h)
					{
						m_Texture.m_CropRect.y = 0;
					}
				}
			}
		}
	}
	else
	{
		m_frameTime = 0.0;
		m_Texture.m_CropRect.x = m_frameWidth;
	}
}

void Animation::Draw()
{
	SDL_RenderCopy(game->Renderer, m_Texture.m_Texture, &m_Texture.m_CropRect, &m_Texture.m_PosRect);
}