#pragma once
#include "StateMachine/GameState.h"
#include "Entity/Ball.h"
#include "Entity/Paddle.h"
#include "UI/HUD.h"
#include "UI/Text.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"
#include "Level/LevelSet.h"
#include "Physics/AABBCollision.h"
#include "Audio/Sound.h"
#include "GameSettings.h"
#include "Audio/MusicManager.h"
#include "Graphics/Animation.h"

constexpr unsigned int NUM_PADDLES = 4;
constexpr unsigned int NUM_ITEMS = 5;
constexpr unsigned int NUM_LEVEL_SETS = 2;

class GameplayState : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void handle_events() override;
	void draw() override;

	void drawCursor();
	void drawLevel();
	void drawPaddles();
	void drawBall();
	void drawText();
	void resetGame();

	void checkCollision();
	void checkforBonus();
	void checkforGameOver();
	bool checkforWin();

	Paddle* getPaddle();

private:
	MusicManager* JukeBox               = &MusicManager::getInstance();

	std::array<Paddle, NUM_PADDLES> m_paddles = {
		Paddle((Game::screenWidth / 6.5), 15, (Game::screenWidth / 2) - (175 / 2), 30),
		Paddle(15, (Game::screenHeight / 4), Game::screenWidth - 45, (Game::screenHeight / 2) - (175 / 2)),
		Paddle((Game::screenWidth / 6.5), 15, (Game::screenWidth / 2) - (175 / 2), Game::screenHeight - 45),
		Paddle(15, (Game::screenHeight / 4), 30, (Game::screenHeight / 2) - (175 / 2))
	};

	int m_health                        = 550;
	int m_bonusProgress                 = 0;
	unsigned int m_lives                = 3;
	const char* m_convertedLives        = nullptr;
	std::string m_LivesString;

	Keyboard m_keyBoard                 = Keyboard(false);
	Mouse m_mouse                       = Mouse(true);
	int m_mouseX                        = 0;
	int m_mouseY                        = 0;

	HUD m_HUD;

	LevelSet m_dungeonLevels            = LevelSet("Assets/Graphics/Levels/Dungeon/");

	Ball m_ball                         = Ball(Settings::GamePlay::Difficulty);

	AABBCollision m_collider;

	Sound m_hitSound                    = Sound("Assets/Audio/hitnormal.wav");
	Sound m_hitBadSound                 = Sound("Assets/Audio/hitbad.wav");
	Sound m_pauseSound                  = Sound("Assets/Audio/pause.wav");
	Sound m_gameOverSound               = Sound("Assets/Audio/gameover.wav");
	Sound m_heal                        = Sound("Assets/Audio/heal.wav");

	Text m_gameTitle                    = Text(48, "KEEP IT ALIVE");
	Text m_gameTitleStart               = Text(12, "Press SPACE to start or ESC to exit");
	Text m_pausedText                   = Text(48, "PAUSED");
	Text m_pressSpaceText               = Text(12, "Press SPACE to continue or ESC to exit");
	Text m_gameOverText                 = Text(48, "GAME OVER");
	Text m_gameOverNewGameText          = Text(12, "Press N to start a new game or ESC to exit");
	Text m_levelPassed                  = Text(48, "LEVEL COMPLETE");
	Text m_levelPassedContinue          = Text(12, "Press N to continue to the next level");

	Texture m_grimReaper                = Texture("Assets/Graphics/gameplay_scene/grim_reaper.png");
	Texture m_cursor                    = Texture("Assets/Graphics/common/cursor.png");

	std::array<Animation, 2> m_Flames   = { Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00),
									        Animation("Assets/Graphics/Animations/flames.png", 8, 4, 16.00) };

	SDL_Rect m_finalScoreBox            = { 0 };

	SDL_Rect m_finalScoreBoxOutline     = { 0 };

	bool m_paused                       = true;
	bool m_gameOver                     = false;
	bool m_levelWon                     = false;
	bool m_newGame                      = true;
};