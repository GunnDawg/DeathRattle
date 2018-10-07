#include "LeaderboardScene.h"
#include "../Game.h"

void LeaderBoardScene::on_enter()
{
	m_background.Load(Game::Renderer, "Assets/Graphics/common/main_background.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_comingSoon.Load(Game::Renderer, "Assets/Graphics/leaderboard_scene/comingsoon.png");
	m_comingSoon.m_TextureRect.y = (Game::screenHeight / 2) - m_comingSoon.m_TextureRect.h / 2;
	m_comingSoon.m_TextureRect.x = (Game::screenWidth / 2) - m_comingSoon.m_TextureRect.w / 2;

	m_comingSoonBox.x = 0;
	m_comingSoonBox.y = m_comingSoon.m_TextureRect.y;
	m_comingSoonBox.w = Game::screenWidth;
	m_comingSoonBox.h = m_comingSoon.m_TextureRect.h;
}

void LeaderBoardScene::on_exit()
{
	m_background.Unload();
	m_comingSoon.Unload();
}

void LeaderBoardScene::update()
{

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
				Game::isRunning = false;
			} break;

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						Game::gameStateMachine.pop();
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
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_comingSoon.m_Texture, NULL, &m_comingSoon.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(Game::Renderer, &m_comingSoonBox);

	SDL_RenderCopy(Game::Renderer, m_comingSoon.m_Texture, NULL, &m_comingSoon.m_TextureRect);
}

void LeaderBoardScene::unload_All()
{

}