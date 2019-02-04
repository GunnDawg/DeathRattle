#include "Scoreboard.h"
#include "Game.h"

Scoreboard::Scoreboard(unsigned int x, unsigned int y)
{
	assert(typeid(x) == typeid(unsigned int) && x > 0 && "Scoreboard must have an X value");
	assert(typeid(y) == typeid(unsigned int) && y > 0 && "Scoreboard must have an Y value");

	m_File                         = std::make_unique<FileIO>("ProfileData/highscore.txt");

	Load();

	m_scoreLabel                   = std::make_unique<Text>(24, "SCORE");
	m_scoreText                    = std::make_unique<Text>(24, m_convertedScore);
	m_highScoreLabel               = std::make_unique<Text>(24, "HIGH SCORE");
	m_highScoreText                = std::make_unique<Text>(24, m_convertedHighScore);
	m_levelScoreLabel              = std::make_unique<Text>(24, "LEVEL GOAL");
	m_levelScoreText               = std::make_unique<Text>(24, m_convertedLevelScore);

	m_finalScoreLabel              = std::make_unique<Text>(32, "FINAL SCORE");
	m_finalScoreText               = std::make_unique<Text>(48, m_convertedScore);

	m_scoreLabel->m_textRect.x     = x;
	m_scoreLabel->m_textRect.y     = y;

	m_scoreText->m_textRect.x      = x;
	m_scoreText->m_textRect.y      = y;
}

void Scoreboard::Load()
{
	//Load in our high score from file
	m_highScore = m_File->Read();
	if (m_highScore > 1000)
	{
		m_convertedHighScore = "ERROR";
	}
	else
	{
		m_hs = std::to_string(m_highScore);
		m_convertedHighScore = m_hs.data();
	}

	//Convert score to a char*
	m_s = std::to_string(m_score);
	m_convertedScore = m_s.data();

	//Convert level score to a char*
	m_ls = std::to_string(m_levelScore);
	m_convertedLevelScore = m_ls.data();
}

void Scoreboard::Unload()
{
	m_scoreLabel->Unload();
	m_scoreText->Unload();
	m_highScoreLabel->Unload();
	m_highScoreText->Unload();
	m_levelScoreLabel->Unload();
	m_levelScoreText->Unload();
	m_finalScoreLabel->Unload();
	m_finalScoreText->Unload();
}

void Scoreboard::Update(const LevelSet& passedLevel)
{
	m_s = std::to_string(m_score);
	m_convertedScore = m_s.data();

	m_fs = std::to_string(m_score);
	m_convertedFinalScore = m_fs.data();

	m_ls = std::to_string(m_levelScore);

	if (m_score >= m_highScore)
	{
		m_hs = std::to_string(m_score);
		m_convertedHighScore = m_hs.data();
	}
	else
	{
		m_highScore = m_File->Read();
		m_hs = std::to_string(m_highScore);
		m_convertedHighScore = m_hs.data();
	}

	if (SCORE_NEEDS_UPDATED)
	{
		m_scoreText->Update(m_convertedScore);
	}
	m_highScoreText->Update(m_convertedHighScore);
	m_levelScoreText->Update(m_convertedLevelScore);
	m_finalScoreText->Update(m_convertedFinalScore);

	switch (passedLevel.getLevel())
	{
		case 0:
		{
			m_levelScore = passedLevel.getScore(0);
		} break;

		case 1:
		{
			m_levelScore = passedLevel.getScore(1);
		} break;

		case 2:
		{
			m_levelScore = passedLevel.getScore(2);
		} break;

		case 3:
		{
			m_levelScore = passedLevel.getScore(3);
		} break;

		case 4:
		{
			m_levelScore = passedLevel.getScore(4);
		} break;

	default:
		break;
	}

	if (m_score >= m_levelScore)
	{
		m_scoreText->Update({ 0, 255, 0, 255 });
	}
	else
	{
		m_scoreText->Update({ 255, 255, 255, 255 });
	}
}

void Scoreboard::Draw()
{
	m_scoreLabel->Draw(m_scoreLabel->m_textRect.x, m_scoreText->m_textRect.y);
	m_scoreText->Draw((m_scoreLabel->m_textRect.x) + 240, m_scoreLabel->m_textRect.y);

	m_levelScoreLabel->Draw(m_scoreLabel->m_textRect.x, (m_scoreText->m_textRect.y) + 24);
	m_levelScoreText->Draw((m_scoreLabel->m_textRect.x) + 240, (m_highScoreLabel->m_textRect.y) - 24);

	m_highScoreLabel->Draw(m_scoreLabel->m_textRect.x, (m_scoreText->m_textRect.y) + 48);
	m_highScoreText->Draw((m_scoreLabel->m_textRect.x) + 240, (m_highScoreLabel->m_textRect.y));
}

void Scoreboard::recordHighScore() const
{
	m_File->Write(m_score);
}

void Scoreboard::showFinal()
{
	m_finalScoreLabel->Draw((Game::screenWidth / 2) - (m_finalScoreLabel->m_textRect.w / 2), (Game::screenHeight / 2) - 70);
	m_finalScoreText->Draw((Game::screenWidth / 2) - (m_finalScoreText->m_textRect.w / 2), m_finalScoreLabel->m_textRect.y + 50);
}