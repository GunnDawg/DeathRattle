#pragma once
#include <SDL.h>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <memory>

#include "StateMachine/GameStateMachine.h"
#include "Scenes/IntroScene.h"
#include "Player.h"

class Game
{
public:
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

	Game(Game const&) = delete;
	void operator=(Game const&) = delete;
	~Game();

	static bool Init();
	static void processinput();
	static void Update();
	static void Draw();
	static void updateDelta();

	static inline bool Running() { return isRunning; }

	static SDL_Window* Window;
	static const char* Title;
	static SDL_Renderer* Renderer;
	static bool isRunning;
	static GameStateMachine gameStateMachine;
	static Uint64 currentTime;
	static Uint64 lastTime;
	static double deltaTime;
	static unsigned int screenWidth;
	static unsigned int screenHeight;

private:
	Game() {};
};