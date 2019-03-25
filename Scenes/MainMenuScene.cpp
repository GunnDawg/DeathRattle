#include "MainMenuScene.h"
#include "PreGameplayScene.h"
#include "LeaderboardScene.h"
#include "OptionsMenuScene.h"
#include "CreditsScene.h"
#include "GameplayScene.h"
#include "Game.h"

void MainMenuScene::on_enter()
{
	GUNN_CORE_INFO("----------ENTERING MAIN MENU SCENE----------");

	game = &Game::GetInstance();

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Load();
		m_skulls[i].mTextureRect.w = 100;
		m_skulls[i].mTextureRect.h = 100;
		m_skulls[i].mTextureRect.y = 0;
	}

	m_skulls[0].mTextureRect.x = 125;
	m_skulls[1].mTextureRect.x = (game->screenWidth - m_skulls[1].mTextureRect.w) - 125;

	m_cursor.Load();
	m_cursor.mTextureRect.w = 48;
	m_cursor.mTextureRect.h = 48;

	m_title.Load();
	m_title.mTextureRect.x = (game->screenWidth / 2) - (m_title.mTextureRect.w / 2);
	m_title.mTextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.mTextureRect.y;
	m_titleBox.w = game->screenWidth;
	m_titleBox.h = m_title.mTextureRect.h;

	m_devName.Load();
	m_devName.mTextureRect.x = (game->screenWidth / 2) - (m_devName.mTextureRect.w / 2);
	m_devName.mTextureRect.y = (game->screenHeight - m_devName.mTextureRect.h);

	m_devNameBox.h = m_devName.mTextureRect.h;
	m_devNameBox.w = game->screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.mTextureRect.y;

	m_version.Load();
	m_version.mTextureRect.x = ((game->screenWidth - m_version.mTextureRect.w));
	m_version.mTextureRect.y = (game->screenHeight - m_version.mTextureRect.h);

	m_background.Load();
	m_background.mTextureRect.x = 0;
	m_background.mTextureRect.y = 0;
	m_background.mTextureRect.w = game->screenWidth;
	m_background.mTextureRect.h = game->screenHeight;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_menuBox.w = 400;
	m_menuBox.h = 400;
	m_menuBox.x = (game->screenWidth / 2) - (m_menuBox.w / 2);
	m_menuBox.y = (game->screenHeight / 2) - (m_menuBox.h / 2);

	m_menuBoxOutline.w = m_menuBox.w;
	m_menuBoxOutline.h = m_menuBox.h;
	m_menuBoxOutline.x = m_menuBox.x;
	m_menuBoxOutline.y = m_menuBox.y;

	m_newGame.Load();
	m_newGameWhite.Load();

	m_options.Load();
	m_optionsWhite.Load();

	m_leaderBoard.Load();
	m_leaderBoardWhite.Load();

	m_credits.Load();
	m_creditsWhite.Load();

	m_exit.Load();
	m_exitWhite.Load();

	m_newGame.mTextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_newGame.mTextureRect.w / 2);
	m_newGame.mTextureRect.y = m_menuBox.y + 25;

	m_newGameWhite.mTextureRect.x = m_newGame.mTextureRect.x;
	m_newGameWhite.mTextureRect.y = m_newGame.mTextureRect.y;

	m_options.mTextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_options.mTextureRect.w / 2);
	m_options.mTextureRect.y = m_newGame.mTextureRect.y + 75;

	m_optionsWhite.mTextureRect.x = m_options.mTextureRect.x;
	m_optionsWhite.mTextureRect.y = m_options.mTextureRect.y;

	m_leaderBoard.mTextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_leaderBoard.mTextureRect.w / 2);
	m_leaderBoard.mTextureRect.y = m_options.mTextureRect.y + 65;

	m_leaderBoardWhite.mTextureRect.x = m_leaderBoard.mTextureRect.x;
	m_leaderBoardWhite.mTextureRect.y = m_leaderBoard.mTextureRect.y;

	m_credits.mTextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_credits.mTextureRect.w / 2);
	m_credits.mTextureRect.y = m_leaderBoard.mTextureRect.y + 65;

	m_creditsWhite.mTextureRect.x = m_credits.mTextureRect.x;
	m_creditsWhite.mTextureRect.y = m_credits.mTextureRect.y;

	m_exit.mTextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_exit.mTextureRect.w / 2);
	m_exit.mTextureRect.y = m_credits.mTextureRect.y + 95;

	m_exitWhite.mTextureRect.x = m_exit.mTextureRect.x;
	m_exitWhite.mTextureRect.y = m_exit.mTextureRect.y;

	if (Settings::Audio::MenuMusic == 1)
	{
		JukeBox->Load(JukeBox->MenuMusic);
		JukeBox->Setvolume(JukeBox->MenuMusic, 1.5);
		JukeBox->Play(JukeBox->MenuMusic);
	}
}

