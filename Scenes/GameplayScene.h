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

	Paddle* getPaddle();

	void checkCollision();
	void checkforBonus();
	void checkforGameOver();
	bool checkforWin();

private:

	unsigned int m_difficulty = 1;
	int m_health = 550;
	int m_bonusProgress = 0;
	unsigned int m_lives = 3;
	const char* m_convertedLives = nullptr;
	std::string m_LivesString;

	Keyboard m_keyBoard;
	Mouse m_mouse;
	int m_mouseX = 0;
	int m_mouseY = 0;

	HUD m_HUD;

	std::unique_ptr<LevelSet> m_dungeonLevels;

	std::array<std::unique_ptr<Paddle>, NUM_PADDLES> m_paddles;
	//std::array<std::unique_ptr<Item>, NUM_ITEMS> m_items;
	unsigned int m_itemNum = 0;

	std::unique_ptr<Ball> m_ball;

	AABBCollision m_collider;

	Sound m_hitSound;
	Sound m_hitBadSound;
	Sound m_pauseSound;
	Sound m_gameOverSound;
	Sound m_heal;

	std::unique_ptr<Text> m_gameTitle;
	std::unique_ptr<Text> m_gameTitleStart;
	std::unique_ptr<Text> m_pausedText;
	std::unique_ptr<Text> m_pressSpaceText;
	std::unique_ptr<Text> m_gameOverText;
	std::unique_ptr<Text> m_gameOverNewGameText;
	std::unique_ptr<Text> m_levelPassed;
	std::unique_ptr<Text> m_levelPassedContinue;

	Texture m_dead;
	Texture m_cursor;

	SDL_Rect m_finalScoreBox;
	SDL_Rect m_finalScoreBoxOutline;

	bool m_running = false;
	bool m_paused = true;
	bool m_gameOver = false;
	bool m_levelWon = false;
	bool m_newGame = true;
	bool m_cached = false;
};