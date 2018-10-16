#include "GameplayScene.h"
#include "Game.h"

void GameplayState::on_enter()
{
	printf("<-----LOADING GAME--------->\n");

	m_mouse.On();

	m_cursor.Load("Assets/Graphics/common/cursor2.png");
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	//Define Drops
	//m_items[0] = std::make_unique<Item>(Type::DamagePaddles);
	//m_items[1] = std::make_unique<Item>(Type::SwapPaddles);
	//m_items[2] = std::make_unique<Item>(Type::IncreaseSpeed);
	//m_items[3] = std::make_unique<Item>(Type::DecreaseSpeed);
	//m_items[4] = std::make_unique<Item>(Type::Health);

	//Define Level Object
	m_dungeonLevels = LevelSet("Assets/Graphics/Levels/Dungeon/", Game::screenWidth, Game::screenHeight);

	//Define paddles
	m_paddles[0] = std::make_unique<Paddle>((Game::screenWidth / 6.5), 15, (Game::screenWidth / 2) - (175 / 2), 30);
	m_paddles[1] = std::make_unique<Paddle>(15, (Game::screenHeight / 4), Game::screenWidth - 45, (Game::screenHeight / 2) - (175 / 2));
	m_paddles[2] = std::make_unique<Paddle>((Game::screenWidth / 6.5), 15, (Game::screenWidth / 2) - (175 / 2), Game::screenHeight - 45);
	m_paddles[3] = std::make_unique<Paddle>(15, (Game::screenHeight / 4), 30, (Game::screenHeight / 2) - (175 / 2));

	//Define ball
	m_ball = std::make_unique<Ball>(Game::screenWidth, Game::screenHeight, m_difficulty);

	//TODO: Rewrite the text class entirely, this is shit (Calvin)
	//Define text components
	m_gameTitle            = std::make_unique<Text>(48, "KEEP IT ALIVE");
	m_gameTitleStart       = std::make_unique<Text>(12, "Press SPACE to start or ESC to exit");
	m_pausedText           = std::make_unique<Text>(48, "PAUSED");
	m_pressSpaceText       = std::make_unique<Text>(12, "Press SPACE to continue");
	m_gameOverText         = std::make_unique<Text>(48, "GAME OVER");
	m_gameOverNewGameText  = std::make_unique<Text>(12, "Press N to start a new game or ESC to exit");
	m_levelPassed          = std::make_unique<Text>(48, "LEVEL COMPLETE");
	m_levelPassedContinue  = std::make_unique<Text>(12, "Press N to continue to the next level");

	//m_gameTitle           = Text(48, "KEEP IT ALIVE");
	//m_gameTitleStart      = Text(m_renderer, 12, "Press SPACE to start or ESC to exit");
	//m_pausedText          = Text(m_renderer, 48, "PAUSED");
	//m_pressSpaceText      = Text(m_renderer, 12, "Press SPACE to continue");
	//m_gameOverText        = Text(m_renderer, 48, "GAME OVER");
	//m_gameOverNewGameText = Text(m_renderer, 12, "Press N to start a new game or ESC to exit");
	//m_levelPassed         = Text(m_renderer, 48, "LEVEL COMPLETE");
	//m_levelPassedContinue = Text(m_renderer, 12, "Press N to continue to the next level");

	//Define misc. graphical components
	m_dead.Load("Assets/Graphics/gameplay_scene/gameover.png");
	m_dead.setRect((Game::screenWidth / 2) - (m_dead.m_TextureRect.w / 2), Game::screenHeight - m_dead.m_TextureRect.h, m_dead.m_TextureRect.w, m_dead.m_TextureRect.h);
	m_ball->Load();

	//Define audio components
	m_hitSound = Sound("Assets/Sounds/hitnormal.wav");
	m_hitBadSound = Sound("Assets/Sounds/hitbad.wav");
	m_pauseSound = Sound("Assets/Sounds/pause.wav");
	m_gameOverSound = Sound("Assets/Sounds/gameover.wav");
	m_heal = Sound("Assets/Sounds/heal.wav");

	//Load HUD
	m_HUD.Load(m_health, true);

	//Load Items
	//for (size_t i = 0; i < m_items.size(); ++i)
	//{
	//	m_items[i]->Load(Game::Renderer);
	//}

	//Load Level Sets
	if (m_cached)
	{
		m_dungeonLevels.LoadAll();
	}
	else
	{
		m_dungeonLevels.Load();
	}

	m_dungeonLevels.setScores({ 10, 50, 175, 250, 300 });

	//Load all audio
	m_hitSound.Load("Assets/Audio/hitnormal.wav");
	m_hitBadSound.Load("Assets/Audio/hitbad.wav");
	m_pauseSound.Load("Assets/Audio/pause.wav");
	m_gameOverSound.Load("Assets/Audio/gameover.wav");
	m_heal.Load("Assets/Audio/heal.wav");
	m_heal.setVolume(4);

	m_running = true;
}

