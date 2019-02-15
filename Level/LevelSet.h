#pragma once
#include <cassert>
#include <memory>
#include <array>
#include <vector>
#include <sstream>
#include "Graphics/Texture.h"
#include "Entity/Paddle.h"

constexpr unsigned int LEVEL_COUNT = 5;

class Game;

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
	inline unsigned int getLevel() const { return mLevelNum; }
	inline unsigned int getLevelPlusOne() const { return mLevelNum + 1; }
	void setScores(std::array<int, LEVEL_COUNT> s);
	inline unsigned int getScore(unsigned int s) const { return mLevelScore[s]; }

private:
	Game* game = nullptr;

	std::string mFilename;
	std::array<Texture, LEVEL_COUNT> mLevelTextures = { };
	std::array<unsigned int, LEVEL_COUNT> mLevelScore = { 0 };

	unsigned int mLevelNum = 0;

	LevelSet(const LevelSet& obj) = delete;
	LevelSet& operator=(const LevelSet&) = delete;
};