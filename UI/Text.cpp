#include "Text.h"
#include "Game.h"

Text::Text(unsigned int fontSize, const std::string_view text) :
m_fontValue(text.data()), m_fontSize(fontSize)
{
	assert(typeid(fontSize) == typeid(unsigned int) && fontSize > 0 && "Text must have a font size");
	assert(typeid(text) == typeid(std::string_view) && !text.empty() && "Text cannot have an empty value");

	game = &Game::GetInstance();

	loadFont();
	SDL_QueryTexture(m_textTexture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);

	GUNN_CORE_INFO("TEXT LOADED: {0}", m_fontValue.c_str());
}

void Text::loadFont()
{
	m_Font = TTF_OpenFont(m_fontPath.data(), m_fontSize);
	if (!m_Font)
	{
		GUNN_CORE_ERROR("Error loading font: {0}. Error: {1}", m_fontPath, TTF_GetError());
	}

	m_textSurface = TTF_RenderText_Solid(m_Font, m_fontValue.data(), m_fontColor);
	if (!m_textSurface)
	{
		GUNN_CORE_ERROR("Error creating text surface: {0}. Error: {1}", m_fontPath.data(), TTF_GetError());
	}

	m_textTexture = SDL_CreateTextureFromSurface(game->Renderer, m_textSurface);
	if (!m_textTexture)
	{
		GUNN_CORE_ERROR("Error creating text texture: {0}", SDL_GetError());
	}

	SDL_FreeSurface(m_textSurface);
	m_textSurface = nullptr;

	TTF_CloseFont(m_Font);
	m_Font = nullptr;
}

void Text::Draw(unsigned int x, unsigned int y)
{
	m_textRect.x = x;
	m_textRect.y = y;

	SDL_RenderCopy(game->Renderer, m_textTexture, nullptr, &m_textRect);
}

void Text::Draw(unsigned int x, unsigned int y, double rotation)
{
	m_textRect.x = x;
	m_textRect.y = y;

	SDL_RenderCopyEx(game->Renderer, m_textTexture, nullptr, &m_textRect, rotation, nullptr, SDL_FLIP_NONE);
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

	SDL_FreeSurface(m_textSurface);
	m_textSurface = nullptr;

	TTF_CloseFont(m_Font);
	m_Font = nullptr;

	GUNN_CORE_INFO("TEXT UNLOADED: {0}", m_fontValue.c_str());
}