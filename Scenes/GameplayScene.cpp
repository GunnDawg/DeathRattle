#include "GameplayScene.h"
#include "../Game.h"

void GameplayState::on_enter()
{
	// initialise whatever you need to here (such as instantiating the player, etc.)
	m_Player = Player();
	m_Player.on_enter();
}

void GameplayState::on_exit()
{
	// Free up memeory if you need to
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
			Game::m_isRunning = false;
		} break;

		case SDL_KEYDOWN:
		{
			switch (evnt.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			{
				Game::m_isRunning = false;
			} break;

			case SDLK_m:
			{
				
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
	m_Player.update(); // m_Player is the player object you created in on_enter()
}

void GameplayState::draw()
{
	m_Player.draw(); // m_Player is the player object you created in on_enter()
}