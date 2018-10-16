#pragma once

#include <SDL.h>
#include <cstdio>
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
	void Update(const LevelSet& passedLevel);
	void Draw() const;
	void recordHighScore() const;

	inline unsigned int getScore() const { return m_score; }
	inline unsigned int getHighScore() const { return m_highScore; }
	inline unsigned int getLevelScore() const { return m_levelScore; }

	inline void setScore(unsigned int x) { m_score = x; }
	inline void resetScore() { m_score = 0; }

	inline void increaseScore(unsigned int x) { m_score += x; }
	inline void decreaseScore(unsigned int x) { m_score -= x; }

	void showFinal();

private:
	//Scoreboard(const Scoreboard& obj)=delete;
	//Scoreboard& operator=(const Scoreboard&)=delete;

	std::unique_ptr<FileIO> m_File;

	const char* m_convertedScore;
	const char* m_convertedHighScore;
	const char* m_convertedLevelScore;
	const char* m_convertedFinalScore;

	//std::array<const char*, 4> m_convertedText;

	std::unique_ptr<Text> m_scoreLabel;
	std::unique_ptr<Text> m_scoreText;
	std::unique_ptr<Text> m_highScoreLabel;
	std::unique_ptr<Text> m_highScoreText;
	std::unique_ptr<Text> m_levelScoreLabel;
	std::unique_ptr<Text> m_levelScoreText;
	std::unique_ptr<Text> m_finalScoreLabel;
	std::unique_ptr<Text> m_finalScoreText;

	unsigned int m_score = 0;
	unsigned int m_highScore = 0;
	unsigned int m_levelScore = 0;
	std::array<unsigned int, 3> m_difficultyLevel;

	std::string m_fs;
	std::string m_hs;
	std::string m_s;
	std::string m_ls;
};