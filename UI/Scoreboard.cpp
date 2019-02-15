#include "Scoreboard.h"
#include "Game.h"

Scoreboard::Scoreboard(unsigned int x, unsigned int y)
{
	assert(typeid(x) == typeid(unsigned int) && x > 0 && "Scoreboard must have an X value");
	assert(typeid(y) == typeid(unsigned int) && y > 0 && "Scoreboard must have an Y value");

	game                           = &Game::GetInstance();

	mFile                         = std::make_unique<FileIO>("ProfileData/highscore.txt");

	Load();

	mScoreLabel                   = std::make_unique<Text>(24, "SCORE");
	mScoreText                    = std::make_unique<Text>(24, mConvertedScore);
	mHighScoreLabel               = std::make_unique<Text>(24, "HIGH SCORE");
	mHighScoreText                = std::make_unique<Text>(24, mConvertedHighScore);
	mLevelScoreLabel              = std::make_unique<Text>(24, "LEVEL GOAL");
	mLevelScoreText               = std::make_unique<Text>(24, mConvertedLevelScore);

	mFinalScoreLabel              = std::make_unique<Text>(32, "FINAL SCORE");
	mFinalScoreText               = std::make_unique<Text>(48, mConvertedScore);

	mScoreLabel->mTextRect.x     = x;
	mScoreLabel->mTextRect.y     = y;

	mScoreText->mTextRect.x      = x;
	mScoreText->mTextRect.y      = y;
}

void Scoreboard::Load()
{
	//Load in our high score from file
	mHighScore = mFile->Read();
	if (mHighScore > 1000)
	{
		mConvertedHighScore = "ERROR";
	}
	else
	{
		mHs = std::to_string(mHighScore);
		mConvertedHighScore = mHs.data();
	}

	//Convert score to a char*
	mS = std::to_string(mScore);
	mConvertedScore = mS.data();

	//Convert level score to a char*
	mLs = std::to_string(mLevelScore);
	mConvertedLevelScore = mLs.data();
}

void Scoreboard::Unload()
{
	mScoreLabel->Unload();
	mScoreText->Unload();
	mHighScoreLabel->Unload();
	mHighScoreText->Unload();
	mLevelScoreLabel->Unload();
	mLevelScoreText->Unload();
	mFinalScoreLabel->Unload();
	mFinalScoreText->Unload();

	game = nullptr;
}

void Scoreboard::Update(const LevelSet& passedLevel)
{
	switch (passedLevel.getLevel())
	{
		case 0:
		{
			mLevelScore = passedLevel.getScore(0);
		} break;

		case 1:
		{
			mLevelScore = passedLevel.getScore(1);
		} break;

		case 2:
		{
			mLevelScore = passedLevel.getScore(2);
		} break;

		case 3:
		{
			mLevelScore = passedLevel.getScore(3);
		} break;

		case 4:
		{
			mLevelScore = passedLevel.getScore(4);
		} break;

	default:
		break;
	}

	mFs = std::to_string(mScore);
	mConvertedFinalScore = mFs.data();

	mLs = std::to_string(mLevelScore);

	if (mScore >= mHighScore)
	{
		mHs = std::to_string(mScore);
		mConvertedHighScore = mHs.data();
	}
	else
	{
		mHighScore = mFile->Read();
		mHs = std::to_string(mHighScore);
		mConvertedHighScore = mHs.data();
	}

	if (SCORE_NEEDS_UPDATED)
	{
		mS = std::to_string(mScore);
		mConvertedScore = mS.data();
		mScoreText->Update(mConvertedScore);
	}
	if (HIGHSCORE_NEEDS_UPDATED)
	{
		mHighScoreText->Update(mConvertedHighScore);
	}

	mLevelScoreText->Update(mConvertedLevelScore);
	mFinalScoreText->Update(mConvertedFinalScore);

	if (mScore >= mLevelScore)
	{
		mScoreText->Update({ 0, 255, 0, 255 });
	}
	else
	{
		mScoreText->Update({ 255, 255, 255, 255 });
	}
}

void Scoreboard::Draw()
{
	mScoreLabel->Draw(mScoreLabel->mTextRect.x, mScoreText->mTextRect.y);
	mScoreText->Draw((mScoreLabel->mTextRect.x) + 240, mScoreLabel->mTextRect.y);

	mLevelScoreLabel->Draw(mScoreLabel->mTextRect.x, (mScoreText->mTextRect.y) + 24);
	mLevelScoreText->Draw((mScoreLabel->mTextRect.x) + 240, (mHighScoreLabel->mTextRect.y) - 24);

	mHighScoreLabel->Draw(mScoreLabel->mTextRect.x, (mScoreText->mTextRect.y) + 48);
	mHighScoreText->Draw((mScoreLabel->mTextRect.x) + 240, (mHighScoreLabel->mTextRect.y));
}

void Scoreboard::recordHighScore()
{
	mFile->Write(mScore);
	HIGHSCORE_NEEDS_UPDATED = true;
}

void Scoreboard::showFinal()
{
	mFinalScoreLabel->Draw((game->screenWidth / 2) - (mFinalScoreLabel->mTextRect.w / 2), (game->screenHeight / 2) - 70);
	mFinalScoreText->Draw((game->screenWidth / 2) - (mFinalScoreText->mTextRect.w / 2), mFinalScoreLabel->mTextRect.y + 50);
}

void Scoreboard::increaseScore(unsigned int x)
{ 
	mScore += x;
	SCORE_NEEDS_UPDATED = true;
}
void Scoreboard::decreaseScore(unsigned int x)
{
	mScore -= x;
	SCORE_NEEDS_UPDATED = true;
}

void Scoreboard::resetScore()
{
	mScore = 0;
	SCORE_NEEDS_UPDATED = true;
}