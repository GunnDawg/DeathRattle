#include "GameplayScene.h"
#include "Scenes/MainMenuScene.h"
#include "Game.h"

void GameplayState::on_enter()
{
	GUNN_CORE_INFO("----------ENTERING GAMEPLAY SCENE----------");

	game = &Game::GetInstance();

	switch (Settings::GamePlay::Input)
	{
		case Settings::GamePlay::GameInput::MOUSE:
		{
			m_mouse.On();
			m_keyBoard.Off();
		} break;

		case Settings::GamePlay::GameInput::KEYBOARD:
		{
			m_mouse.Off();
			m_keyBoard.On();
		} break;

		case Settings::GamePlay::GameInput::GAMEPAD:
		{
			m_mouse.Off();
			m_keyBoard.Off();

			GUNN_CORE_ERROR("Controller support coming soon!!");
			game->isRunning = false;
		} break;

	default:
		GUNN_CORE_ERROR("Invalid input mode set.");
	}

	m_paddles = {
		Paddle((game->screenWidth / 6.5), 15, (game->screenWidth / 2) - (175 / 2), 30),
		Paddle(15, (game->screenHeight / 4), game->screenWidth - 45, (game->screenHeight / 2) - (175 / 2)),
		Paddle((game->screenWidth / 6.5), 15, (game->screenWidth / 2) - (175 / 2), game->screenHeight - 45),
		Paddle(15, (game->screenHeight / 4), 30, (game->screenHeight / 2) - (175 / 2))
	};

	m_cursor.Load();

	m_grimReaper.Load();
	m_grimReaper.setRect((game->screenWidth / 2) - (m_grimReaper.mTextureRect.w / 2),
		                  game->screenHeight - m_grimReaper.mTextureRect.h,
		                  m_grimReaper.mTextureRect.w,
		                  m_grimReaper.mTextureRect.h);

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_ball.Load();

	m_dungeonLevels.Load();
	m_dungeonLevels.setScores({ 10, 50, 175, 250, 300 });

	m_HUD.Load(m_dungeonLevels);

	m_hitSound.Load();
	m_hitBadSound.Load();
	m_pauseSound.Load();
	m_gameOverSound.Load();
	m_heal.Load();
	m_heal.setVolume(4);

	if (Settings::Audio::GamePlayMusic == 1)
	{
		JukeBox->Load(JukeBox->GamePlayMusic);
		JukeBox->Play(JukeBox->GamePlayMusic);
	}
}

void GameplayState::on_exit()
{
	GUNN_CORE_INFO("<-----UNLOADING GAME--------->\n");

	m_HUD.Unload();

	m_gameTitle.Unload();
	m_gameTitleStart.Unload();
	m_pausedText.Unload();
	m_pressSpaceText.Unload();
	m_gameOverText.Unload();
	m_gameOverNewGameText.Unload();
	m_levelPassed.Unload();
	m_levelPassedContinue.Unload();

	m_hitSound.Unload();
	m_hitBadSound.Unload();
	m_pauseSound.Unload();
	m_gameOverSound.Unload();
	m_heal.Unload();

	m_grimReaper.Unload();
	m_cursor.Unload();
	m_ball.Unload();
	m_dungeonLevels.Unload(m_dungeonLevels.getLevel());

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	if (Settings::Audio::GamePlayMusic == 1)
	{
		JukeBox->Stop(JukeBox->GamePlayMusic);
		JukeBox->Unload(JukeBox->GamePlayMusic);
	}

	game = nullptr;
	JukeBox = nullptr;
}

void GameplayState::handle_events()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
			{
				game->isRunning = false;
			} break;

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						if (m_paused || m_gameOver || m_levelWon)
						{
							game->gameStateMachine.pop();

							std::unique_ptr<GameState> mainMenuState = std::make_unique<MainMenuScene>();
							game->gameStateMachine.push(std::move(mainMenuState));
						}
						else
						{
							m_paused = true;
						}
					} break;

					case SDLK_SPACE:
					{
						if (m_newGame)
						{
							m_newGame = false;
							m_paused = false;
						}
						else if (m_paused && !m_gameOver)
						{
							m_paused = false;
						}
						else if (!m_paused)
						{
							m_paused = true;
						}
					} break;

					case SDLK_n:
					{
						if (m_gameOver || m_levelWon)
						{
							resetGame();
							m_gameOver = false;
							m_levelWon = false;
							m_newGame = true;
						}
					} break;

					case SDLK_h:
					{
						if (m_HUD.isShowing())
						{
							m_HUD.setShowing(false);
						}
						else
						{
							m_HUD.setShowing(true);
						}
					} break;

				default:
					break;
				}
			} break;

		default:
			break;
		}
	}
}

