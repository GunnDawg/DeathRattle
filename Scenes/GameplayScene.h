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

	unsigned int m_difficulty                      = 1;
	int m_health                                   = 550;
	int m_bonusProgress                            = 0;
	unsigned int m_lives                           = 3;
	const char* m_convertedLives                   = nullptr;
	std::string m_LivesString;

	Keyboard m_keyBoard;
	Mouse m_mouse;
	int m_mouseX                                   = 0;
	int m_mouseY                                   = 0;

	HUD m_HUD;

	std::array<std::unique_ptr<Paddle>, NUM_PADDLES> m_paddles = {
		std::make_unique<Paddle>((Game::screenWidth / 6.5), 15, (Game::screenWidth / 2) - (175 / 2), 30),
		std::make_unique<Paddle>(15, (Game::screenHeight / 4), Game::screenWidth - 45, (Game::screenHeight / 2) - (175 / 2)),
		std::make_unique<Paddle>((Game::screenWidth / 6.5), 15, (Game::screenWidth / 2) - (175 / 2), Game::screenHeight - 45),
		std::make_unique<Paddle>(15, (Game::screenHeight / 4), 30, (Game::screenHeight / 2) - (175 / 2))
	};

	std::unique_ptr<LevelSet> m_dungeonLevels      = std::make_unique<LevelSet>("Assets/Graphics/Levels/Dungeon/");

	std::unique_ptr<Ball> m_ball                   = std::make_unique<Ball>(m_difficulty);

	AABBCollision m_collider;

	Sound m_hitSound                               = Sound("Assets/Sounds/hitnormal.wav");
	Sound m_hitBadSound                            = Sound("Assets/Sounds/hitbad.wav");
	Sound m_pauseSound                             = Sound("Assets/Sounds/pause.wav");
	Sound m_gameOverSound                          = Sound("Assets/Sounds/gameover.wav");
	Sound m_heal                                   = Sound("Assets/Sounds/heal.wav");

	std::unique_ptr<Text> m_gameTitle              = std::make_unique<Text>(48, "KEEP IT ALIVE");
	std::unique_ptr<Text> m_gameTitleStart         = std::make_unique<Text>(12, "Press SPACE to start or ESC to exit");
	std::unique_ptr<Text> m_pausedText             = std::make_unique<Text>(48, "PAUSED");
	std::unique_ptr<Text> m_pressSpaceText         = std::make_unique<Text>(12, "Press SPACE to continue or ESC to exit");
	std::unique_ptr<Text> m_gameOverText           = std::make_unique<Text>(48, "GAME OVER");
	std::unique_ptr<Text> m_gameOverNewGameText    = std::make_unique<Text>(12, "Press N to start a new game or ESC to exit");
	std::unique_ptr<Text> m_levelPassed            = std::make_unique<Text>(48, "LEVEL COMPLETE");
	std::unique_ptr<Text> m_levelPassedContinue    = std::make_unique<Text>(12, "Press N to continue to the next level");

	Texture m_dead                                 = Texture("Assets/Graphics/gameplay_scene/gameover.png");
	Texture m_cursor                               = Texture("Assets/Graphics/common/cursor.png");

	SDL_Rect m_finalScoreBox                       = { 0 };
	SDL_Rect m_finalScoreBoxOutline                = { 0 };

	bool m_running                                 = false;
	bool m_paused                                  = true;
	bool m_gameOver                                = false;
	bool m_levelWon                                = false;
	bool m_newGame                                 = true;
};