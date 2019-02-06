#include "MainMenuScene.h"
#include "PreGameplayScene.h"
#include "LeaderboardScene.h"
#include "OptionsMenuScene.h"
#include "CreditsScene.h"
#include "GameplayScene.h"
#include "Game.h"

void MainMenuScene::on_enter()
{
	game = &Game::GetInstance();

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Load();
		m_skulls[i].m_TextureRect.w = 100;
		m_skulls[i].m_TextureRect.h = 100;
		m_skulls[i].m_TextureRect.y = 0;
	}

	m_skulls[0].m_TextureRect.x = 125;
	m_skulls[1].m_TextureRect.x = (game->screenWidth - m_skulls[1].m_TextureRect.w) - 125;

	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_title.Load();
	m_title.m_TextureRect.x = (game->screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = game->screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_devName.Load();
	m_devName.m_TextureRect.x = (game->screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (game->screenHeight - m_devName.m_TextureRect.h);

	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.w = game->screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_version.Load();
	m_version.m_TextureRect.x = ((game->screenWidth - m_version.m_TextureRect.w));
	m_version.m_TextureRect.y = (game->screenHeight - m_version.m_TextureRect.h);

	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = game->screenWidth;
	m_background.m_TextureRect.h = game->screenHeight;

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

	m_newGame.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_newGame.m_TextureRect.w / 2);
	m_newGame.m_TextureRect.y = m_menuBox.y + 25;

	m_newGameWhite.m_TextureRect.x = m_newGame.m_TextureRect.x;
	m_newGameWhite.m_TextureRect.y = m_newGame.m_TextureRect.y;

	m_options.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_options.m_TextureRect.w / 2);
	m_options.m_TextureRect.y = m_newGame.m_TextureRect.y + 75;

	m_optionsWhite.m_TextureRect.x = m_options.m_TextureRect.x;
	m_optionsWhite.m_TextureRect.y = m_options.m_TextureRect.y;

	m_leaderBoard.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_leaderBoard.m_TextureRect.w / 2);
	m_leaderBoard.m_TextureRect.y = m_options.m_TextureRect.y + 65;

	m_leaderBoardWhite.m_TextureRect.x = m_leaderBoard.m_TextureRect.x;
	m_leaderBoardWhite.m_TextureRect.y = m_leaderBoard.m_TextureRect.y;

	m_credits.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_credits.m_TextureRect.w / 2);
	m_credits.m_TextureRect.y = m_leaderBoard.m_TextureRect.y + 65;

	m_creditsWhite.m_TextureRect.x = m_credits.m_TextureRect.x;
	m_creditsWhite.m_TextureRect.y = m_credits.m_TextureRect.y;

	m_exit.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_exit.m_TextureRect.w / 2);
	m_exit.m_TextureRect.y = m_credits.m_TextureRect.y + 75;

	m_exitWhite.m_TextureRect.x = m_exit.m_TextureRect.x;
	m_exitWhite.m_TextureRect.y = m_exit.m_TextureRect.y;

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
}

void MainMenuScene::update()
{
	if(game->mouseX >= m_newGame.m_TextureRect.x &&
		game->mouseX <= m_newGame.m_TextureRect.x + m_newGame.m_TextureRect.w &&
		game->mouseY >= m_newGame.m_TextureRect.y &&
		game->mouseY <= m_newGame.m_TextureRect.y + m_newGame.m_TextureRect.h)
	{
		m_isNewGame = true;
	}
	else if (game->mouseX >= m_options.m_TextureRect.x &&
		game->mouseX <= m_options.m_TextureRect.x + m_options.m_TextureRect.w &&
		game->mouseY >= m_options.m_TextureRect.y &&
		game->mouseY <= m_options.m_TextureRect.y + m_options.m_TextureRect.h)
	{
		m_isOptions = true;
	}
	else if (game->mouseX >= m_exit.m_TextureRect.x &&
		game->mouseX <= m_exit.m_TextureRect.x + m_exit.m_TextureRect.w &&
		game->mouseY >= m_exit.m_TextureRect.y &&
		game->mouseY <= m_exit.m_TextureRect.y + m_exit.m_TextureRect.h)
	{
		m_isExit = true;
	}
	else if (game->mouseX >= m_leaderBoard.m_TextureRect.x &&
		game->mouseX <= m_leaderBoard.m_TextureRect.x + m_leaderBoard.m_TextureRect.w &&
		game->mouseY >= m_leaderBoard.m_TextureRect.y &&
		game->mouseY <= m_leaderBoard.m_TextureRect.y + m_leaderBoard.m_TextureRect.h)
	{
		m_isLeaderBoard = true;
	}
	else if (game->mouseX >= m_credits.m_TextureRect.x &&
		game->mouseX <= m_credits.m_TextureRect.x + m_credits.m_TextureRect.w &&
		game->mouseY >= m_credits.m_TextureRect.y &&
		game->mouseY <= m_credits.m_TextureRect.y + m_credits.m_TextureRect.h)
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

						game->gameStateMachine.unloadAll();
						std::unique_ptr<GameState> gamePlayState = std::make_unique<GameplayState>();
						game->gameStateMachine.push(std::move(gamePlayState));

						//m_isNewGame = false;
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
	SDL_RenderCopy(game->Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

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
		SDL_RenderCopy(game->Renderer, m_newGameWhite.m_Texture, NULL, &m_newGameWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_newGame.m_Texture, NULL, &m_newGame.m_TextureRect);
	}

	if (m_isOptions)
	{
		SDL_RenderCopy(game->Renderer, m_optionsWhite.m_Texture, NULL, &m_optionsWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_options.m_Texture, NULL, &m_options.m_TextureRect);
	}

	if (m_isLeaderBoard)
	{
		SDL_RenderCopy(game->Renderer, m_leaderBoardWhite.m_Texture, NULL, &m_leaderBoardWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_leaderBoard.m_Texture, NULL, &m_leaderBoard.m_TextureRect);

	}

	if (m_isCredits)
	{
		SDL_RenderCopy(game->Renderer, m_creditsWhite.m_Texture, NULL, &m_creditsWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_credits.m_Texture, NULL, &m_credits.m_TextureRect);
	}

	if (m_isExit)
	{
		SDL_RenderCopy(game->Renderer, m_exitWhite.m_Texture, NULL, &m_exitWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_exit.m_Texture, NULL, &m_exit.m_TextureRect);
	}
	
	SDL_RenderCopy(game->Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(game->Renderer, &m_menuBoxOutline);

	SDL_RenderCopyEx(game->Renderer, m_skulls[0].m_Texture, NULL, &m_skulls[0].m_TextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(game->Renderer, m_skulls[1].m_Texture, NULL, &m_skulls[1].m_TextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}