void MainMenuScene::on_exit()
{
	m_cursor.Unload();
	m_background.Unload();
	m_title.Unload();

	m_newGame.Unload();
	m_newGameWhite.Unload();

	m_options.Unload();
	m_optionsWhite.Unload();

	m_leaderBoard.Unload();
	m_leaderBoardWhite.Unload();

	m_credits.Unload();
	m_creditsWhite.Unload();

	m_exit.Unload();
	m_exitWhite.Unload();

	m_devName.Unload();
	m_version.Unload();

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Unload();
	}

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	game = nullptr;
	JukeBox = nullptr;
}

void MainMenuScene::update()
{
	if(game->mouseX >= m_newGame.mTextureRect.x &&
		game->mouseX <= m_newGame.mTextureRect.x + m_newGame.mTextureRect.w &&
		game->mouseY >= m_newGame.mTextureRect.y &&
		game->mouseY <= m_newGame.mTextureRect.y + m_newGame.mTextureRect.h)
	{
		m_isNewGame = true;
	}
	else if (game->mouseX >= m_options.mTextureRect.x &&
		game->mouseX <= m_options.mTextureRect.x + m_options.mTextureRect.w &&
		game->mouseY >= m_options.mTextureRect.y &&
		game->mouseY <= m_options.mTextureRect.y + m_options.mTextureRect.h)
	{
		m_isOptions = true;
	}
	else if (game->mouseX >= m_exit.mTextureRect.x &&
		game->mouseX <= m_exit.mTextureRect.x + m_exit.mTextureRect.w &&
		game->mouseY >= m_exit.mTextureRect.y &&
		game->mouseY <= m_exit.mTextureRect.y + m_exit.mTextureRect.h)
	{
		m_isExit = true;
	}
	else if (game->mouseX >= m_leaderBoard.mTextureRect.x &&
		game->mouseX <= m_leaderBoard.mTextureRect.x + m_leaderBoard.mTextureRect.w &&
		game->mouseY >= m_leaderBoard.mTextureRect.y &&
		game->mouseY <= m_leaderBoard.mTextureRect.y + m_leaderBoard.mTextureRect.h)
	{
		m_isLeaderBoard = true;
	}
	else if (game->mouseX >= m_credits.mTextureRect.x &&
		game->mouseX <= m_credits.mTextureRect.x + m_credits.mTextureRect.w &&
		game->mouseY >= m_credits.mTextureRect.y &&
		game->mouseY <= m_credits.mTextureRect.y + m_credits.mTextureRect.h)
	{
		m_isCredits = true;
	}
	else
	{
		m_isNewGame = false;
		m_isOptions = false;
		m_isLeaderBoard = false;
		m_isCredits = false;
		m_isExit = false;
	}

	m_cursor.setRect(game->mouseX, game->mouseY);
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
	}
}

