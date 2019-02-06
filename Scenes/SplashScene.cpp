#include "SplashScene.h"
#include "Game.h"

void SplashScene::on_enter()
{
	game = &Game::GetInstance();

	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = 1280;
	m_background.m_TextureRect.h = 720;

	m_logo.Load();
	m_logo.m_TextureRect.x = (game->screenWidth / 2) - (m_logo.m_TextureRect.w / 2);
	m_logo.m_TextureRect.y = -450;

	m_production.Load();
	m_production.m_TextureRect.x = (game->screenWidth / 2) - (m_production.m_TextureRect.w / 2);
	m_production.m_TextureRect.y = game->screenHeight;

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

	game = nullptr;
}

void SplashScene::update()
{
	if (m_logo.m_TextureRect.y <= 10)
	{
		m_logo.m_TextureRect.y += 0.35 * game->avgDeltaTime;
	}

	if (m_production.m_TextureRect.y >= 540)
	{
		m_production.m_TextureRect.y -= 0.123 * game->avgDeltaTime;
	}

	if (m_timer.elapsedSeconds() > 7.0)
	{
		game->gameStateMachine.pop();

		std::unique_ptr<GameState> introSceneState = std::make_unique<IntroSceneState>();
		game->gameStateMachine.push(std::move(introSceneState));
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
				game->isRunning = false;
			} break;

		default:
			break;
		}
		
	}
}

void SplashScene::draw()
{
	SDL_RenderCopy(game->Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_production.m_Texture, NULL, &m_production.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_logo.m_Texture, NULL, &m_logo.m_TextureRect);
}