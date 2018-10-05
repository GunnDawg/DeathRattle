#pragma once
#include <SDL.h>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>

#include "StateMachine/GameStateMachine.h"
#include "Player.h"
#include "Enemy.h"
#include "StateMachine/GameState.h"
#include "StateMachine/PlayerSceneState.h"
#include "StateMachine/EnemySceneState.h"

class Game
{
public:
	Game() = default;
	Game(const char* title, unsigned int w, unsigned int h);

	bool Init();
	void processinput();
	void Update();
	inline void beginRender() { SDL_RenderClear(m_Renderer); }
	void Draw();
	inline void endRender() { SDL_RenderPresent(m_Renderer); }
	void Unload();
	inline bool isRunning() { return m_isRunning; }

	void updateDelta();

	static bool m_isRunning;

private:
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	const char* m_Title = nullptr;
	unsigned int m_screenWidth = 0;
	unsigned int m_screenHeight = 0;

	double m_deltaTime;
	uint64_t m_currentTime;
	uint64_t m_lastTime;

	GameStateMachine m_gameStateMachine;
};