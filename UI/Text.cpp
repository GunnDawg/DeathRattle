#include "Text.h"
#include "Game.h"

Text::Text(unsigned int fontSize, const std::string_view text) :
	m_textRect({}), m_fontPath("Assets/Fonts/8BIT.ttf"),
	m_fontValue(text),
	m_fontSize(fontSize),
	m_fontColor({ 255, 255, 255, 255 }),
	m_textTexture(loadFont(m_fontPath, m_fontSize, m_fontValue, m_fontColor))
{
	assert(typeid(fontSize) == typeid(unsigned int) && fontSize > 0 && "Text must have a font size");
	assert(typeid(text) == typeid(std::string_view) && !text.empty() && "Text cannot have an empty value");

	SDL_QueryTexture(m_textTexture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);

	printf("TEXT LOADED: \t\t---> \t%s\n", m_fontValue.c_str());
}

Text::~Text()
{
	SDL_DestroyTexture(m_textTexture);
	m_textTexture = nullptr;
}

SDL_Texture* Text::loadFont(const std::string_view fontPath, unsigned int fontSize, const std::string_view text, const SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont(fontPath.data(), fontSize);
	if (!font)
	{
		printf("Error loading font. Error: %s\n", TTF_GetError());
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.data(), color);
	if (!textSurface)
	{
		printf("Error creating text surface: %s/nFile: %s", SDL_GetError(), fontPath.data());
	}

	m_textTexture = SDL_CreateTextureFromSurface(Game::Renderer, textSurface);
	if (!m_textTexture)
	{
		printf("Error creating text texture: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(textSurface);

	TTF_CloseFont(font);

	return(m_textTexture);
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

	m_fontValue = newText;
	m_textTexture = loadFont(m_fontPath, m_fontSize, m_fontValue, { 255, 255, 255, 255 });
	SDL_QueryTexture(m_textTexture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);
}

void Text::Unload()
{
	SDL_DestroyTexture(m_textTexture);
	printf("TEXT UNLOADED: \t\t---> \t%s\n", m_fontValue.c_str());
}