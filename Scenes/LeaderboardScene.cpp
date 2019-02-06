#include "LeaderboardScene.h"
#include "Game.h"

void LeaderBoardScene::on_enter()
{
	game = &Game::GetInstance();

	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = game->screenWidth;
	m_background.m_TextureRect.h = game->screenHeight;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_comingSoon.Load();
	m_comingSoon.m_TextureRect.y = (game->screenHeight / 2) - m_comingSoon.m_TextureRect.h / 2;
	m_comingSoon.m_TextureRect.x = (game->screenWidth / 2) - m_comingSoon.m_TextureRect.w / 2;

	m_comingSoonBox.x = 0;
	m_comingSoonBox.y = m_comingSoon.m_TextureRect.y;
	m_comingSoonBox.w = game->screenWidth;
	m_comingSoonBox.h = m_comingSoon.m_TextureRect.h;

	m_thud.Load();
	m_thud.Play();
}

void LeaderBoardScene::on_exit()
{
	m_cursor.Unload();

	m_background.Unload();
	m_comingSoon.Unload();

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	m_thud.Unload();

	game = nullptr;
}

void LeaderBoardScene::update()
{
	m_cursor.setRect(game->mouseX, game->mouseY);
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
	}
}

void LeaderBoardScene::handle_events()
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
						game->gameStateMachine.pop();
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

void LeaderBoardScene::draw()
{
	SDL_RenderCopy(game->Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	SDL_RenderCopy(game->Renderer, m_comingSoon.m_Texture, NULL, &m_comingSoon.m_TextureRect);

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_comingSoonBox);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	SDL_RenderCopy(game->Renderer, m_comingSoon.m_Texture, NULL, &m_comingSoon.m_TextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}