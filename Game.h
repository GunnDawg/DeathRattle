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
#include "Scenes/GameplayScene.h"

class Game
{
public:
	Game() = default;
	Game(const char* title);
	~Game();

	bool Init();
	void processinput();
	void Update();
	void Draw();
	void exitGame();

	inline bool isRunning() { return m_isRunning; }

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

private:
	void updateDelta();
	inline void beginRender() { SDL_RenderClear(m_Renderer); }
	inline void endRender() { SDL_RenderPresent(m_Renderer); }
};