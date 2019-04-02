#include <memory>

#include "LeaderboardScene.h"
#include "Game.h"

void LeaderBoardScene::on_enter()
{
	GUNN_CORE_INFO("----------ENTERING LEADERBOARD SCENE----------");

	game = &Game::GetInstance();

	m_cursor.Load();
	m_cursor.mTextureRect.w = 48;
	m_cursor.mTextureRect.h = 48;

	m_background.Load();
	m_background.mTextureRect.x = 0;
	m_background.mTextureRect.y = 0;
	m_background.mTextureRect.w = game->screenWidth;
	m_background.mTextureRect.h = game->screenHeight;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_comingSoon.Load();
	m_comingSoon.mTextureRect.y = (game->screenHeight / 2) - m_comingSoon.mTextureRect.h / 2;
	m_comingSoon.mTextureRect.x = (game->screenWidth / 2) - m_comingSoon.mTextureRect.w / 2;

	m_comingSoonBox.x = 0;
	m_comingSoonBox.y = m_comingSoon.mTextureRect.y;
	m_comingSoonBox.w = game->screenWidth;
	m_comingSoonBox.h = m_comingSoon.mTextureRect.h;

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
	SDL_RenderCopy(game->Renderer, m_background.mTexture, NULL, &m_background.mTextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	SDL_RenderCopy(game->Renderer, m_comingSoon.mTexture, NULL, &m_comingSoon.mTextureRect);

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_comingSoonBox);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	SDL_RenderCopy(game->Renderer, m_comingSoon.mTexture, NULL, &m_comingSoon.mTextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.mTexture, NULL, &m_cursor.mTextureRect);
}