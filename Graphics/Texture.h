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

	void Load();
	void Unload();
	void setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void setRect(unsigned int x, unsigned int y);
	SDL_Rect getRect() const { return m_TextureRect; }
	SDL_Texture* getTexture() const { return m_Texture; }

	std::string m_filePath;
	SDL_Texture* m_Texture            = nullptr;
	SDL_Rect m_TextureRect            = { 0 };
};