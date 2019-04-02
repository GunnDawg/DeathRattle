#pragma once

#include <string>
#include <memory>
#include "Text.h"
#include "IO/FileIO.h"
#include "Level/LevelSet.h"

class Game;

class Scoreboard
{
public:
	Scoreboard()=default;
	Scoreboard(unsigned int x, unsigned int y);

	void Load();
	void Unload();
	void Update(const LevelSet& passedLevel);
	void Draw();
	void recordHighScore();

	bool SCORE_NEEDS_UPDATED                      = false;
	bool HIGHSCORE_NEEDS_UPDATED                  = true;
	bool STAGE_SCORE_NEEDS_UPDATED                = false;

	inline unsigned int getScore() const { return mScore; }
	inline unsigned int getHighScore() const { return mHighScore; }
	inline unsigned int getLevelScore() const { return mLevelScore; }

	inline void setScore(unsigned int x) { mScore = x; }

	void increaseScore(unsigned int x);
	void decreaseScore(unsigned int x);
	void resetScore();

	void showFinal();

private:
	Game* game                                    = nullptr;

	std::unique_ptr<FileIO> mFile;

	const char* mConvertedScore                  = nullptr;
	const char* mConvertedHighScore              = nullptr;
	const char* mConvertedLevelScore             = nullptr;
	const char* mConvertedFinalScore             = nullptr;

	std::unique_ptr<Text> mScoreLabel            = nullptr;
	std::unique_ptr<Text> mScoreText             = nullptr;
	std::unique_ptr<Text> mHighScoreLabel        = nullptr;
	std::unique_ptr<Text> mHighScoreText         = nullptr;
	std::unique_ptr<Text> mLevelScoreLabel       = nullptr;
	std::unique_ptr<Text> mLevelScoreText        = nullptr;
	std::unique_ptr<Text> mFinalScoreLabel       = nullptr;
	std::unique_ptr<Text> mFinalScoreText        = nullptr;

	unsigned int mScore                          = 0;
	unsigned int mHighScore                      = 0;
	unsigned int mLevelScore                     = 0;

	std::string mFs;
	std::string mHs;
	std::string mS;
	std::string mLs;
};