void MainMenuScene::handle_events()
{
	SDL_Event evnt;
	{
		while (SDL_PollEvent(&evnt))
		{
			switch (evnt.type)
			{
				case SDL_QUIT:
				{
					game->isRunning = false;
				} break;

				case SDL_MOUSEBUTTONDOWN:
				{
					if (m_isExit)
					{
						game->isRunning = false;
						game->gameStateMachine.unloadAll();
					}

					else if (m_isNewGame)
					{
						if (Settings::Audio::MenuMusic == 1)
						{
							JukeBox->Stop(JukeBox->MenuMusic);
						}

						m_isNewGame = false;
						game->gameStateMachine.unloadAll();
						std::unique_ptr<GameState> gamePlayState = std::make_unique<GameplayState>();
						game->gameStateMachine.push(std::move(gamePlayState));

						//std::unique_ptr<GameState> preGamePlayState = std::make_unique<PreGameplayScene>();
						//Game::gameStateMachine.push(std::move(preGamePlayState));
					}

					else if (m_isLeaderBoard)
					{
						m_isLeaderBoard = false;
						std::unique_ptr<GameState> leaderBoardScene = std::make_unique<LeaderBoardScene>();
						game->gameStateMachine.push(std::move(leaderBoardScene));
					}

					else if (m_isOptions)
					{
						m_isOptions = false;
						std::unique_ptr<GameState> optionsMenuScene = std::make_unique<OptionsMenuScene>();
						game->gameStateMachine.push(std::move(optionsMenuScene));
					}

					else if (m_isCredits)
					{
						m_isCredits = false;
						std::unique_ptr<GameState> creditsScene = std::make_unique<CreditsScene>();
						game->gameStateMachine.push(std::move(creditsScene));
					}
				} break;

				case SDL_KEYDOWN:
				{
					switch (evnt.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						{
							game->isRunning = false;
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
}

void MainMenuScene::draw()
{
	SDL_RenderCopy(game->Renderer, m_background.mTexture, NULL, &m_background.mTextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 170);
	SDL_RenderFillRect(game->Renderer, &m_titleBox);
	SDL_RenderFillRect(game->Renderer, &m_devNameBox);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_menuBox);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);

	if (m_isNewGame)
	{
		SDL_RenderCopy(game->Renderer, m_newGameWhite.mTexture, NULL, &m_newGameWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_newGame.mTexture, NULL, &m_newGame.mTextureRect);
	}

	if (m_isOptions)
	{
		SDL_RenderCopy(game->Renderer, m_optionsWhite.mTexture, NULL, &m_optionsWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_options.mTexture, NULL, &m_options.mTextureRect);
	}

	if (m_isLeaderBoard)
	{
		SDL_RenderCopy(game->Renderer, m_leaderBoardWhite.mTexture, NULL, &m_leaderBoardWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_leaderBoard.mTexture, NULL, &m_leaderBoard.mTextureRect);

	}

	if (m_isCredits)
	{
		SDL_RenderCopy(game->Renderer, m_creditsWhite.mTexture, NULL, &m_creditsWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_credits.mTexture, NULL, &m_credits.mTextureRect);
	}

	if (m_isExit)
	{
		SDL_RenderCopy(game->Renderer, m_exitWhite.mTexture, NULL, &m_exitWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_exit.mTexture, NULL, &m_exit.mTextureRect);
	}
	
	SDL_RenderCopy(game->Renderer, m_devName.mTexture, NULL, &m_devName.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_version.mTexture, NULL, &m_version.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_title.mTexture, NULL, &m_title.mTextureRect);

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(game->Renderer, &m_menuBoxOutline);

	SDL_RenderCopyEx(game->Renderer, m_skulls[0].mTexture, NULL, &m_skulls[0].mTextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(game->Renderer, m_skulls[1].mTexture, NULL, &m_skulls[1].mTextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.mTexture, NULL, &m_cursor.mTextureRect);
}