void GameplayState::update()
{
	m_HUD.Update(m_dungeonLevels, m_ball, m_lives, m_health, m_bonusProgress);

	m_cursor.setRect(game->mouseX, game->mouseY);
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
	}

	if (m_health <= 0)
	{
		m_health = 0;
		m_HUD.HP_TEXT_NEEDS_UPDATED = true;
	}

	if (m_paused)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		SDL_ShowCursor(0);
	}
	else
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);

		if (m_mouse.isEnabled())
		{
			m_mouse.Update(&m_paddles[0], &m_paddles[1], &m_paddles[2], &m_paddles[3]);
		}
		else if (m_keyBoard.isEnabled())
		{
			m_keyBoard.Update(game->avgDeltaTime, 1.75, game->screenWidth, game->screenHeight, m_paddles[0], m_paddles[1], m_paddles[2], m_paddles[3]);
		}

		m_ball.Update();

		checkforGameOver();
		checkCollision();
		checkforBonus();
	}
}

void GameplayState::drawCursor()
{
	SDL_RenderCopy(game->Renderer, m_cursor.mTexture, NULL, &m_cursor.mTextureRect);
}

void GameplayState::drawLevel()
{
	m_dungeonLevels.Draw();
}

void GameplayState::drawPaddles()
{
	for (std::size_t i = 0; i < m_paddles.size(); ++i)
	{
		m_paddles[i].Draw();
	}
}

void GameplayState::drawBall()
{
	m_ball.Draw();
}

void GameplayState::drawText()
{
	if (m_HUD.isShowing())
	{
		m_HUD.Draw();
	}

	if (m_gameOver)
	{
		SDL_Rect rect = m_grimReaper.mTextureRect;
		SDL_RenderCopy(game->Renderer, m_grimReaper.mTexture, nullptr, &rect);
		m_gameOverText.Draw((game->screenWidth / 2) - (m_gameOverText.mTextRect.w / 2), (game->screenHeight / 2) - 150);
		m_gameOverNewGameText.Draw((game->screenWidth / 2) - 225, (game->screenHeight / 2) - 90);
	}

	else if (m_levelWon)
	{
		m_levelPassed.Draw((game->screenWidth / 2) - (m_levelPassed.mTextRect.w / 2), (game->screenHeight / 2) - 150);
		m_levelPassedContinue.Draw((game->screenWidth / 2) - (m_levelPassedContinue.mTextRect.w / 2), (game->screenHeight / 2) - 90);
	}

	else if (m_paused && !m_newGame)
	{
		m_pausedText.Draw((game->screenWidth / 2) - (m_pausedText.mTextRect.w / 2), (game->screenHeight / 2) - 150);
		m_pressSpaceText.Draw((game->screenWidth / 2) - (m_pressSpaceText.mTextRect.w / 2), (game->screenHeight / 2) - 90);
	}

	else if (m_paused && m_newGame)
	{
		m_gameTitle.Draw((game->screenWidth / 2) - (m_gameTitle.mTextRect.w / 2), (game->screenHeight / 2) - 150);
		m_gameTitleStart.Draw((game->screenWidth / 2) - 185, (game->screenHeight / 2) - 90);
	}
}

void GameplayState::draw()
{
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 255);
	drawLevel();

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	if (m_gameOver || m_levelWon)
	{
		m_finalScoreBox.w = 700;
		m_finalScoreBox.h = 300;
		m_finalScoreBox.x = (game->screenWidth / 2) - (m_finalScoreBox.w / 2);
		m_finalScoreBox.y = (game->screenHeight / 2) - (m_finalScoreBox.h / 2) - 50;

		m_finalScoreBoxOutline.x = m_finalScoreBox.x;
		m_finalScoreBoxOutline.y = m_finalScoreBox.y;
		m_finalScoreBoxOutline.w = m_finalScoreBox.w;
		m_finalScoreBoxOutline.h = m_finalScoreBox.h;

		SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 170);
		SDL_RenderFillRect(game->Renderer, &m_finalScoreBox);
		SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

		SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(game->Renderer, &m_finalScoreBoxOutline);
		SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 170);

		m_HUD.m_ScoreBoard.showFinal();
		m_HUD.setShowing(false);
	}

	drawText();
	drawBall();

	if (!m_paused)
	{
		drawPaddles();
	}
	else
	{
		drawCursor();
	}
}

