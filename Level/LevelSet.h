#pragma once

#include <cstdio>
#include <cassert>
#include <memory>
#include <array>
#include <vector>
#include <sstream>
#include "Graphics/Texture.h"
#include "Entity/Paddle.h"

constexpr unsigned int LEVEL_COUNT = 5;

class LevelSet
{
public:
	LevelSet()=default;
	LevelSet(const char* filePath);
	~LevelSet();

	void Load();
	void Unload(int x);
	void Draw();

	void setLevel(unsigned int x);
	void nextLevel();
	void prevLevel();
	inline unsigned int getLevel() const { return m_levelNum; }
	inline unsigned int getLevelPlusOne() const { return m_levelNum + 1; }
	void setScores(std::array<int, LEVEL_COUNT> s);
	inline unsigned int getScore(unsigned int s) const { return m_levelScore[s]; }

private:
	//LevelSet(const LevelSet& obj)=delete;
	//LevelSet& operator=(const LevelSet&)=delete;

	std::string m_filename;
	std::array<Texture, LEVEL_COUNT> m_levelTextures;
	std::array<unsigned int, LEVEL_COUNT> m_levelScore;

	unsigned int m_levelNum;
};