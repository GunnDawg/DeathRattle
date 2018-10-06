#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "../Game.h"

void MainMenuScene::on_enter()
{
	m_title.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/title.png");
	m_title.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 25;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = Game::screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_devName.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/dev_name.png");
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_background.Load(Game::Renderer, "Assets/Graphics/main_background.png");
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
	m_newGame.m_TextureRect.x = m_menuBox.x + 100;
	m_newGame.m_TextureRect.y = m_menuBox.y + 25;

	m_options.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/options.png");
	m_options.m_TextureRect.x = m_menuBox.x + 100;
	m_options.m_TextureRect.y = m_newGame.m_TextureRect.y + 75;

	m_leaderBoard.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/leaderboard.png");
	m_leaderBoard.m_TextureRect.x = m_menuBox.x + 50;
	m_leaderBoard.m_TextureRect.y = m_options.m_TextureRect.y + 75;

	m_exit.Load(Game::Renderer, "Assets/Graphics/main_menu_scene/exit.png");
	m_exit.m_TextureRect.x = m_menuBox.x + 150;
	m_exit.m_TextureRect.y = m_leaderBoard.m_TextureRect.y + 150;
}

void MainMenuScene::on_exit()
{

}

void MainMenuScene::update()
{
	//if (mousePos.x >= buttonX && mousePos.x <= buttonX + buttonWidth && mousePos.y >= buttonY && mousePos.y <= buttonY + buttonHeight

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
	else
	{
		m_isNewGame = false;
		m_isOptions = false;
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
						Game::isRunning = false;
					}

					if (m_isNewGame)
					{
						std::unique_ptr<GameState> gamePlayState = std::make_unique<GameplayState>();
						Game::gameStateMachine.push(std::move(gamePlayState));
					}
				} break;
			}
		}
	}
}

void MainMenuScene::draw()
{
	if (m_isNewGame)
	{
		SDL_SetTextureColorMod(m_newGame.m_Texture, 0, 0, 0);
	}
	else
	{
		SDL_SetTextureColorMod(m_newGame.m_Texture, 255, 255, 255);
	}

	if (m_isOptions)
	{
		SDL_SetTextureColorMod(m_options.m_Texture, 0, 0, 0);
	}
	else
	{
		SDL_SetTextureColorMod(m_options.m_Texture, 255, 255, 255);
	}

	if (m_isExit)
	{
		SDL_SetTextureColorMod(m_exit.m_Texture, 0, 0, 0);
	}
	else
	{
		SDL_SetTextureColorMod(m_exit.m_Texture, 255, 255, 255);
	}

	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_menuBox);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::Renderer, &m_menuBoxOutline);

	SDL_RenderCopy(Game::Renderer, m_newGame.m_Texture, NULL, &m_newGame.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_options.m_Texture, NULL, &m_options.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_leaderBoard.m_Texture, NULL, &m_leaderBoard.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_exit.m_Texture, NULL, &m_exit.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 150);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);
}