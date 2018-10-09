#include "SplashScene.h"
#include "Game.h"

void SplashScene::on_enter()
{
	m_background.Load(Game::Renderer, "Assets/Graphics/splash_scene/background2.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;

	m_logo.Load(Game::Renderer, "Assets/Graphics/splash_scene/GGlogo2.png");
	m_logo.m_TextureRect.x = (Game::screenWidth / 2) - (m_logo.m_TextureRect.w / 2);
	m_logo.m_TextureRect.y = -450;

	m_production.Load(Game::Renderer, "Assets/Graphics/splash_scene/production2.png");
	m_production.m_TextureRect.x = (Game::screenWidth / 2) - (m_production.m_TextureRect.w / 2);
	m_production.m_TextureRect.y = Game::screenHeight;

	m_introSound.Load("Assets/Audio/intro.wav");
	m_introSound.Play();

	m_timer.start();
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
	if (m_logo.m_TextureRect.y <= 75)
	{
		m_logo.m_TextureRect.y += 10;
	}

	if (m_production.m_TextureRect.y >= (m_logo.m_TextureRect.y + m_logo.m_TextureRect.h) + 100)
	{
		m_production.m_TextureRect.y -= 1.75;
	}

	if (m_timer.elapsedSeconds() > 5.0)
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
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_logo.m_Texture, NULL, &m_logo.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_production.m_Texture, NULL, &m_production.m_TextureRect);
}