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
#include "Scenes/IntroScene.h"

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
	static void exitGame();

	static inline bool isRunning() { return m_isRunning; }

	static SDL_Window* m_Window;
	static const char* m_Title;
	static SDL_Renderer* m_Renderer;
	static bool m_isRunning;
	static GameStateMachine m_gameStateMachine;
	static Uint64 m_currentTime;
	static Uint64 m_lastTime;
	static double m_deltaTime;
	static unsigned int m_screenWidth;
	static unsigned int m_screenHeight;

	static void updateDelta();
	static inline void beginRender() { SDL_RenderClear(m_Renderer); }
	static inline void endRender() { SDL_RenderPresent(m_Renderer); }

private:
	Game();
};