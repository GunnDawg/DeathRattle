#include "Game.h"

Game::~Game()
{
	if (!gameStateMachine.m_gameStates.empty())
	{
		gameStateMachine.unloadAll();
	}

	if (Renderer != nullptr)
	{
		SDL_DestroyRenderer(Renderer);
		Renderer = nullptr;
	}

	if (Window != nullptr)
	{
		SDL_DestroyWindow(Window);
		Window = nullptr;
	}

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	GUNN_CORE_INFO("GAME INSTANCE DESTROYED!!");
}

void Game::updateDelta()
{
	lastTime = currentTime;
	currentTime = SDL_GetPerformanceCounter();
	deltaTime = static_cast<double>((currentTime - lastTime) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

	if (deltaTime < 100)
	{
		totalDeltaTime += deltaTime;
	}

	totalUpdates += 1;
	avgDeltaTime = totalDeltaTime / totalUpdates;
}

bool Game::Init()
{
	Gunn::Log::Init();

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0)
	{
		GUNN_CORE_FATAL("Error starting SDL. Error: {0}", SDL_GetError());
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		GUNN_CORE_FATAL("IMG_Init: Failed to init required PNG support!");
		GUNN_CORE_FATAL("IMG_Init: {0}", IMG_GetError());
		return false;
	}

	if (TTF_Init() != 0)
	{
		GUNN_CORE_FATAL("Error starting SDL_TTF. Error: {0}", TTF_GetError());
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
	{
		GUNN_CORE_FATAL("Error starting SDL_Mixer. Error: {0}", Mix_GetError());
		return false;
	}

	Uint32 WindowFlags = 0;

	switch (Settings::Display::WindowMode)
	{
		case 0:
		{
			WindowFlags = SDL_WINDOW_SHOWN;
		} break;

		case 1:
		{
			WindowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
		} break;

	default:
		break;
	}

	Window = SDL_CreateWindow
	(
		"Death Rattle",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		Settings::Display::WindowWidth,
		Settings::Display::WindowHeight,
		WindowFlags
	);
	if (Window == nullptr)
	{
		GUNN_CORE_FATAL("Error creating SDL_Window. Error: {0}", SDL_GetError());
		return false;
	}


	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Renderer == nullptr)
	{
		GUNN_CORE_FATAL("Error creating SDL_Renderer. Error: {0}", SDL_GetError());
		return false;
	}

	//std::unique_ptr<GameState> loadingSceneState = std::make_unique<LoadingScene>();
	//gameStateMachine.push(std::move(loadingSceneState));

	std::unique_ptr<GameState> splashSceneState = std::make_unique<SplashScene>();
	gameStateMachine.push(std::move(splashSceneState));

	SDL_ShowCursor(0);
	isRunning = true;

	return true;
}

void Game::ProcessInput()
{
	gameStateMachine.handleEvents();
}

void Game::Update()
{
	updateDelta();
	SDL_GetMouseState(&mouseX, &mouseY);
	gameStateMachine.update();
}

void Game::Draw()
{
	gameStateMachine.draw();
	SDL_RenderPresent(Renderer);
}