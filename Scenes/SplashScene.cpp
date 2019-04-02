#include <memory>

#include "SplashScene.h"
#include "Game.h"
#include <Scenes/IntroScene.h>

void SplashScene::on_enter()
{
	GUNN_CORE_INFO("----------ENTERING SPLASH SCENE----------");

	game = &Game::GetInstance();

	m_background.Load();
	m_background.mTextureRect.x = 0;
	m_background.mTextureRect.y = 0;
	m_background.mTextureRect.w = 1280;
	m_background.mTextureRect.h = 720;

	m_logo.Load();
	m_logo.mTextureRect.x = (game->screenWidth / 2) - (m_logo.mTextureRect.w / 2);
	m_logo.mTextureRect.y = -450;

	m_production.Load();
	m_production.mTextureRect.x = (game->screenWidth / 2) - (m_production.mTextureRect.w / 2);
	m_production.mTextureRect.y = game->screenHeight;

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
	if (m_logo.mTextureRect.y <= 10)
	{
		m_logo.mTextureRect.y += 0.35 * game->avgDeltaTime;
	}

	if (m_production.mTextureRect.y >= 540)
	{
		m_production.mTextureRect.y -= 0.123 * game->avgDeltaTime;
	}

	if (m_timer.ElapsedSeconds() > 7.0)
	{
		m_timer.Stop();

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
	SDL_RenderCopy(game->Renderer, m_background.mTexture, NULL, &m_background.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_production.mTexture, NULL, &m_production.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_logo.mTexture, NULL, &m_logo.mTextureRect);
}