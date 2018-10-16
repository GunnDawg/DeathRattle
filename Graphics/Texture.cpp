#include "Texture.h"
#include "Game.h"

Texture::Texture()
{
	m_TextureRect.x = 100;
	m_TextureRect.y = 100;
}

Texture::~Texture()
{
	
}

SDL_Texture* Texture::Load(std::string filePath)
{
	m_filePath = filePath.c_str();

	m_Texture = IMG_LoadTexture(Game::Renderer, m_filePath.c_str());
	if (m_Texture == nullptr)
	{
		printf("Error creating Texture. Error: %s\n", IMG_GetError());
	}

	SDL_QueryTexture(m_Texture, NULL, NULL, &m_TextureRect.w, &m_TextureRect.h);

	return m_Texture;
}

void Texture::Unload()
{
	//if (m_Texture == nullptr)
	//{
	//	SDL_DestroyTexture(m_Texture);
	//	printf("Texture Destroyed: %s\n", m_filePath.c_str());
	//}

	SDL_DestroyTexture(m_Texture);
	printf("Texture Destroyed: %s\n", m_filePath.c_str());
}

void Texture::setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	m_TextureRect.x = x;
	m_TextureRect.y = y;
	m_TextureRect.w = w;
	m_TextureRect.h = h;
}