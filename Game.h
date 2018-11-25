#pragma once
#include <SDL.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdio>
#include <array>
#include <memory>
#include <chrono>

#include "StateMachine/GameStateMachine.h"
#include "Scenes/LoadingScene.h"
#include "Scenes/SplashScene.h"

class Game
{
public:
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;

	void updateDelta();
	bool Init();
	void processinput();
	void Update();
	void Draw();

	inline static GameStateMachine gameStateMachine      = GameStateMachine();
	SDL_Window* Window                                   = nullptr;
	inline static SDL_Renderer* Renderer                 = nullptr;
	const char* Title                                    = "Death Rattle";
	inline static unsigned int screenWidth               = 1280;
	inline static unsigned int screenHeight              = 720;
	inline static bool isRunning                         = false;
	unsigned int index = 0;
	unsigned int amount = 0;
	inline static std::array<double, 1000> times = { 16.666 };
	//Uint64 currentTime                                   = 0ULL;
	//Uint64 lastTime                                      = 0ULL;
	//inline static double deltaTime                       = 0.0;

	inline static float deltaTime = 0.0f;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point end;

	inline static int mouseX                             = 0;
	inline static int mouseY                             = 0;

private:
	Game()=default;
	~Game();
};