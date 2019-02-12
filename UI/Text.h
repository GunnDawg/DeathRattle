#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <cassert>
#include "Log/Log.h"

class Game;

class Text
{
public:
	Text()=default;
	Text(unsigned int fontSize, const std::string_view text);

	void Draw(unsigned int x, unsigned int y);
	void Draw(unsigned int x, unsigned int y, double rotation);
	void Update(const std::string_view newText);
	void Update(const SDL_Color& newColor);
	void Unload();

	SDL_Rect m_textRect                 = { 0 };

private:
	Game* game                          = nullptr;

	void loadFont();

	TTF_Font* m_Font                    = nullptr;

	std::string m_fontPath              = "Assets/Fonts/8BIT.ttf";
	std::string m_fontValue             = { };
	unsigned int m_fontSize             = 0;
	SDL_Color m_fontColor               = { 255, 255, 255, 255 };

	SDL_Texture* m_textTexture          = nullptr;
	SDL_Surface* m_textSurface          = nullptr;
};