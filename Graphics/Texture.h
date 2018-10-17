#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>

class Texture
{
public:
	Texture()=default;
	Texture(const std::string_view filePath);
	~Texture();

	SDL_Texture* Load();
	void Unload();
	SDL_Texture* getTexture() { return m_Texture; }
	void setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h);

	std::string m_filePath;
	SDL_Texture* m_Texture;
	SDL_Rect m_TextureRect;
};