void GameplayState::on_exit()
{
	
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
			Game::isRunning = false;
		} break;

		//TODO: Consider a key input manager if needed, might not be (Calvin)
		case SDL_KEYDOWN:
		{
			switch (evnt.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			{
				Game::isRunning = false;
			} break;

			case SDLK_SPACE:
			{
				if (!m_paused)
				{
					Mix_PauseMusic();
					m_paused = true;
					m_pauseSound.Play();
				}
				else if (m_levelWon)
				{
					m_paused = true;
				}
				else if (m_paused && !m_gameOver)
				{
					if (!MusicManager::isGamePlayMusic)
					{
						Mix_PausedMusic();
					}
					m_paused = false;
					m_pauseSound.Play();
				}

				if (!m_keyBoard.isEnabled() && !m_mouse.isEnabled())
				{
					printf("No input devices enabled. Enable either the mouse or the keyboard!\n");
					m_paused = true;
				}
				else if (m_newGame)
				{
					m_newGame = false;
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
	SDL_GetMouseState(&m_mouseX, &m_mouseY);

	m_cursor.setRect(m_mouseX, m_mouseY, 48, 48);

	if (m_health <= 0)
	{
		m_health = 0;
	}

	m_HUD.Update(m_dungeonLevels, *m_ball, m_lives, m_health, m_bonusProgress);

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
			m_mouse.Update(m_paddles[0].get(), m_paddles[1].get(), m_paddles[2].get(), m_paddles[3].get());
		}
		else if (m_keyBoard.isEnabled())
		{
			m_keyBoard.Update(Game::deltaTime, 75, Game::screenWidth, Game::screenHeight, *m_paddles[0], *m_paddles[1], *m_paddles[2], *m_paddles[3]);
		}

		m_HUD.Update(m_dungeonLevels, *m_ball, m_lives, m_health, m_bonusProgress);

		if (!m_paused)
		{
			m_ball->Update();
		}

		checkforGameOver();
		checkCollision();
		checkforBonus();
	}

	//if (!MusicManager::isGamePlayMusic)
	//{
	//	MusicManager::
	//}
}

void GameplayState::drawCursor()
{
	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}

void GameplayState::drawLevel()
{
	m_dungeonLevels.Draw();
}

void GameplayState::drawPaddles()
{
	for (size_t i = 0; i < m_paddles.size(); ++i)
	{
		m_paddles[i]->Draw();
	}
}

void GameplayState::drawBall()
{
	m_ball->Draw();
}

//TODO: Really need a game state manager to avoid this kind of code
void GameplayState::drawText()
{
	if (m_HUD.isShowing())
	{
		m_HUD.Draw();
	}

	if (m_gameOver)
	{
		SDL_Rect rect = m_dead.m_TextureRect;
		SDL_RenderCopy(Game::Renderer, m_dead.getTexture(), nullptr, &rect);
		m_gameOverText->Draw((Game::screenWidth / 2) - 216, (Game::screenHeight / 2) - 150);
		m_gameOverNewGameText->Draw((Game::screenWidth / 2) - 225, (Game::screenHeight / 2) - 90);
	}

	else if (m_levelWon)
	{
		m_levelPassed->Draw((Game::screenWidth / 2) - 336, (Game::screenHeight / 2) - 150);
		m_levelPassedContinue->Draw((Game::screenWidth / 2) - 222, (Game::screenHeight / 2) - 90);
	}

	else if (m_paused && !m_newGame)
	{
		m_pausedText->Draw((Game::screenWidth / 2) - 144, (Game::screenHeight / 2) - 150);
		m_pressSpaceText->Draw((Game::screenWidth / 2) - 130, (Game::screenHeight / 2) - 90);
	}

	else if (m_paused && m_newGame)
	{
		m_gameTitle->Draw((Game::screenWidth / 2) - 255, (Game::screenHeight / 2) - 150);
		m_gameTitleStart->Draw((Game::screenWidth / 2) - 185, (Game::screenHeight / 2) - 90);
	}
}

void GameplayState::draw()
{
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 255);
	
	drawLevel();
	drawText();

	if (m_gameOver || m_levelWon)
	{
		m_HUD.m_ScoreBoard->showFinal();
	}

	drawBall();

	if (!m_paused)
	{
		drawPaddles();
	}
	else
	{
		drawCursor();
	}

	if (m_bonusProgress >= 550)
	{
		//drawItems();
	}

}

