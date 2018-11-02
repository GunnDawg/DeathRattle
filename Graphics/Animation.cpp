#include "Animation.h"
#include "Game.h"

Animation::Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY) :
m_Texture(filePath),
m_numFramesX(numFramesX), m_numFramesY(numFramesY)
{
	m_Texture.Load();

	m_frameWidth = (m_Texture.m_TextureRect.w / m_numFramesX);
	m_frameHeight = (m_Texture.m_TextureRect.h / m_numFramesY);

	m_Texture.m_CropRect.w = 128;
	m_Texture.m_CropRect.h = 256;
	m_Texture.m_CropRect.x = 0;
	m_Texture.m_CropRect.y = 0;

	m_Texture.m_PosRect.x = 0;
	m_Texture.m_PosRect.y = 0;
	m_Texture.m_PosRect.w = 320;
	m_Texture.m_PosRect.h = 512;
}

void Animation::Load(unsigned int x, unsigned int y)
{
	m_Texture.m_PosRect.x = x;
	m_Texture.m_PosRect.y = y;
}

void Animation::Play(double dt)
{
	m_frameTime += dt;
	if (m_frameTime >= 16.00)
	{
		m_frameTime = 0;
		m_Texture.m_CropRect.x += m_frameWidth;
		if (m_Texture.m_CropRect.x >= m_Texture.m_TextureRect.w)
		{
			m_Texture.m_CropRect.x = 0;
			m_Texture.m_CropRect.y += m_frameHeight;
			if (m_Texture.m_CropRect.y >= m_Texture.m_TextureRect.h)
			{
				m_Texture.m_CropRect.y = 0;
			}
		}
	}
}

void Animation::Stop()
{
	m_Texture.Unload();
}

void Animation::Draw()
{
	SDL_RenderCopy(Game::Renderer, m_Texture.m_Texture, &m_Texture.m_CropRect, &m_Texture.m_PosRect);
}

void Animation::Update(unsigned int x, unsigned int y)
{
	m_Texture.m_PosRect.x = x;
	m_Texture.m_PosRect.y = y;
}