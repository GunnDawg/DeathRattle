#pragma once
#include <SDL.h>

namespace Settings
{
	struct GamePlay
	{
		enum class GameDifficulty                      { EASY, MEDIUM, HARD };
		enum class GameInput                           { MOUSE, KEYBOARD, GAMEPAD };

		inline static GameDifficulty Difficulty        = GameDifficulty::MEDIUM;
		inline static GameInput Input                  = GameInput::MOUSE;
	};

	struct Display
	{
		inline static SDL_WindowFlags WindowMode       = SDL_WINDOW_SHOWN;
		inline static unsigned int WindowWidth         = 1280;
		inline static unsigned int WindowHeight        = 720;
	};

	struct Audio
	{
		inline static bool MenuMusic                   = 1;
		inline static bool GamePlayMusic               = 1;
		inline static bool SoundEffects                = 1;
	};
}