Paddle* GameplayState::getPaddle()
{
	if (m_collider.CheckCollision(m_paddles[0]->getRect(), m_ball->getRect()))
	{
		return(m_paddles[0].get());
	}

	if (m_collider.CheckCollision(m_paddles[1]->getRect(), m_ball->getRect()))
	{
		return(m_paddles[1].get());
	}

	if (m_collider.CheckCollision(m_paddles[2]->getRect(), m_ball->getRect()))
	{
		return(m_paddles[2].get());
	}

	if (m_collider.CheckCollision(m_paddles[3]->getRect(), m_ball->getRect()))
	{
		return(m_paddles[3].get());
	}

	return(nullptr);
}

void GameplayState::checkCollision()
{
	Paddle* paddleHit = getPaddle();

	if (paddleHit == nullptr)
	{
		return;
	}

	if (paddleHit->isMarked())
		m_hitBadSound.Play();
	else
	{
		m_hitSound.Play();
		if (m_bonusProgress <= 540)
		{
			m_bonusProgress += 10;
		}
		else
		{
			m_bonusProgress = 0;
			//spawnItem();
		}
	}

	bool fTopBottom = paddleHit == m_paddles[0].get() || paddleHit == m_paddles[2].get(); /*||
					  paddleHit == m_levelPaddles[0].get() || paddleHit == m_levelPaddles[2].get();*/

	double dimension = fTopBottom ? paddleHit->getRect().w : paddleHit->getRect().h;

	double dist = fTopBottom ? (m_ball->getRect().x + m_ball->getRect().w / 2) - paddleHit->getRect().x :
		(m_ball->getRect().y + m_ball->getRect().h / 2) - paddleHit->getRect().y;

	double percent = static_cast<double>(dist / dimension);

	if (percent > 1)
		percent = 1;
	if (percent < 0)
		percent = 0;

	double angle = 0.0f;

	if (paddleHit == m_paddles[0].get())
	{
		angle = percent * -1 * M_PI + M_PI;
		m_ball->m_posY = paddleHit->getRect().y + paddleHit->getRect().h + 1;
	}
	else if (paddleHit == m_paddles[1].get())
	{
		angle = percent * -1 * M_PI - M_PI / 2;
		m_ball->m_posX = paddleHit->getRect().x - m_ball->getRect().w - 1;
	}
	else if (paddleHit == m_paddles[2].get())
	{
		angle = percent * M_PI - M_PI;
		m_ball->m_posY = paddleHit->getRect().y - m_ball->getRect().h - 1;
	}
	else if (paddleHit == m_paddles[3].get())
	{
		angle = percent * M_PI - M_PI / 2;
		m_ball->m_posX = paddleHit->getRect().x + paddleHit->getRect().w + 1;
	}

	m_ball->setAngle(angle);

	if (!fTopBottom)
	{
		if (paddleHit->getRect().h >= m_ball->getRect().w && paddleHit->isMarked())
		{
			//Default was "5"
			paddleHit->setRectH(paddleHit->getRect().h - (paddleHit->getRect().h / 16));
			m_health -= 75;
			m_ball->addSpeed(0.02f);
		}
		else if (paddleHit->getRect().h >= m_ball->getRect().w)
		{
			//Default was "2"
			paddleHit->setRectH(paddleHit->getRect().h - (paddleHit->getRect().h / 20));
			m_health -= 10;
			m_ball->addSpeed(0.01f);
		}
	}
	else
	{
		if (paddleHit->getRect().w >= m_ball->getRect().w && paddleHit->isMarked())
		{
			paddleHit->setRectW(paddleHit->getRect().w - (paddleHit->getRect().w / 16));
			m_health -= 75;
			m_ball->addSpeed(0.02f);
		}
		else if (paddleHit->getRect().w >= m_ball->getRect().w)
		{
			paddleHit->setRectW(paddleHit->getRect().w - (paddleHit->getRect().w / 20));
			m_health -= 10;
			m_ball->addSpeed(0.01f);
		}
	}

	if (m_HUD.m_ScoreBoard->getScore() > 0 && paddleHit->isMarked())
	{
		m_HUD.m_ScoreBoard->decreaseScore(1);
	}
	else if (!paddleHit->isMarked())
	{
		m_HUD.m_ScoreBoard->increaseScore(1);
	}

	paddleHit->setHit(true);
}

