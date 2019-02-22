#include "Text.h"
#include "Game.h"

Text::Text(unsigned int fontSize, const std::string_view text) :
mFontValue(text.data()), mFontSize(fontSize)
{
	assert(typeid(fontSize) == typeid(unsigned int) && fontSize > 0 && "Text must have a font size");
	assert(typeid(text) == typeid(std::string_view) && !text.empty() && "Text cannot have an empty value");

	game = &Game::GetInstance();

	loadFont();
	SDL_QueryTexture(mTextTexture, nullptr, nullptr, &mTextRect.w, &mTextRect.h);

	GUNN_CORE_INFO("TEXT LOADED: {0}", mFontValue.c_str());
}

void Text::loadFont()
{
	mFont = TTF_OpenFont(mFontPath.data(), mFontSize);
	if (!mFont)
	{
		GUNN_CORE_ERROR("Error loading font: {0}. Error: {1}", mFontPath, TTF_GetError());
	}

	mTextSurface = TTF_RenderText_Solid(mFont, mFontValue.data(), mFontColor);
	if (!mTextSurface)
	{
		GUNN_CORE_ERROR("Error creating text surface: {0}. Error: {1}", mFontPath.data(), TTF_GetError());
	}

	mTextTexture = SDL_CreateTextureFromSurface(game->Renderer, mTextSurface);
	if (!mTextTexture)
	{
		GUNN_CORE_ERROR("Error creating text texture: {0}", SDL_GetError());
	}

	SDL_FreeSurface(mTextSurface);
	mTextSurface = nullptr;

	TTF_CloseFont(mFont);
	mFont = nullptr;
}

void Text::Draw(unsigned int x, unsigned int y)
{
	mTextRect.x = x;
	mTextRect.y = y;

	SDL_RenderCopy(game->Renderer, mTextTexture, nullptr, &mTextRect);
}

void Text::Draw(unsigned int x, unsigned int y, double rotation)
{
	mTextRect.x = x;
	mTextRect.y = y;

	SDL_RenderCopyEx(game->Renderer, mTextTexture, nullptr, &mTextRect, rotation, nullptr, SDL_FLIP_NONE);
}

void Text::Update(const std::string_view newText)
{
	SDL_DestroyTexture(mTextTexture);
	mTextTexture = nullptr;

	mFontValue = newText.data();
	loadFont();
	SDL_QueryTexture(mTextTexture, nullptr, nullptr, &mTextRect.w, &mTextRect.h);
}

void Text::Update(const SDL_Color& newColor)
{
	SDL_DestroyTexture(mTextTexture);
	mTextTexture = nullptr;

	mFontColor = newColor;
	loadFont();
	SDL_QueryTexture(mTextTexture, nullptr, nullptr, &mTextRect.w, &mTextRect.h);
}

void Text::Unload()
{
	SDL_DestroyTexture(mTextTexture);
	mTextTexture = nullptr;

	SDL_FreeSurface(mTextSurface);
	mTextSurface = nullptr;

	TTF_CloseFont(mFont);
	mFont = nullptr;

	GUNN_CORE_INFO("TEXT UNLOADED: {0}", mFontValue.c_str());
}