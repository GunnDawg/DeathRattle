#include "SplashScene.h"
#include "Game.h"

void SplashScene::on_enter()
{
	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = 1280;
	m_background.m_TextureRect.h = 720;

	m_logo.Load();
	m_logo.m_TextureRect.x = (Game::screenWidth / 2) - (m_logo.m_TextureRect.w / 2);
	m_logo.m_TextureRect.y = -450;

	m_production.Load();
	m_production.m_TextureRect.x = (Game::screenWidth / 2) - (m_production.m_TextureRect.w / 2);
	m_production.m_TextureRect.y = Game::screenHeight;

	m_introSound.Load();
	m_introSound.Play();

	m_timer.Start();
}

void SplashScene::on_exit()
{
	m_background.Unload();
	m_logo.Unload();
	m_production.Unload();

	m_introSound.Unload();
}

void SplashScene::update()
{
	if (m_logo.m_TextureRect.y <= 10)
	{
		m_logo.m_TextureRect.y += 0.35 * Game::avgDeltaTime;
		//m_logo.m_TextureRect.y += 10;
	}

	if (m_production.m_TextureRect.y >= 540)
	{
		m_production.m_TextureRect.y -= 0.12 * Game::avgDeltaTime;
		//m_production.m_TextureRect.y -= 4;
	}

	if (m_timer.elapsedSeconds() > 7.0)
	{
		Game::gameStateMachine.pop();

		std::unique_ptr<GameState> introSceneState = std::make_unique<IntroSceneState>();
		Game::gameStateMachine.push(std::move(introSceneState));
	}
}

void SplashScene::handle_events()
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

		default:
			break;
		}
		
	}
}

void SplashScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_production.m_Texture, NULL, &m_production.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_logo.m_Texture, NULL, &m_logo.m_TextureRect);
}