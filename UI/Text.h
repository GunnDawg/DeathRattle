#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <cassert>
#include <cstdio>

class Text
{
public:
	Text()=default;
	Text(unsigned int fontSize, const std::string_view text);
	~Text();

	void Draw(unsigned int x, unsigned int y);
	void Update(const std::string_view newText);

	SDL_Rect m_textRect;

private:
	//Text(const Text& obj)=delete;
	//Text& operator=(const Text&)=delete;

	SDL_Texture* loadFont(const std::string_view fontPath, unsigned int fontSize, const std::string_view text, const SDL_Color color);

	std::string m_fontPath;
	std::string m_fontValue;
	unsigned int m_fontSize;
	SDL_Color m_fontColor;

	SDL_Texture* m_textTexture;
};