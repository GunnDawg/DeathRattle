#include "PlayerSceneState.h"
#include "../Game.h"

void PlayerSceneState::on_enter(SDL_Renderer* passedRenderer)
{
	// initialise whatever you need to here (such as instantiating the player, etc.)
	m_Player = Player();
	m_Player.on_enter(passedRenderer);
}

void PlayerSceneState::on_exit()
{
	// Free up memeory if you need to
}

void PlayerSceneState::handle_events()
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

void PlayerSceneState::update(double dt)
{
	m_Player.update(dt); // m_Player is the player object you created in on_enter()
}

void PlayerSceneState::draw(SDL_Renderer* passedRenderer)
{
	m_Player.draw(passedRenderer); // m_Player is the player object you created in on_enter()
}