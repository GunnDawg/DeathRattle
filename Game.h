#pragma once
extern "C"
{
	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_mixer.h>
	#include <SDL_ttf.h>
}

#include <array>
#include <memory>
#include "Log/Log.h"
#include "GameSettings.h"
#include "StateMachine/GameStateMachine.h"
#include "Scenes/SplashScene.h"

class Game
{
public:

	static Game& GetInstance()
	{
		static Game* instance = nullptr;

		if (instance == nullptr)
		{
			instance = new Game();
		}

		return *instance;
	}

	static void DestroyGame()
	{
		static Game* instance = &GetInstance();

		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;

	void updateDelta();
	bool Init();
	void ProcessInput();
	void Update();
	void Draw();

	inline static GameStateMachine gameStateMachine             = GameStateMachine();
	SDL_Window* Window                                          = nullptr;
	SDL_Renderer* Renderer                                      = nullptr;
	const char* Title                                           = "Death Rattle";
	unsigned int screenWidth                                    = Settings::Display::WindowWidth;
	unsigned int screenHeight                                   = Settings::Display::WindowHeight;
	bool isRunning                                              = false;

	Uint64 currentTime                                          = 0ULL;
	Uint64 lastTime                                             = 0ULL;
	Uint64 totalUpdates                                         = 0ULL;
	double deltaTime                                            = 0.0;
	double totalDeltaTime                                       = 0.0;
	double avgDeltaTime                                         = 0.0;

	int mouseX                                                  = 0;
	int mouseY                                                  = 0;

private:
	Game()=default;
	~Game();
};