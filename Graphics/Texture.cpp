#include "Texture.h"
#include "Game.h"

Texture::Texture(const std::string_view filePath) :
m_filePath(filePath.data())
{
	game = &Game::GetInstance();
}

void Texture::Load()
{
	m_Texture = IMG_LoadTexture(game->Renderer, m_filePath.c_str());
	if (m_Texture == nullptr)
	{
		GUNN_CORE_ERROR("TEXTURE: Error loading texture file: {0}. Error: {1}", m_filePath, IMG_GetError());
	}
	else
	{
		if (SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_TextureRect.w, &m_TextureRect.h) == -1)
		{
			GUNN_CORE_ERROR("TEXTURE: {0} is invalid. Error: {1}", m_filePath, IMG_GetError());
		}
		else
		{
			GUNN_CORE_INFO("TEXTURE LOADED: {0}", m_filePath);
		}
	}
}

void Texture::Unload()
{
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
		GUNN_CORE_INFO("TEXTURE UNLOADED: {0}", m_filePath);
	}
}

void Texture::setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	m_TextureRect.x = x;
	m_TextureRect.y = y;
	m_TextureRect.w = w;
	m_TextureRect.h = h;
}

void Texture::setRect(unsigned int x, unsigned int y)
{
	m_TextureRect.x = x;
	m_TextureRect.y = y;
}