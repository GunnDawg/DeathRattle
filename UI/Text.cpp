#include "Text.h"
#include "Game.h"

Text::Text(unsigned int fontSize, const std::string_view text) :
m_fontValue(text.data()), m_fontSize(fontSize)
{
	assert(typeid(fontSize) == typeid(unsigned int) && fontSize > 0 && "Text must have a font size");
	assert(typeid(text) == typeid(std::string_view) && !text.empty() && "Text cannot have an empty value");

	loadFont();
	SDL_QueryTexture(m_textTexture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);

	printf("TEXT LOADED: \t\t---> \t%s\n", m_fontValue.c_str());
}

void Text::loadFont()
{
	TTF_Font* font = TTF_OpenFont(m_fontPath.data(), m_fontSize);
	if (!font)
	{
		printf("Error loading font. Error: %s\n", TTF_GetError());
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, m_fontValue.data(), m_fontColor);
	if (!textSurface)
	{
		printf("Error creating text surface: %s/nFile: %s", SDL_GetError(), m_fontPath.data());
	}

	m_textTexture = SDL_CreateTextureFromSurface(Game::Renderer, textSurface);
	if (!m_textTexture)
	{
		printf("Error creating text texture: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(textSurface);

	TTF_CloseFont(font);
}

void Text::Draw(unsigned int x, unsigned int y)
{
	m_textRect.x = x;
	m_textRect.y = y;

	SDL_RenderCopy(Game::Renderer, m_textTexture, nullptr, &m_textRect);
}

void Text::Update(const std::string_view newText)
{
	SDL_DestroyTexture(m_textTexture);
	m_textTexture = nullptr;

	m_fontValue = newText.data();
	loadFont();
	SDL_QueryTexture(m_textTexture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);
}

void Text::Update(const SDL_Color& newColor)
{
	SDL_DestroyTexture(m_textTexture);
	m_textTexture = nullptr;

	m_fontColor = newColor;
	loadFont();
	SDL_QueryTexture(m_textTexture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);
}

void Text::Unload()
{
	SDL_DestroyTexture(m_textTexture);
	m_textTexture = nullptr;

	printf("TEXT UNLOADED: \t\t---> \t%s\n", m_fontValue.c_str());
}