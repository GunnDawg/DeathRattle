#pragma once
#include <SDL.h>
#include <cassert>
#include <array>
#include <string>
#include <memory>
#include "Text.h"
#include "IO/FileIO.h"
#include "Level/LevelSet.h"

class Scoreboard
{
public:
	Scoreboard()=default;
	Scoreboard(unsigned int x, unsigned int y);
	~Scoreboard()=default;

	void Load();
	void Unload();
	void Update(const LevelSet& passedLevel);
	void Draw();
	void recordHighScore() const;

	bool SCORE_NEEDS_UPDATED                      = true;
	bool HIGHSCORE_NEEDS_UPDATED                  = false;
	bool STAGE_SCORE_NEEDS_UPDATED                = false;

	inline unsigned int getScore() const { return m_score; }
	inline unsigned int getHighScore() const { return m_highScore; }
	inline unsigned int getLevelScore() const { return m_levelScore; }

	inline void setScore(unsigned int x) { m_score = x; }
	inline void resetScore() { m_score = 0; }

	inline void increaseScore(unsigned int x) { m_score += x; }
	inline void decreaseScore(unsigned int x) { m_score -= x; }

	void showFinal();

private:
	Scoreboard(const Scoreboard& obj)=delete;
	Scoreboard& operator=(const Scoreboard&)=delete;

	std::unique_ptr<FileIO> m_File;

	const char* m_convertedScore                  = nullptr;
	const char* m_convertedHighScore              = nullptr;
	const char* m_convertedLevelScore             = nullptr;
	const char* m_convertedFinalScore             = nullptr;

	std::unique_ptr<Text> m_scoreLabel            = nullptr;
	std::unique_ptr<Text> m_scoreText             = nullptr;
	std::unique_ptr<Text> m_highScoreLabel        = nullptr;
	std::unique_ptr<Text> m_highScoreText         = nullptr;
	std::unique_ptr<Text> m_levelScoreLabel       = nullptr;
	std::unique_ptr<Text> m_levelScoreText        = nullptr;
	std::unique_ptr<Text> m_finalScoreLabel       = nullptr;
	std::unique_ptr<Text> m_finalScoreText        = nullptr;

	unsigned int m_score                          = 0;
	unsigned int m_highScore                      = 0;
	unsigned int m_levelScore                     = 0;

	std::string m_fs;
	std::string m_hs;
	std::string m_s;
	std::string m_ls;
};