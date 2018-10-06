#include "Game.h"

SDL_Window* Game::m_Window = nullptr;
const char* Game::m_Title = "Keep it Alive!";
unsigned int Game::m_screenWidth = 1280;
unsigned int Game::m_screenHeight = 720;
SDL_Renderer* Game::m_Renderer = nullptr;
bool Game::m_isRunning = false;
GameStateMachine Game::m_gameStateMachine;
Uint64 Game::m_currentTime = 0;
Uint64 Game::m_lastTime = 0;
double Game::m_deltaTime = 0;

Game::Game(const char* title)
{
	
}

Game::~Game()
{
	exitGame();
}

void Game::updateDelta()
{
	m_lastTime = m_currentTime;
	m_currentTime = SDL_GetPerformanceCounter();
	m_deltaTime = static_cast<double>((m_currentTime - m_lastTime) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

	//printf("%f\n", m_deltaTime);
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

	std::unique_ptr<GameState> introSceneState = std::make_unique<IntroSceneState>();
	m_gameStateMachine.push(std::move(introSceneState));

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

	m_gameStateMachine.update();
}

void Game::Draw()
{
	beginRender();

	m_gameStateMachine.draw();

	endRender();
}

void Game::exitGame()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;

	SDL_Quit();
	IMG_Quit();
}