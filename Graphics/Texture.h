#pragma once
extern "C"
{
	#include <SDL.h>
	#include <SDL_image.h>
}

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

	SDL_Texture* mTexture               = nullptr;
	std::string mFilePath               = { 0 };
	SDL_Rect mTextureRect               = { 0 };

private:
	Game* game                          = nullptr;
};