#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Log/Log.h"

class Game;

class Texture
{
public:
	Texture()=default;
	Texture(const std::string_view filePath);

	void Load();
	void Unload();
	void setRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void setRect(unsigned int x, unsigned int y);

	SDL_Texture* m_Texture               = nullptr;
	std::string m_filePath               = { 0 };
	SDL_Rect m_TextureRect               = { 0 };

private:
	Game* game                           = nullptr;
};