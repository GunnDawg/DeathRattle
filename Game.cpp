#include "Game.h"

Game::Game(const char* title, unsigned int w, unsigned int h) :
m_Title(title), m_screenWidth(w), m_screenHeight(h), m_isRunning(true)
{

}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Error starting SDL. Error: %s\n", SDL_GetError());
		return(0);
	}

	m_Window = SDL_CreateWindow(
		m_Title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		m_screenWidth,
		m_screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (m_Window == nullptr)
	{
		printf("Error creating SDL_Window. Error: %s\n", SDL_GetError());
		return(0);
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr)
	{
		printf("Error creating SDL_Renderer. Error: %s\n", SDL_GetError());
		return(0);
	}

	return(1);
}

void Game::processinput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
		{

		} break;

		case SDL_KEYDOWN:
		{
			switch (evnt.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				{

				} break;

				case SDLK_m:
				{

				} break;

				default:
					break;
			}

		} break;

		default:
			break;
		}
	}
}

void Game::Update()
{

}

void Game::Draw()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);

	SDL_RenderPresent(m_Renderer);
}

void Game::Unload()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;

	SDL_Quit();
}