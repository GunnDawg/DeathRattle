#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	SDL_Texture* Load(std::string filePath);
	void Unload();
	SDL_Texture* getTexture() { return m_Texture; }
	void setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h);

	SDL_Rect m_TextureRect;
	SDL_Texture* m_Texture;

	std::string m_filePath;
};