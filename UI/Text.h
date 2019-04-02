#pragma once
extern "C"
{
	#include <SDL.h>
	#include <SDL_ttf.h>
}

#include <string>
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

	SDL_Rect mTextRect                 = { 0 };

private:
	Game* game                          = nullptr;

	void loadFont();

	TTF_Font* mFont                    = nullptr;

	std::string mFontPath              = "Assets/Fonts/8BIT.ttf";
	std::string mFontValue             = { };
	unsigned int mFontSize             = 0;
	SDL_Color mFontColor               = { 255, 255, 255, 255 };

	SDL_Texture* mTextTexture          = nullptr;
	SDL_Surface* mTextSurface          = nullptr;
};