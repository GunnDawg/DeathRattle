#include "HUD.h"
#include "Game.h"

void HUD::Load(const LevelSet& passedLevel)
{
	game = &Game::GetInstance();

	//Top Left Display
	setRect(mTextBoxes[0], 336, 100, 12, 12);
	setRect(mBlackBoxes[0], 336, 100, mTextBoxes[0].x, mTextBoxes[0].y);

	//Top Right Display
	setRect(mTextBoxes[1], 336, 100, game->screenWidth - 350, 12);
	setRect(mBlackBoxes[1], 336, 100, mTextBoxes[1].x, mTextBoxes[1].y);

	//Health Bar
	setRect(mTextBoxes[2], 558, 35, (game->screenWidth / 2) - 280, 12);// <--- Use textBoxes[2] if you need to move it around.
	setRect(mTextBoxes[3], 550, 25, mTextBoxes[2].x + 4, mTextBoxes[2].y + 5); // <--- The red part of the bar :)
	setRect(mBlackBoxes[2], 550, 25, mTextBoxes[3].x, mTextBoxes[3].y);

	//Bonus Bar
	setRect(mTextBoxes[4], 558, 35, mTextBoxes[2].x, mTextBoxes[2].y + 55);
	setRect(mTextBoxes[5], 0, 25, mTextBoxes[4].x + 4, mTextBoxes[4].y + 5);
	setRect(mBlackBoxes[3], 550, 25, mTextBoxes[5].x, mTextBoxes[5].y);

	mBallSpeedString = std::to_string(NULL);
	mConvertedBallSpeed = mBallSpeedString.c_str();

	mLivesString = std::to_string(NULL);
	mConvertedLives = mLivesString.c_str();

	mLevelString = std::to_string(NULL);
	mConvertedLevel = mLevelString.c_str();

	mRemaininghpString = std::to_string(NULL);
	mConvertedHP = mRemaininghpString.c_str();

	mBallSpeedLabel                              = std::make_unique<Text>(24, "SPEED LEVEL");
	mBallSpeedText                               = std::make_unique<Text>(24, mConvertedBallSpeed);
	mLivesLabel                                  = std::make_unique<Text>(24, "LIVES");
	mLivesText                                   = std::make_unique<Text>(24, mConvertedLives);
	mLevelLabel                                  = std::make_unique<Text>(24, "STAGE");
	mLevelText                                   = std::make_unique<Text>(24, mConvertedLevel);
	mRemainingHP                                 = std::make_unique<Text>(22, mConvertedHP);
	mItemDropProgress                            = std::make_unique<Text>(22, "BONUS");

	m_ScoreBoard.Load();
	m_ScoreBoard.Update(passedLevel);
}

void HUD::Unload()
{
	m_ScoreBoard.Unload();

	mBallSpeedLabel->Unload();
	mBallSpeedText->Unload();
	mLivesLabel->Unload();
	mLivesText->Unload();
	mLevelLabel->Unload();
	mLevelText->Unload();
	mRemainingHP->Unload();
	mItemDropProgress->Unload();

	game = nullptr;
}

void HUD::drawHealthBar()
{
	SDL_SetRenderDrawColor(game->Renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(game->Renderer, &mTextBoxes[3]);
}

void HUD::drawProgressBar()
{
	SDL_SetRenderDrawColor(game->Renderer, 76, 220, 61, 255);
	SDL_RenderFillRect(game->Renderer, &mTextBoxes[5]);
}

void HUD::drawText()
{
	mBallSpeedLabel->Draw(mTextBoxes[1].x + 12, 24);
	mBallSpeedText->Draw(game->screenWidth - 64, 24);

	mLivesLabel->Draw(mBallSpeedLabel->mTextRect.x, mBallSpeedLabel->mTextRect.y + 24);
	mLivesText->Draw(game->screenWidth - 64, mLivesLabel->mTextRect.y);

	mLevelLabel->Draw(mBallSpeedLabel->mTextRect.x, mBallSpeedLabel->mTextRect.y + 48);
	mLevelText->Draw(game->screenWidth - 64, mLevelLabel->mTextRect.y);

	mRemainingHP->Draw(mTextBoxes[3].x + 235, mTextBoxes[3].y - 1);

	mItemDropProgress->Draw(mTextBoxes[5].x + 210, mTextBoxes[5].y - 1);
}

void HUD::drawBoxes()
{
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 100);
	for (std::size_t i = 0; i < mBlackBoxes.size(); ++i)
	{
		SDL_RenderFillRect(game->Renderer, &mBlackBoxes[i]);
	}
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);

	SDL_RenderDrawRect(game->Renderer, &mTextBoxes[0]);
	SDL_RenderDrawRect(game->Renderer, &mTextBoxes[1]);
	SDL_RenderDrawRect(game->Renderer, &mTextBoxes[2]);
	SDL_RenderDrawRect(game->Renderer, &mTextBoxes[4]);
}

void HUD::Draw()
{
	drawHealthBar();
	drawProgressBar();
	drawBoxes();
	drawText();

	m_ScoreBoard.Draw();
}

void HUD::Update(const LevelSet& passedLevel, const Ball& passedBall, const unsigned int lives, const unsigned int hp, const unsigned int progress)
{
	if (HP_TEXT_NEEDS_UPDATED)
	{
		mTextBoxes[3].w = hp;
		if (mTextBoxes[3].w < 0)
		{
			mTextBoxes[3].w = 0;
		}
	}

	mTextBoxes[5].w = progress;

	if (m_ScoreBoard.SCORE_NEEDS_UPDATED || m_ScoreBoard.HIGHSCORE_NEEDS_UPDATED)
	{
		m_ScoreBoard.Update(passedLevel);

		if (m_ScoreBoard.SCORE_NEEDS_UPDATED)
		{
			m_ScoreBoard.SCORE_NEEDS_UPDATED = false;
		}

		if (m_ScoreBoard.HIGHSCORE_NEEDS_UPDATED)
		{
			m_ScoreBoard.HIGHSCORE_NEEDS_UPDATED = false;
		}
	}

	if (BALL_SPEED_NEEDS_UPDATED)
	{
		mBallSpeedString = std::to_string(static_cast<int>(passedBall.getSpeed() * 10));
		mBallSpeedText->Update(mConvertedBallSpeed);
		BALL_SPEED_NEEDS_UPDATED = false;
	}

	if (LIVES_TEXT_NEEDS_UPDATED)
	{
		mLivesString = std::to_string(lives);
		mLivesText->Update(mConvertedLives);
		LIVES_TEXT_NEEDS_UPDATED = false;
	}

	if (LEVEL_NUM_NEEDS_UPDATED)
	{
		mLevelString = std::to_string(passedLevel.getLevelPlusOne());
		mLevelText->Update(mConvertedLevel);
		LEVEL_NUM_NEEDS_UPDATED = false;
	}

	if (HP_TEXT_NEEDS_UPDATED)
	{
		mRemaininghpString = std::to_string(static_cast<int>(hp / 550.0f * 100));
		mRemainingHP->Update(mConvertedHP);
		HP_TEXT_NEEDS_UPDATED = false;
	}
}

void HUD::setRect(SDL_Rect& r, const unsigned int w, const unsigned int h, const unsigned int x, const unsigned int y)
{
	r.w = w;
	r.h = h;
	r.x = x;
	r.y = y;
}