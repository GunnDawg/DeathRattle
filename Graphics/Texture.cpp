#include "Texture.h"
#include "Game.h"

Texture::Texture(const std::string_view filePath) :
m_filePath(filePath),
m_Texture(nullptr),
m_TextureRect({ 0 })
{
	assert(typeid(filePath) == typeid(std::string_view) && !filePath.empty() && "Texture filepath cannot be empty");
}


Texture::~Texture()
{
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		printf("TEXTURE DESTROYED: \t---> \t%s\n", m_filePath.c_str());
	}
}

void Texture::Load()
{
	m_Texture = IMG_LoadTexture(Game::Renderer, m_filePath.c_str());
	if (m_Texture == nullptr)
	{
		printf("TEXTURE: \t---> Error loading texture file. Error: \t%s\n", IMG_GetError());
	}
	else
	{
		if (SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_TextureRect.w, &m_TextureRect.h) == -1)
		{
			printf("TEXTURE: \t---> \t%s is invalid\n", SDL_GetError());
		}
		else
		{
			printf("TEXTURE LOADED: \t---> \t%s\n", m_filePath.c_str());
		}
	}
}

void Texture::Unload()
{
	SDL_DestroyTexture(m_Texture);
	m_Texture = nullptr;
	printf("TEXTURE UNLOADED: \t---> \t%s\n", m_filePath.c_str());

}

void Texture::setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	m_TextureRect.x = x;
	m_TextureRect.y = y;
	m_TextureRect.w = w;
	m_TextureRect.h = h;
}