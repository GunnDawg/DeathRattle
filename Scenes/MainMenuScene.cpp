#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "LeaderboardScene.h"
#include "OptionsMenuScene.h"
#include "../Managers/AssetManager.h"
#include "../Game.h"

void MainMenuScene::on_enter()
{
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
	m_menuBox.x = (Game::screenWidth / 2) - (m_menuBox.w / 2);
	m_menuBox.y = (Game::screenHeight / 2) - (m_menuBox.h / 2);

	m_menuBoxOutline.w = m_menuBox.w;
	m_menuBoxOutline.h = m_menuBox.h;
	m_menuBoxOutline.x = m_menuBox.x;
	m_menuBoxOutline.y = m_menuBox.y;

	m_newGame.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/new_game.png");
	m_newGame.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_newGame.m_TextureRect.w / 2);
	m_newGame.m_TextureRect.y = m_menuBox.y + 25;

	m_newGameWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/new_game_white.png");
	m_newGameWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_newGameWhite.m_TextureRect.w / 2);
	m_newGameWhite.m_TextureRect.y = m_menuBox.y + 25;

	m_options.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/options.png");
	m_options.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_options.m_TextureRect.w / 2);
	m_options.m_TextureRect.y = m_newGame.m_TextureRect.y + 75;

	m_optionsWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/options_white.png");
	m_optionsWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_optionsWhite.m_TextureRect.w / 2);
	m_optionsWhite.m_TextureRect.y = m_newGame.m_TextureRect.y + 75;

	m_leaderBoard.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/leaderboard.png");
	m_leaderBoard.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_leaderBoard.m_TextureRect.w / 2);
	m_leaderBoard.m_TextureRect.y = m_options.m_TextureRect.y + 75;

	m_leaderBoardWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/leaderboard_white.png");
	m_leaderBoardWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_leaderBoardWhite.m_TextureRect.w / 2);
	m_leaderBoardWhite.m_TextureRect.y = m_options.m_TextureRect.y + 75;

	m_credits.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/credits.png");
	m_credits.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_credits.m_TextureRect.w / 2);
	m_credits.m_TextureRect.y = m_leaderBoard.m_TextureRect.y + 75;

	m_creditsWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/credits_white.png");
	m_creditsWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_creditsWhite.m_TextureRect.w / 2);
	m_creditsWhite.m_TextureRect.y = m_leaderBoard.m_TextureRect.y + 75;

	m_exit.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/exit.png");
	m_exit.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_exit.m_TextureRect.w / 2);
	m_exit.m_TextureRect.y = m_credits.m_TextureRect.y + 75;

	m_exitWhite.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/exit_white.png");
	m_exitWhite.m_TextureRect.x = m_menuBox.x + ((m_menuBox.w / 2) - m_exitWhite.m_TextureRect.w / 2);
	m_exitWhite.m_TextureRect.y = m_credits.m_TextureRect.y + 75;

	m_hoverSound.Load("Assets/Audio/menu_hover.wav");
}

void MainMenuScene::on_exit()
{
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
}

void MainMenuScene::update()
{
	SDL_GetMouseState(&m_mouseRect.x, &m_mouseRect.y);
	if(m_mouseRect.x >= m_newGame.m_TextureRect.x &&
		m_mouseRect.x <= m_newGame.m_TextureRect.x + m_newGame.m_TextureRect.w &&
		m_mouseRect.y >= m_newGame.m_TextureRect.y &&
		m_mouseRect.y <= m_newGame.m_TextureRect.y + m_newGame.m_TextureRect.h)
	{
		m_isNewGame = true;
	}
	else if (m_mouseRect.x >= m_options.m_TextureRect.x &&
		m_mouseRect.x <= m_options.m_TextureRect.x + m_options.m_TextureRect.w &&
		m_mouseRect.y >= m_options.m_TextureRect.y &&
		m_mouseRect.y <= m_options.m_TextureRect.y + m_options.m_TextureRect.h)
	{
		m_isOptions = true;
	}
	else if (m_mouseRect.x >= m_exit.m_TextureRect.x &&
		m_mouseRect.x <= m_exit.m_TextureRect.x + m_exit.m_TextureRect.w &&
		m_mouseRect.y >= m_exit.m_TextureRect.y &&
		m_mouseRect.y <= m_exit.m_TextureRect.y + m_exit.m_TextureRect.h)
	{
		m_isExit = true;
	}
	else if (m_mouseRect.x >= m_exit.m_TextureRect.x &&
		m_mouseRect.x <= m_exit.m_TextureRect.x + m_exit.m_TextureRect.w &&
		m_mouseRect.y >= m_exit.m_TextureRect.y &&
		m_mouseRect.y <= m_exit.m_TextureRect.y + m_exit.m_TextureRect.h)
	{
		m_isExit = true;
	}
	else if (m_mouseRect.x >= m_leaderBoard.m_TextureRect.x &&
		m_mouseRect.x <= m_leaderBoard.m_TextureRect.x + m_leaderBoard.m_TextureRect.w &&
		m_mouseRect.y >= m_leaderBoard.m_TextureRect.y &&
		m_mouseRect.y <= m_leaderBoard.m_TextureRect.y + m_leaderBoard.m_TextureRect.h)
	{
		m_isLeaderBoard = true;
	}
	else if (m_mouseRect.x >= m_credits.m_TextureRect.x &&
		m_mouseRect.x <= m_credits.m_TextureRect.x + m_credits.m_TextureRect.w &&
		m_mouseRect.y >= m_credits.m_TextureRect.y &&
		m_mouseRect.y <= m_credits.m_TextureRect.y + m_credits.m_TextureRect.h)
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

					if (m_isNewGame)
					{
						std::unique_ptr<GameState> gamePlayState = std::make_unique<GameplayState>();
						Game::gameStateMachine.push(std::move(gamePlayState));
					}

					if (m_isLeaderBoard)
					{
						std::unique_ptr<GameState> leaderBoardScene = std::make_unique<LeaderBoardScene>();
						Game::gameStateMachine.push(std::move(leaderBoardScene));
					}

					if (m_isOptions)
					{
						std::unique_ptr<GameState> optionsMenuScene = std::make_unique<OptionsMenuScene>();
						Game::gameStateMachine.push(std::move(optionsMenuScene));
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
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_menuBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::Renderer, &m_menuBoxOutline);

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

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 150);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);
	
	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);
}