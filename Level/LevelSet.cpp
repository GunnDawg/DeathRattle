#include "LevelSet.h"
#include "Game.h"

#include <cassert>
#include <sstream>
#include "Entity/Paddle.h"

LevelSet::LevelSet(const char* filePath)
{
	assert(typeid(filePath) == typeid(const char*) && filePath > 0);

	game = &Game::GetInstance();

	for (std::size_t i = 0; i < mLevelTextures.size(); i++)
	{
		std::ostringstream out;
		out << filePath << "level" << i << ".png";
		mFilename = out.str();
		mLevelTextures[i] = Texture(mFilename);
	}
}

LevelSet::~LevelSet()
{
	Unload(mLevelNum);
}

void LevelSet::Load()
{
	mLevelTextures[mLevelNum].Load();
	mLevelTextures[mLevelNum].setRect(0, 0, game->screenWidth, game->screenHeight);
}

void LevelSet::Unload(int x)
{
	mLevelTextures[x].Unload();

	//game = nullptr;
}

void LevelSet::setScores(std::array<int, LEVEL_COUNT> s)
{
	for (std::size_t i = 0; i < s.size(); ++i)
	{
		mLevelScore[i] = s[i];
	}
}

void LevelSet::Draw()
{
	SDL_Rect rect = mLevelTextures[mLevelNum].mTextureRect;
	SDL_RenderCopy(game->Renderer, mLevelTextures[mLevelNum].mTexture, nullptr, &rect);
}

void LevelSet::setLevel(unsigned int x)
{
	mLevelNum = x;
}

void LevelSet::nextLevel()
{
	if (mLevelNum < (mLevelTextures.size() - 1))
	{
		Unload(mLevelNum);
		++mLevelNum;
		Load();
	}
	else
	{
		Unload(mLevelNum);
		mLevelNum = 0;
		Load();
	}
}

void LevelSet::prevLevel()
{
	if (mLevelNum >= 1)
	{
		Unload(mLevelNum);
		--mLevelNum;
		Load();
	}
}