Paddle* GameplayState::getPaddle()
{
	if (m_collider.CheckCollision(m_paddles[0].getRect(), m_ball.getRect()))
	{
		return &m_paddles[0];
	}

	if (m_collider.CheckCollision(m_paddles[1].getRect(), m_ball.getRect()))
	{
		return &m_paddles[1];
	}

	if (m_collider.CheckCollision(m_paddles[2].getRect(), m_ball.getRect()))
	{
		return &m_paddles[2];
	}

	if (m_collider.CheckCollision(m_paddles[3].getRect(), m_ball.getRect()))
	{
		return &m_paddles[3];
	}

	return nullptr;
}

void GameplayState::checkCollision()
{
	Paddle* paddleHit = getPaddle();
	if (paddleHit == nullptr)
	{
		return;
	}
	else if (paddleHit != nullptr)
	{
		if (paddleHit->isMarked())
		{
			if (Settings::Audio::SoundEffects == 1)
			{
				m_hitBadSound.Play();
			}
		}
		else
		{
			if (Settings::Audio::SoundEffects == 1)
			{
				m_hitSound.Play();
			}
			if (m_bonusProgress <= 540)
			{
				m_bonusProgress += 10;
			}
			else
			{
				m_bonusProgress = 0;
			}
		}

		bool fTopBottom = paddleHit == &m_paddles[0] || paddleHit == &m_paddles[2];

		double dimension = fTopBottom ? paddleHit->getRect().w : paddleHit->getRect().h;

		double dist = fTopBottom ? (m_ball.getRect().x + m_ball.getRect().w / 2) - paddleHit->getRect().x :
			(m_ball.getRect().y + m_ball.getRect().h / 2) - paddleHit->getRect().y;

		double percent = (dist / dimension);

		if (percent > 1)
			percent = 1;
		if (percent < 0)
			percent = 0;

		double angle = 0.0;

		if (paddleHit == &m_paddles[0])
		{
			angle = percent * -1 * M_PI + M_PI;
			m_ball.mPosY = paddleHit->getRect().y + paddleHit->getRect().h + 1;
		}
		else if (paddleHit == &m_paddles[1])
		{
			angle = percent * -1 * M_PI - M_PI / 2;
			m_ball.mPosX = paddleHit->getRect().x - m_ball.getRect().w - 1;
		}
		else if (paddleHit == &m_paddles[2])
		{
			angle = percent * M_PI - M_PI;
			m_ball.mPosY = paddleHit->getRect().y - m_ball.getRect().h - 1;
		}
		else if (paddleHit == &m_paddles[3])
		{
			angle = percent * M_PI - M_PI / 2;
			m_ball.mPosX = paddleHit->getRect().x + paddleHit->getRect().w + 1;
		}

		m_ball.setAngle(angle);

		if (!fTopBottom)
		{
			if (paddleHit->getRect().h >= m_ball.getRect().w && paddleHit->isMarked())
			{
				paddleHit->setRectH(paddleHit->getRect().h - (paddleHit->getRect().h / 16));
				m_health -= 75;
				m_HUD.HP_TEXT_NEEDS_UPDATED = true;

				m_ball.addSpeed(0.02f);
				m_HUD.BALL_SPEED_NEEDS_UPDATED = true;
			}
			else if (paddleHit->getRect().h >= m_ball.getRect().w)
			{
				paddleHit->setRectH(paddleHit->getRect().h - (paddleHit->getRect().h / 20));
				m_health -= 10;
				m_HUD.HP_TEXT_NEEDS_UPDATED = true;

				m_ball.addSpeed(0.01f);
				m_HUD.BALL_SPEED_NEEDS_UPDATED = true;
			}
		}
		else
		{
			if (paddleHit->getRect().w >= m_ball.getRect().w && paddleHit->isMarked())
			{
				paddleHit->setRectW(paddleHit->getRect().w - (paddleHit->getRect().w / 16));
				m_health -= 75;
				m_HUD.HP_TEXT_NEEDS_UPDATED = true;

				m_ball.addSpeed(0.02f);
				m_HUD.BALL_SPEED_NEEDS_UPDATED = true;
			}
			else if (paddleHit->getRect().w >= m_ball.getRect().w)
			{
				paddleHit->setRectW(paddleHit->getRect().w - (paddleHit->getRect().w / 20));
				m_health -= 10;
				m_HUD.HP_TEXT_NEEDS_UPDATED = true;

				m_ball.addSpeed(0.01f);
				m_HUD.BALL_SPEED_NEEDS_UPDATED = true;
			}
		}

		if (m_HUD.m_ScoreBoard.getScore() > 0 && paddleHit->isMarked())
		{
			m_HUD.m_ScoreBoard.decreaseScore(1);
		}
		else if (!paddleHit->isMarked())
		{
			m_HUD.m_ScoreBoard.increaseScore(1);
		}

		if (m_HUD.m_ScoreBoard.getScore() > m_HUD.m_ScoreBoard.getHighScore())
		{
			m_HUD.m_ScoreBoard.recordHighScore();
		}

		paddleHit->setHit(true);
	}
}

