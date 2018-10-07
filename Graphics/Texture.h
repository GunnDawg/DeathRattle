#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>

class Texture
{
public:
	Texture();
	~Texture();

	SDL_Texture* Load(SDL_Renderer* passedRenderer, const char* filePath);
	inline void Unload() { SDL_DestroyTexture(m_Texture); printf("Texture Destroyed: %s\n", m_filePath); }
	SDL_Texture* getTexture() { return m_Texture; }

	SDL_Rect m_TextureRect;
	SDL_Texture* m_Texture;

	const char* m_filePath;
};