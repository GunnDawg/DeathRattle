#include "HUD.h"
#include "Game.h"

void HUD::Load()
{
	//Top Left Display
	setRect(m_textBoxes[0], 336, 100, 12, 12);
	setRect(m_blackBoxes[0], 336, 100, m_textBoxes[0].x, m_textBoxes[0].y);

	//Top Right Display
	setRect(m_textBoxes[1], 336, 100, Game::screenWidth - 350, 12);
	setRect(m_blackBoxes[1], 336, 100, m_textBoxes[1].x, m_textBoxes[1].y);

	//Health Bar
	setRect(m_textBoxes[2], 558, 35, (Game::screenWidth / 2) - 280, 12);// <--- Use textBoxes[2] if you need to move it around.
	setRect(m_textBoxes[3], 550, 25, m_textBoxes[2].x + 4, m_textBoxes[2].y + 5); // <--- The red part of the bar :)
	setRect(m_blackBoxes[2], 550, 25, m_textBoxes[3].x, m_textBoxes[3].y);

	//Bonus Bar
	setRect(m_textBoxes[4], 558, 35, m_textBoxes[2].x, m_textBoxes[2].y + 55);
	setRect(m_textBoxes[5], 0, 25, m_textBoxes[4].x + 4, m_textBoxes[4].y + 5);
	setRect(m_blackBoxes[3], 550, 25, m_textBoxes[5].x, m_textBoxes[5].y);

	m_ballSpeedString = std::to_string(NULL);
	m_convertedBallSpeed = m_ballSpeedString.c_str();

	m_livesString = std::to_string(NULL);
	m_convertedLives = m_livesString.c_str();

	m_levelString = std::to_string(NULL);
	m_convertedLevel = m_levelString.c_str();

	m_remaininghpString = std::to_string(NULL);
	m_convertedHP = m_remaininghpString.c_str();

	m_ballSpeedLabel                              = std::make_unique<Text>(24, "SPEED LEVEL");
	m_ballSpeedText                               = std::make_unique<Text>(24, m_convertedBallSpeed);
	m_LivesLabel                                  = std::make_unique<Text>(24, "LIVES");
	m_LivesText                                   = std::make_unique<Text>(24, m_convertedLives);
	m_levelLabel                                  = std::make_unique<Text>(24, "STAGE");
	m_levelText                                   = std::make_unique<Text>(24, m_convertedLevel);
	m_remainingHP                                 = std::make_unique<Text>(22, m_convertedHP);
	m_itemDropProgress                            = std::make_unique<Text>(22, "BONUS");
}

void HUD::Unload()
{
	m_ScoreBoard.Unload();

	m_ballSpeedLabel->Unload();
	m_ballSpeedText->Unload();
	m_LivesLabel->Unload();
	m_LivesText->Unload();
	m_levelLabel->Unload();
	m_levelText->Unload();
	m_remainingHP->Unload();
	m_itemDropProgress->Unload();
}

void HUD::drawHealthBar()
{
	SDL_SetRenderDrawColor(Game::Renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(Game::Renderer, &m_textBoxes[3]);
}

void HUD::drawProgressBar()
{
	SDL_SetRenderDrawColor(Game::Renderer, 76, 220, 61, 255);
	SDL_RenderFillRect(Game::Renderer, &m_textBoxes[5]);
}

void HUD::drawText()
{
	m_ballSpeedLabel->Draw(m_textBoxes[1].x + 12, 24);
	m_ballSpeedText->Draw(Game::screenWidth - 64, 24);

	m_LivesLabel->Draw(m_ballSpeedLabel->m_textRect.x, m_ballSpeedLabel->m_textRect.y + 24);
	m_LivesText->Draw(Game::screenWidth - 64, m_LivesLabel->m_textRect.y);

	m_levelLabel->Draw(m_ballSpeedLabel->m_textRect.x, m_ballSpeedLabel->m_textRect.y + 48);
	m_levelText->Draw(Game::screenWidth - 64, m_levelLabel->m_textRect.y);

	m_remainingHP->Draw(m_textBoxes[3].x + 235, m_textBoxes[3].y - 1);

	m_itemDropProgress->Draw(m_textBoxes[5].x + 210, m_textBoxes[5].y - 1);
}

void HUD::drawBoxes()
{
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 100);
	for (std::size_t i = 0; i < m_blackBoxes.size(); ++i)
	{
		SDL_RenderFillRect(Game::Renderer, &m_blackBoxes[i]);
	}
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);

	SDL_RenderDrawRect(Game::Renderer, &m_textBoxes[0]);
	SDL_RenderDrawRect(Game::Renderer, &m_textBoxes[1]);
	SDL_RenderDrawRect(Game::Renderer, &m_textBoxes[2]);
	SDL_RenderDrawRect(Game::Renderer, &m_textBoxes[4]);
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
	m_textBoxes[3].w = hp;
	if (m_textBoxes[3].w < 0)
	{
		m_textBoxes[3].w = 0;
	}

	m_textBoxes[5].w = progress;

	m_ScoreBoard.Update(passedLevel);

	m_ballSpeedString = std::to_string(static_cast<int>(passedBall.getSpeed() * 10));
	m_ballSpeedText->Update(m_convertedBallSpeed);

	m_livesString = std::to_string(lives);
	m_LivesText->Update(m_convertedLives);

	m_levelString = std::to_string(passedLevel.getLevelPlusOne());
	m_levelText->Update(m_convertedLevel);

	m_remaininghpString = std::to_string(static_cast<int>(hp / 550.0f * 100));
	m_remainingHP->Update(m_convertedHP);
}

void HUD::setRect(SDL_Rect& r, const unsigned int w, const unsigned int h, const unsigned int x, const unsigned int y)
{
	r.w = w;
	r.h = h;
	r.x = x;
	r.y = y;
}