void GameplayState::checkforBonus()
{
	if (m_paddles[0]->isMarked() && m_paddles[1]->isMarked() && m_paddles[2]->isMarked() && m_paddles[3]->isMarked())
	{
		if (m_health <= 484)
		{
			m_health += 66;
		}
		else
		{
			m_health = 550;
		}

		if (m_bonusProgress <= 500)
		{
			m_bonusProgress += 50;
		}
		else
		{
			m_bonusProgress = 0;
			//spawnItem();
		}

		m_heal.Play();
		m_HUD.m_ScoreBoard->increaseScore(5);
		m_ball->removeSpeed(0.03f);

		for (size_t i = 0; i < m_paddles.size(); ++i)
		{
			m_paddles[i]->Heal();
		}
	}
}

void GameplayState::checkforGameOver()
{
	if (m_health <= 0 || m_ball->getRect().x <= 0 || m_ball->getRect().x > Game::screenWidth - m_ball->getRect().w || m_ball->getRect().y < 0 || m_ball->getRect().y > Game::screenHeight - m_ball->getRect().h)
	{
		//m_bgMusic.Stop();
		m_health = 0;
		m_bonusProgress = 0;
		m_gameOverSound.Play();

		m_ball->setDead(true);
		m_paused = true;
		if (m_HUD.m_ScoreBoard->getScore() > m_HUD.m_ScoreBoard->getHighScore())
		{
			m_HUD.m_ScoreBoard->recordHighScore();
		}

		if (m_HUD.m_ScoreBoard->getScore() >= m_HUD.m_ScoreBoard->getLevelScore())
		{
			m_levelWon = true;
		}
		else
		{
			--m_lives;
			m_gameOver = true;
		}
	}
}

bool GameplayState::checkforWin()
{
	if (m_HUD.m_ScoreBoard->getScore() >= m_HUD.m_ScoreBoard->getLevelScore())
	{
		m_dungeonLevels.nextLevel(m_cached);

		return(true);
	}

	return(false);
}

void GameplayState::resetGame()
{
	m_health = 550;
	m_bonusProgress = 0;
	m_ball->resetBall(Game::screenWidth, Game::screenHeight, m_difficulty);

	if (!checkforWin())
	{
		if (m_lives > 0)
		{
			m_dungeonLevels.setLevel(m_dungeonLevels.getLevel());
		}
		else
		{
			if (!m_cached && m_dungeonLevels.getLevel() != 0)
			{
				m_dungeonLevels.Unload(m_dungeonLevels.getLevel());
				m_dungeonLevels.setLevel(0);
				m_dungeonLevels.Load();
			}
			else
			{
				m_dungeonLevels.setLevel(0);
			}

			m_lives = 3;
		}
	}

	m_paddles[0]->resetPaddles((Game::screenWidth / 2) - (175 / 2), 30, (Game::screenWidth / 6.5), 15);
	m_paddles[1]->resetPaddles(Game::screenWidth - 45, (Game::screenHeight / 2) - (175 / 2), 15, (Game::screenHeight / 4));
	m_paddles[2]->resetPaddles((Game::screenWidth / 2) - (175 / 2), Game::screenHeight - 45, (Game::screenWidth / 6.5), 15);
	m_paddles[3]->resetPaddles(30, (Game::screenHeight / 2) - (175 / 2), 15, (Game::screenHeight / 4));

	m_HUD.m_ScoreBoard->setScore(0);

	//m_bgMusic.Play();

	m_newGame = true;
	m_paused = true;
	m_levelWon = false;
}