#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <cassert>
#include <cstdio>
#include <array>

class Text
{
public:
	Text() = default;
	Text(unsigned int fontSize, const std::string_view text);
	~Text();

	void Draw();
	void Draw(unsigned int x, unsigned int y);
	void Update(const std::string_view newText);
	void Update();
	void Unload();

	SDL_Rect m_textRect            = { 0 };

private:
	//Text(const Text& obj)=delete;
	//Text& operator=(const Text&)=delete;

	void loadFont(const std::string_view fontPath, unsigned int fontSize, const std::string_view text, const SDL_Color color);

	std::string m_fontPath         = "Assets/Fonts/8BIT.ttf";
	std::string m_fontValue;
	unsigned int m_fontSize        = 0;
	SDL_Color m_fontColor          = { 255, 255, 255, 255 };

	SDL_Texture* m_textTexture     = nullptr;
};