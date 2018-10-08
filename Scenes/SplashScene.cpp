#include "SplashScene.h"
#include "../Game.h"

void SplashScene::on_enter()
{
	m_logo.Load(Game::Renderer, "Assets/Graphics/splash_scene/GGlogo.png");
	m_logo.m_TextureRect.x = (Game::screenWidth / 2) - (m_logo.m_TextureRect.w / 2);
	m_logo.m_TextureRect.y = -450;

	m_production.Load(Game::Renderer, "Assets/Graphics/splash_scene/production.png");
	m_production.m_TextureRect.x = (Game::screenWidth / 2) - (m_production.m_TextureRect.w / 2);
	m_production.m_TextureRect.y = Game::screenHeight;

	m_timer.start();
}

void SplashScene::on_exit()
{
	m_logo.Unload();
	m_production.Unload();
}

void SplashScene::update()
{
	if (m_logo.m_TextureRect.y <= 75)
	{
		m_logo.m_TextureRect.y += 10;
	}

	if (m_production.m_TextureRect.y >= (m_logo.m_TextureRect.y + m_logo.m_TextureRect.h) + 200)
	{
		m_production.m_TextureRect.y -= 1.75;
	}

	if (m_timer.elapsedSeconds() > 5.0)
	{
		Game::gameStateMachine.pop();

		std::unique_ptr<GameState> introSceneState = std::make_unique<IntroSceneState>();
		Game::gameStateMachine.push(std::move(introSceneState));
	}
	
	if (m_logo.m_TextureRect.y == 79)
	{
		m_thud.Play();
	}
}

void SplashScene::handle_events()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
			case SDL_KEYDOWN:
			{
				Game::gameStateMachine.pop();

				std::unique_ptr<GameState> introSceneState = std::make_unique<IntroSceneState>();
				Game::gameStateMachine.push(std::move(introSceneState));
			} break;

			default:
				break;
		}
	}
}

void SplashScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_logo.m_Texture, NULL, &m_logo.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_production.m_Texture, NULL, &m_production.m_TextureRect);
}