#include "IntroScene.h"
#include "GameplayScene.h"
#include "../Game.h"

void IntroSceneState::on_enter()
{
	m_background.Load(Game::m_Renderer, "Assets/Graphics/main_background.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = 1280;
	m_background.m_TextureRect.h = 720;

	m_keepIt.Load(Game::m_Renderer, "Assets/Graphics/intro_scene/keepit.png");
	m_keepIt.m_TextureRect.x = (Game::m_screenWidth / 2) - (m_keepIt.m_TextureRect.w / 2);
	m_keepIt.m_TextureRect.y = 0 - (m_keepIt.m_TextureRect.h);

	m_alive.Load(Game::m_Renderer, "Assets/Graphics/intro_scene/alive.png");
	m_alive.m_TextureRect.x = (Game::m_screenWidth / 2) - (m_alive.m_TextureRect.w / 2);
	m_alive.m_TextureRect.y = 720;

	m_pressEnter.Load(Game::m_Renderer, "Assets/Graphics/intro_scene/pressenter.png");
	m_pressEnter.m_TextureRect.x = (Game::m_screenWidth / 2) - (m_pressEnter.m_TextureRect.w / 2);
	m_pressEnter.m_TextureRect.y = 500;

	m_pressEnterBox.x = 0;
	m_pressEnterBox.y = m_pressEnter.m_TextureRect.y;
	m_pressEnterBox.w = Game::m_screenWidth;
	m_pressEnterBox.h = m_pressEnter.m_TextureRect.h;
}
void IntroSceneState::on_exit()
{
	printf("LEAVING MAIN MENU\n");
}

void IntroSceneState::update()
{
	double slideSpeed = (0.005 * Game::m_deltaTime);

	if(m_keepIt.m_TextureRect.y <= 200)
	{
		m_keepIt.m_TextureRect.y += 7;
	}

	if(m_alive.m_TextureRect.y >= 325)
	{
		m_alive.m_TextureRect.y -= 8;
	}
}

void IntroSceneState::handle_events()
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
					case SDLK_RETURN:
					{
						Game::m_gameStateMachine.pop();

						std::unique_ptr<GameState> playerSceneState = std::make_unique<GameplayState>();
						Game::m_gameStateMachine.push(std::move(playerSceneState));
					} break;

					case SDLK_ESCAPE:
					{
						Game::m_isRunning = false;
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
	SDL_RenderCopy(Game::m_Renderer, m_background.getTexture(), NULL, &m_background.m_TextureRect);
	SDL_RenderCopy(Game::m_Renderer, m_keepIt.getTexture(), NULL, &m_keepIt.m_TextureRect);
	SDL_RenderCopy(Game::m_Renderer, m_alive.getTexture(), NULL, &m_alive.m_TextureRect);

	if (m_alive.m_TextureRect.y <= 325)
	{
		SDL_SetRenderDrawBlendMode(Game::m_Renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(Game::m_Renderer, 0, 0, 0, 200);

		SDL_RenderFillRect(Game::m_Renderer, &m_pressEnterBox);
		SDL_RenderCopy(Game::m_Renderer, m_pressEnter.getTexture(), NULL, &m_pressEnter.m_TextureRect);
	}
}