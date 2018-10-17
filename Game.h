#pragma once
#include <SDL.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdio>
#include <memory>

#include "StateMachine/GameStateMachine.h"
#include "Audio/MusicManager.h"
#include "Scenes/SplashScene.h"

class Game
{
public:
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

	static void updateDelta();
	static bool Init();
	static void processinput();
	static void Update();
	static void Draw();

	inline static GameStateMachine gameStateMachine;
	inline static SDL_Window* Window                     = nullptr;
	inline static const char* Title                      = "Keep it Alive!!";
	inline static SDL_Renderer* Renderer                 = nullptr;
	inline static bool isRunning                         = false;
	inline static Uint64 currentTime                     = 0ULL;
	inline static Uint64 lastTime                        = 0ULL;
	inline static double deltaTime                       = 0.0;
	inline static unsigned int screenWidth               = 1280;
	inline static unsigned int screenHeight              = 720;

	inline static int mouseX                             = 0;
	inline static int mouseY                             = 0;

private:
	Game() = default;
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
};