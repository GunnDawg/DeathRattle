#include "Texture.h"

Texture::Texture()
{
	m_TextureRect.x = 100;
	m_TextureRect.y = 100;
}

Texture::~Texture()
{

}

SDL_Texture* Texture::Load(SDL_Renderer* passedRenderer, const char* filePath)
{
	m_Texture = IMG_LoadTexture(passedRenderer, filePath);
	if (m_Texture == nullptr)
	{
		printf("Error creating Texture. Error: %s\n", IMG_GetError());
	}

	SDL_QueryTexture(m_Texture, NULL, NULL, &m_TextureRect.w, &m_TextureRect.h);

	return m_Texture;
}