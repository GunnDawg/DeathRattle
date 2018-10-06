#include "IntroScene.h"
#include "GameplayScene.h"
#include "../Game.h"

void IntroSceneState::on_enter()
{
	m_gameNameTexture.Load(Game::m_Renderer, "Assets/Graphics/splash.png");
	m_gameNameTexture.m_TextureRect.y = -300;
	m_gameNameTexture.m_TextureRect.x = 0;

	m_pressEnter.Load(Game::m_Renderer, "Assets/Graphics/pressenter.png");
	m_pressEnter.m_TextureRect.y = 800;
	m_pressEnter.m_TextureRect.x = (Game::m_screenWidth / 2) - (m_pressEnter.m_TextureRect.w / 2);
}
void IntroSceneState::on_exit()
{
	
}

void IntroSceneState::update()
{
	double slideSpeed = (0.005 * Game::m_deltaTime);

	if(m_gameNameTexture.m_TextureRect.y < 200)
	{
		m_gameNameTexture.m_TextureRect.y += 3;
	}

	if(m_pressEnter.m_TextureRect.y > 400)
	{
		m_pressEnter.m_TextureRect.y -= 3;
	}
	

}

void IntroSceneState::handle_events()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_KEYDOWN:
		{
			switch (evnt.key.keysym.sym)
			{
			case SDLK_m:
			{
				std::unique_ptr<GameState> playerSceneState = std::make_unique<GameplayState>();
				Game::m_gameStateMachine.push(std::move(playerSceneState));
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

void IntroSceneState::draw()
{
	SDL_RenderCopy(Game::m_Renderer, m_gameNameTexture.getTexture(), NULL, &m_gameNameTexture.m_TextureRect);
	SDL_RenderCopy(Game::m_Renderer, m_pressEnter.getTexture(), NULL, &m_pressEnter.m_TextureRect);
}