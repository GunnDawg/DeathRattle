#include "Game.h"

SDL_Window* Game::Window = nullptr;
SDL_Renderer* Game::Renderer = nullptr;
const char* Game::Title = "Keep it Alive! - A Pong-Like Game";
unsigned int Game::screenWidth = 1280;
unsigned int Game::screenHeight = 720;
bool Game::isRunning = false;
GameStateMachine Game::gameStateMachine;
Uint64 Game::currentTime = 0ULL;
Uint64 Game::lastTime = 0ULL;
double Game::deltaTime = 0.0;
int Game::mouseX = 0;
int Game::mouseY = 0;

Game::~Game()
{
	gameStateMachine.unloadAll();

	SDL_DestroyRenderer(Renderer);
	Renderer = nullptr;

	SDL_DestroyWindow(Window);
	Window = nullptr;

	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
}

void Game::updateDelta()
{
	lastTime = currentTime;
	currentTime = SDL_GetPerformanceCounter();
	deltaTime = static_cast<double>((currentTime - lastTime) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));
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

	if (TTF_Init() != 0)
	{
		printf("Error starting SDL_TTF. Error: %s\n", TTF_GetError());
		return(false);
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
	{
		printf("Error starting SDL_Mixer. Error: %s\n", Mix_GetError());
		return(false);
	}

	Window = SDL_CreateWindow
	(
		Title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		screenWidth,
		screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (Window == nullptr)
	{
		printf("Error creating SDL_Window. Error: %s\n", SDL_GetError());
		return(0);
	}

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Renderer == nullptr)
	{
		printf("Error creating SDL_Renderer. Error: %s\n", SDL_GetError());
		return(0);
	}

	std::unique_ptr<GameState> splashSceneState = std::make_unique<SplashScene>();
	gameStateMachine.push(std::move(splashSceneState));

	SDL_ShowCursor(0);

	isRunning = true;

	return(1);
}

void Game::processinput()
{
	gameStateMachine.handleEvents();
}

void Game::Update()
{
	updateDelta();
	MusicManager::Update();

	gameStateMachine.update();

	SDL_GetMouseState(&mouseX, &mouseY);
}

void Game::Draw()
{
	SDL_RenderClear(Renderer);

	gameStateMachine.draw();

	SDL_RenderPresent(Renderer);
}