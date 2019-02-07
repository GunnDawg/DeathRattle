#pragma once

#include <array>
#include <memory>
#include <string>
#include "UI/Scoreboard.h"
#include "UI/Text.h"
#include "Level/LevelSet.h"
#include "Entity/Ball.h"

constexpr unsigned int NUM_BOXES = 6;
constexpr unsigned int NUM_SHADED_BOXES = 4;

class Game;

class HUD
{
public:
	HUD()=default;
	~HUD()=default;

	inline bool isShowing() const { return m_isShowing; }

	void Load(const LevelSet& passedLevel);
	void Unload();
	void Draw();
	void Update(const LevelSet& passedLevel, const Ball& passedBall, const unsigned int lives, const unsigned int hp, const unsigned int progress);
	inline void setShowing(bool showing) { m_isShowing = showing; }

	Scoreboard m_ScoreBoard = Scoreboard(24, 24);

private:
	Game* game                                              = nullptr;

	void drawHealthBar();
	void drawProgressBar();
	void drawText();
	void drawBoxes();

	void setRect(SDL_Rect& r, const unsigned int w, const unsigned int h, const unsigned int x, const unsigned int y);

	std::string m_ballSpeedString;
	std::string m_livesString;
	std::string m_levelString;
	std::string m_remaininghpString;

	const char* m_convertedBallSpeed                        = nullptr;
	const char* m_convertedLives                            = nullptr;
	const char* m_convertedHP                               = nullptr;
	const char* m_convertedLevel                            = nullptr;

	std::array<SDL_Rect, NUM_BOXES> m_textBoxes             = { 0 };
	std::array<SDL_Rect, NUM_SHADED_BOXES> m_blackBoxes     = { 0 };

	std::unique_ptr<Text> m_ballSpeedLabel                  = nullptr;
	std::unique_ptr<Text> m_ballSpeedText                   = nullptr;
	std::unique_ptr<Text> m_LivesLabel                      = nullptr;
	std::unique_ptr<Text> m_LivesText                       = nullptr;
	std::unique_ptr<Text> m_levelLabel                      = nullptr;
	std::unique_ptr<Text> m_levelText                       = nullptr;
	std::unique_ptr<Text> m_remainingHP                     = nullptr;
	std::unique_ptr<Text> m_itemDropProgress                = nullptr;

	bool m_isShowing                                        = true;

	HUD(const HUD& obj) = default;
	HUD& operator=(const HUD&) = default;
};