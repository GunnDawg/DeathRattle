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

	inline bool isShowing() const { return mShowing; }

	void Load(const LevelSet& passedLevel);
	void Unload();
	void Draw();
	void Update(const LevelSet& passedLevel, const Ball& passedBall, const unsigned int lives, const unsigned int hp, const unsigned int progress);
	inline void setShowing(bool showing) { mShowing = showing; }

	Scoreboard m_ScoreBoard = Scoreboard(24, 24);

	bool BALL_SPEED_NEEDS_UPDATED                           = true;
	bool LIVES_TEXT_NEEDS_UPDATED                           = true;
	bool HP_TEXT_NEEDS_UPDATED                              = true;
	bool LEVEL_NUM_NEEDS_UPDATED                            = true;

private:
	Game* game                                              = nullptr;

	void drawHealthBar();
	void drawProgressBar();
	void drawText();
	void drawBoxes();

	void setRect(SDL_Rect& r, const unsigned int w, const unsigned int h, const unsigned int x, const unsigned int y);

	std::string mBallSpeedString;
	std::string mLivesString;
	std::string mLevelString;
	std::string mRemaininghpString;

	const char* mConvertedBallSpeed                        = nullptr;
	const char* mConvertedLives                            = nullptr;
	const char* mConvertedHP                               = nullptr;
	const char* mConvertedLevel                            = nullptr;

	std::array<SDL_Rect, NUM_BOXES> mTextBoxes             = { 0 };
	std::array<SDL_Rect, NUM_SHADED_BOXES> mBlackBoxes     = { 0 };

	std::unique_ptr<Text> mBallSpeedLabel                  = nullptr;
	std::unique_ptr<Text> mBallSpeedText                   = nullptr;
	std::unique_ptr<Text> mLivesLabel                      = nullptr;
	std::unique_ptr<Text> mLivesText                       = nullptr;
	std::unique_ptr<Text> mLevelLabel                      = nullptr;
	std::unique_ptr<Text> mLevelText                       = nullptr;
	std::unique_ptr<Text> mRemainingHP                     = nullptr;
	std::unique_ptr<Text> mItemDropProgress                = nullptr;

	bool mShowing                                        = true;
};