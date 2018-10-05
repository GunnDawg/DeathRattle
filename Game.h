#pragma once
#include <SDL.h>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

#include "Player.h"
#include "StateMachine/GameState.h"

class Game
{
public:
	Game() = default;
	Game(const char* title, unsigned int w, unsigned int h);

	bool Init();
	void processinput();
	void Update();
	void Draw();
	void Unload();
	bool isRunning() { return m_isRunning; }

	void updateDelta();

	GameStateMachine m_gameStateMachine;

private:
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	const char* m_Title = nullptr;
	unsigned int m_screenWidth = 0;
	unsigned int m_screenHeight = 0;

	double m_deltaTime;
	uint64_t m_currentTime;
	uint64_t m_lastTime;

	bool m_isRunning;

	Player m_player;
};