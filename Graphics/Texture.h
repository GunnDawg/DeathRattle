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
	SDL_Texture* getTexture() { return m_Texture; }

	SDL_Rect m_TextureRect;
	SDL_Rect m_CropRect;
	SDL_Texture* m_Texture;
};