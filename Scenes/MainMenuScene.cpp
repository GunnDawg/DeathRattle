#include "MainMenuScene.h"
#include "PreGameplayScene.h"
#include "LeaderboardScene.h"
#include "OptionsMenuScene.h"
#include "CreditsScene.h"
#include "Game.h"

void MainMenuScene::on_enter()
{
	for (size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Load(Game::Renderer, "Assets/Graphics/common/skull3.png");
		m_skulls[i].m_TextureRect.w = 100;
		m_skulls[i].m_TextureRect.h = 100;
		m_skulls[i].m_TextureRect.y = 0;
	}

	m_skulls[0].m_TextureRect.x = 125;
	m_skulls[1].m_TextureRect.x = (Game::screenWidth - m_skulls[1].m_TextureRect.w) - 125;

	m_cursor.Load(Game::Renderer, "Assets/Graphics/common/cursor2.png");
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_title.Load(Game::Renderer, "Assets/Graphics/common/title.png");
	m_title.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = Game::screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_devName.Load(Game::Renderer, "Assets/Graphics/common/dev_name.png");
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_version.Load(Game::Renderer, "Assets/Graphics/common/version.png");
	m_version.m_TextureRect.x = ((Game::screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_background.Load(Game::Renderer, "Assets/Graphics/common/main_background.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_menuBox.w = 400;
	m_menuBox.h = 400;
	m_menuBox.x = (Game::screenWidth / 2) + (m_menuBox.w / 2);
	m_menuBox.y = (Game::screenHeight / 2) - (m_menuBox.h / 2);

	m_menuBoxOutline.w = m_menuBox.w;
	m_menuBoxOutline.h = m_menuBox.h;
	m_menuBoxOutline.x = m_menuBox.x;
	m_menuBoxOutline.y = m_menuBox.y;

	m_newGame.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/new_game.png");

	m_newGameWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/new_game_white.png");

	m_options.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/options.png");

	m_optionsWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/options_white.png");

	m_leaderBoard.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/leaderboard.png");

	m_leaderBoardWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/leaderboard_white.png");

	m_credits.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/credits.png");

	m_creditsWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/credits_white.png");

	m_exit.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/exit.png");

	m_exitWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/exit_white.png");

	m_swoosh.Load("Assets/Audio/swoosh.wav");
	m_swoosh.Play();

	MusicManager::Load();
	if (MusicManager::isMenuMusic)
	{
		MusicManager::Play();
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

	for (size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Unload();
	}

	m_swoosh.Unload();
}

void MainMenuScene::update()
{
	if (m_menuBox.x >= (Game::screenWidth / 2) - (m_menuBox.w / 2))
	{
		m_menuBox.x -= static_cast<int>(1.75 * Game::deltaTime);

		m_newGame.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_newGame.m_TextureRect.w / 2);
		m_newGame.m_TextureRect.y = m_menuBox.y + 25;

		m_newGameWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_newGameWhite.m_TextureRect.w / 2);
		m_newGameWhite.m_TextureRect.y = m_newGame.m_TextureRect.y;

		m_options.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_options.m_TextureRect.w / 2);
		m_options.m_TextureRect.y = m_newGame.m_TextureRect.y + 75;

		m_optionsWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_optionsWhite.m_TextureRect.w / 2);
		m_optionsWhite.m_TextureRect.y = m_options.m_TextureRect.y;

		m_leaderBoard.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_leaderBoard.m_TextureRect.w / 2);
		m_leaderBoard.m_TextureRect.y = m_options.m_TextureRect.y + 65;

		m_leaderBoardWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_leaderBoardWhite.m_TextureRect.w / 2);
		m_leaderBoardWhite.m_TextureRect.y = m_leaderBoard.m_TextureRect.y;

		m_credits.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_credits.m_TextureRect.w / 2);
		m_credits.m_TextureRect.y = m_leaderBoard.m_TextureRect.y + 65;

		m_creditsWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_creditsWhite.m_TextureRect.w / 2);
		m_creditsWhite.m_TextureRect.y = m_credits.m_TextureRect.y;

		m_exit.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_exit.m_TextureRect.w / 2);
		m_exit.m_TextureRect.y = m_credits.m_TextureRect.y + 75;

		m_exitWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_exitWhite.m_TextureRect.w / 2);
		m_exitWhite.m_TextureRect.y = m_exit.m_TextureRect.y;

		m_menuBoxOutline.w = m_menuBox.w;
		m_menuBoxOutline.h = m_menuBox.h;
		m_menuBoxOutline.x = m_menuBox.x;
		m_menuBoxOutline.y = m_menuBox.y;
	}

	if(Game::mouseX >= m_newGame.m_TextureRect.x &&
		Game::mouseX <= m_newGame.m_TextureRect.x + m_newGame.m_TextureRect.w &&
		Game::mouseY >= m_newGame.m_TextureRect.y &&
		Game::mouseY <= m_newGame.m_TextureRect.y + m_newGame.m_TextureRect.h)
	{
		m_isNewGame = true;
	}
	else if (Game::mouseX >= m_options.m_TextureRect.x &&
		Game::mouseX <= m_options.m_TextureRect.x + m_options.m_TextureRect.w &&
		Game::mouseY >= m_options.m_TextureRect.y &&
		Game::mouseY <= m_options.m_TextureRect.y + m_options.m_TextureRect.h)
	{
		m_isOptions = true;
	}
	else if (Game::mouseX >= m_exit.m_TextureRect.x &&
		Game::mouseX <= m_exit.m_TextureRect.x + m_exit.m_TextureRect.w &&
		Game::mouseY >= m_exit.m_TextureRect.y &&
		Game::mouseY <= m_exit.m_TextureRect.y + m_exit.m_TextureRect.h)
	{
		m_isExit = true;
	}
	else if (Game::mouseX >= m_leaderBoard.m_TextureRect.x &&
		Game::mouseX <= m_leaderBoard.m_TextureRect.x + m_leaderBoard.m_TextureRect.w &&
		Game::mouseY >= m_leaderBoard.m_TextureRect.y &&
		Game::mouseY <= m_leaderBoard.m_TextureRect.y + m_leaderBoard.m_TextureRect.h)
	{
		m_isLeaderBoard = true;
	}
	else if (Game::mouseX >= m_credits.m_TextureRect.x &&
		Game::mouseX <= m_credits.m_TextureRect.x + m_credits.m_TextureRect.w &&
		Game::mouseY >= m_credits.m_TextureRect.y &&
		Game::mouseY <= m_credits.m_TextureRect.y + m_credits.m_TextureRect.h)
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

	m_cursor.m_TextureRect.x = Game::mouseX;
	m_cursor.m_TextureRect.y = Game::mouseY;
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
					Game::isRunning = false;
				} break;

				case SDL_MOUSEBUTTONDOWN:
				{
					if (m_isExit)
					{
						Game::gameStateMachine.unloadAll();
						Game::isRunning = false;
					}

					else if (m_isNewGame)
					{
						//Game::gameStateMachine.unloadAll();
						//std::unique_ptr<GameState> gamePlayState = std::make_unique<GameplayState>();
						//Game::gameStateMachine.push(std::move(gamePlayState));

						std::unique_ptr<GameState> preGamePlayState = std::make_unique<PreGameplayScene>();
						Game::gameStateMachine.push(std::move(preGamePlayState));
					}

					else if (m_isLeaderBoard)
					{
						std::unique_ptr<GameState> leaderBoardScene = std::make_unique<LeaderBoardScene>();
						Game::gameStateMachine.push(std::move(leaderBoardScene));
					}

					else if (m_isOptions)
					{
						std::unique_ptr<GameState> optionsMenuScene = std::make_unique<OptionsMenuScene>();
						Game::gameStateMachine.push(std::move(optionsMenuScene));
					}

					else if (m_isCredits)
					{
						std::unique_ptr<GameState> creditsScene = std::make_unique<CreditsScene>();
						Game::gameStateMachine.push(std::move(creditsScene));
					}
				} break;

				case SDL_KEYDOWN:
				{
					switch (evnt.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						{
							Game::isRunning = false;
						} break;

						default:
							break;
					}
				}

				default:
					break;
			}
		}
	}
}

void MainMenuScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 170);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_menuBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);

	if (m_isNewGame)
	{
		SDL_RenderCopy(Game::Renderer, m_newGameWhite.m_Texture, NULL, &m_newGameWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_newGame.m_Texture, NULL, &m_newGame.m_TextureRect);
	}

	if (m_isOptions)
	{
		SDL_RenderCopy(Game::Renderer, m_optionsWhite.m_Texture, NULL, &m_optionsWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_options.m_Texture, NULL, &m_options.m_TextureRect);
	}

	if (m_isLeaderBoard)
	{
		SDL_RenderCopy(Game::Renderer, m_leaderBoardWhite.m_Texture, NULL, &m_leaderBoardWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_leaderBoard.m_Texture, NULL, &m_leaderBoard.m_TextureRect);

	}

	if (m_isCredits)
	{
		SDL_RenderCopy(Game::Renderer, m_creditsWhite.m_Texture, NULL, &m_creditsWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_credits.m_Texture, NULL, &m_credits.m_TextureRect);
	}

	if (m_isExit)
	{
		SDL_RenderCopy(Game::Renderer, m_exitWhite.m_Texture, NULL, &m_exitWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_exit.m_Texture, NULL, &m_exit.m_TextureRect);
	}
	
	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::Renderer, &m_menuBoxOutline);

	SDL_RenderCopyEx(Game::Renderer, m_skulls[0].m_Texture, NULL, &m_skulls[0].m_TextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(Game::Renderer, m_skulls[1].m_Texture, NULL, &m_skulls[1].m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}