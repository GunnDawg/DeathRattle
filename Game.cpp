#include "Game.h"

Game::Game(const char* title, unsigned int w, unsigned int h) :
m_Title(title), m_screenWidth(w), m_screenHeight(h), m_isRunning(false)
{
	
}

void Game::updateDelta()
{
	m_lastTime = m_currentTime;
	m_currentTime = SDL_GetPerformanceCounter();
	m_deltaTime = static_cast<double>((m_currentTime - m_lastTime) * 10 / static_cast<double>(SDL_GetPerformanceFrequency()));
}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Error starting SDL. Error: %s\n", SDL_GetError());
		return(0);
	}

	if ((IMG_Init(IMG_INIT_PNG != IMG_INIT_PNG)))
	{
		printf("IMG_Init: Failed to init required PNG support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
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

	m_isRunning = true;

	return(1);
}

void Game::processinput()
{
	m_gameStateMachine.handleEvents();
}

void Game::Update()
{
	updateDelta();

	m_gameStateMachine.update(m_deltaTime);
}

void Game::Draw()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);

	m_gameStateMachine.draw(m_Renderer);

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