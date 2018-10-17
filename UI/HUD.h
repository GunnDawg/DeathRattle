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
	HUD(unsigned int w, unsigned int h, int hp, bool showing);
	~HUD();

	bool isShowing() const { return m_isShowing; }

	void Load(const unsigned int hp, bool showing);
	void Draw();
	void Update(const LevelSet& passedLevel, const Ball& passedBall, const unsigned int lives, const unsigned int hp, const unsigned int progress);
	inline void setShowing(bool showing) { m_isShowing = showing; }

	Scoreboard m_ScoreBoard = Scoreboard(24, 24);

private:
	//HUD(const HUD& obj)=default;
	//HUD& operator=(const HUD&)=default;

	void drawHealthBar();
	void drawProgressBar();
	void drawText();
	void drawBoxes();

	void setRect(SDL_Rect& r, const unsigned int w, const unsigned int h, const unsigned int x, const unsigned int y);

	std::string m_ballSpeedString;
	std::string m_livesString;
	std::string m_levelString;
	std::string m_remaininghpString;

	const char* m_convertedBallSpeed;
	const char* m_convertedLives;
	const char* m_convertedHP;
	const char* m_convertedLevel;

	std::array<SDL_Rect, NUM_BOXES> m_textBoxes;
	std::array<SDL_Rect, NUM_SHADED_BOXES> m_blackBoxes;

	std::unique_ptr<Text> m_ballSpeedLabel;
	std::unique_ptr<Text> m_ballSpeedText;
	std::unique_ptr<Text> m_LivesLabel;
	std::unique_ptr<Text> m_LivesText;
	std::unique_ptr<Text> m_levelLabel;
	std::unique_ptr<Text> m_levelText;
	std::unique_ptr<Text> m_remainingHP;
	std::unique_ptr<Text> m_itemDropProgress;

	bool m_isShowing;
};