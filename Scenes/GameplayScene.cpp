#include "GameplayScene.h"
#include "Game.h"

void GameplayState::on_enter()
{
	m_Player = Player();
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

			} break;

			default:
				break;
		}
	}
}

void GameplayState::update()
{
	m_Player.update();
}

void GameplayState::draw()
{
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 255);
	m_Player.draw();
}