void GameplayState::checkforBonus()
{
	if (m_paddles[0].isMarked() && m_paddles[1].isMarked() && m_paddles[2].isMarked() && m_paddles[3].isMarked())
	{
		if (m_health <= 484)
		{
			m_health += 66;
			m_HUD.HP_TEXT_NEEDS_UPDATED = true;
		}
		else
		{
			m_health = 550;
			m_HUD.HP_TEXT_NEEDS_UPDATED = true;
		}

		if (m_bonusProgress <= 500)
		{
			m_bonusProgress += 50;
		}
		else
		{
			m_bonusProgress = 0;
		}

		if (Settings::Audio::SoundEffects == 1)
		{
			m_heal.Play();
		}
		m_HUD.m_ScoreBoard.increaseScore(5);
		m_ball.removeSpeed(0.03f);
		m_HUD.BALL_SPEED_NEEDS_UPDATED = true;

		for (std::size_t i = 0; i < m_paddles.size(); ++i)
		{
			m_paddles[i].Heal();
		}
	}
}

void GameplayState::checkforGameOver()
{
	if (m_health <= 0 || m_ball.getRect().x <= 0 || m_ball.getRect().x > game->screenWidth - m_ball.getRect().w || m_ball.getRect().y < 0 || m_ball.getRect().y > game->screenHeight - m_ball.getRect().h)
	{
		m_health = 0;
		m_HUD.HP_TEXT_NEEDS_UPDATED = true;
		m_bonusProgress = 0;
		if (Settings::Audio::SoundEffects == 1)
		{
			m_gameOverSound.Play();
		}

		m_ball.setDead(true);
		m_paused = true;
		if (m_HUD.m_ScoreBoard.getScore() > m_HUD.m_ScoreBoard.getHighScore())
		{
			m_HUD.m_ScoreBoard.recordHighScore();
		}

		if (m_HUD.m_ScoreBoard.getScore() >= m_HUD.m_ScoreBoard.getLevelScore())
		{
			m_levelWon = true;
		}
		else
		{
			--m_lives;
			m_HUD.LIVES_TEXT_NEEDS_UPDATED = true;
			m_gameOver = true;
		}
	}
}

bool GameplayState::checkforWin()
{
	if (m_HUD.m_ScoreBoard.getScore() >= m_HUD.m_ScoreBoard.getLevelScore())
	{
		m_dungeonLevels.nextLevel();
		m_HUD.LEVEL_NUM_NEEDS_UPDATED = true;

		return true;
	}

	return false;
}

void GameplayState::resetGame()
{
	m_health = 550;
	m_HUD.HP_TEXT_NEEDS_UPDATED = true;
	m_bonusProgress = 0;
	m_ball.resetBall(Settings::GamePlay::Difficulty);

	if (!checkforWin())
	{
		if (m_lives > 0)
		{
			m_dungeonLevels.setLevel(m_dungeonLevels.getLevel());
			m_HUD.LEVEL_NUM_NEEDS_UPDATED = true;
		}
		else
		{
			if (m_dungeonLevels.getLevel() != 0)
			{
				m_dungeonLevels.Unload(m_dungeonLevels.getLevel());
				m_dungeonLevels.setLevel(0);
				m_HUD.LEVEL_NUM_NEEDS_UPDATED = true;
				m_dungeonLevels.Load();
			}
			else
			{
				m_dungeonLevels.setLevel(0);
				m_HUD.LEVEL_NUM_NEEDS_UPDATED = true;
			}

			m_lives = 3;
		}
	}

	m_paddles[0].resetPaddles((game->screenWidth / 2) - (175 / 2), 30, (game->screenWidth / 6.5), 15);
	m_paddles[1].resetPaddles(game->screenWidth - 45, (game->screenHeight / 2) - (175 / 2), 15, (game->screenHeight / 4));
	m_paddles[2].resetPaddles((game->screenWidth / 2) - (175 / 2), game->screenHeight - 45, (game->screenWidth / 6.5), 15);
	m_paddles[3].resetPaddles(30, (game->screenHeight / 2) - (175 / 2), 15, (game->screenHeight / 4));

	m_HUD.m_ScoreBoard.resetScore();
	m_HUD.setShowing(true);

	m_newGame = true;
	m_paused = true;
	m_levelWon = false;
}