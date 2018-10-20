#pragma once

#include <cstdio>
#include <cassert>
#include <array>
#include <memory>
#include <string>
#include "UI/Scoreboard.h"
#include "UI/Text.h"
#include "Level/LevelSet.h"
#include "Entity/Ball.h"

constexpr unsigned int NUM_BOXES = 6;
constexpr unsigned int NUM_SHADED_BOXES = 4;

class HUD
{
public:
	HUD() = default;
	~HUD() = default;

	bool isShowing() const { return m_isShowing; }

	void Load();
	void Unload();
	void Draw();
	void Update(const LevelSet& passedLevel, const Ball& passedBall, const unsigned int lives, const unsigned int hp, const unsigned int progress);
	inline void setShowing(bool showing) { m_isShowing = showing; }

	Scoreboard m_ScoreBoard;

private:
	//HUD(const HUD& obj)=default;
	//HUD& operator=(const HUD&)=default;

	void drawHealthBar();
	void drawProgressBar();
	void drawText();
	void drawBoxes();
	void setRect(SDL_Rect& r, const unsigned int w, const unsigned int h, const unsigned int x, const unsigned int y);

	const char* m_convertedBallSpeed                         = nullptr;
	const char* m_convertedLives                             = nullptr;
	const char* m_convertedHP                                = nullptr;
	const char* m_convertedLevel                             = nullptr;

	std::array<SDL_Rect, NUM_BOXES> m_textBoxes              = { 0 };
	std::array<SDL_Rect, NUM_SHADED_BOXES> m_blackBoxes      = { 0 };

	std::string m_ballSpeedString;
	std::string m_livesString;
	std::string m_levelString;
	std::string m_remaininghpString;

	Text m_ballSpeedLabel;
	Text m_ballSpeedText;
	Text m_LivesLabel;
	Text m_LivesText;
	Text m_levelLabel;
	Text m_levelText;
	Text m_remainingHP;
	Text m_itemDropProgress;

	bool m_isShowing                                         = true;
};