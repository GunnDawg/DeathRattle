#pragma once
namespace Settings
{
	struct GamePlay
	{
		enum class GameDifficulty { EASY, MEDIUM, HARD};
		enum class GameInput { MOUSE, KEYBOARD};

		inline static GameDifficulty Difficulty        = GameDifficulty::MEDIUM;
		inline static GameInput Input                  = GameInput::MOUSE;
	};

	struct Display
	{
		inline static bool FullScreen = 0; // 0 = Windowed 1 = Fullscreen
	};

	struct Audio
	{
		inline static bool MenuMusic                   = 1; // 0 = Off 1 = On
		inline static bool GamePlayMusic               = 1;
		inline static bool SoundEffects                = 1;
	};
}