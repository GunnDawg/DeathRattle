#include "LoadingScene.h"
#include "SplashScene.h"
#include "Game.h"

void LoadingScene::on_enter()
{
	m_Loading.Load();
	m_Loading.m_TextureRect.x = (Game::screenWidth / 2) - (m_Loading.m_TextureRect.w / 2);
	m_Loading.m_TextureRect.y = (Game::screenHeight / 2) - (m_Loading.m_TextureRect.h / 2);

	m_loadingCircle.Load((m_Loading.m_TextureRect.x + m_Loading.m_TextureRect.w + 25), m_Loading.m_TextureRect.y, 96, 96);

	m_timer.start();
}

void LoadingScene::on_exit()
{
	m_Loading.Unload();
	m_loadingCircle.Unload();
}

void LoadingScene::update()
{
	m_loadingCircle.Play(Game::deltaTime);

	if (m_timer.elapsedSeconds() >= 12)
	{
		m_timer.stop();
		Game::gameStateMachine.pop();

		std::unique_ptr<GameState> splashScene = std::make_unique<SplashScene>();
		Game::gameStateMachine.push(std::move(splashScene));
	}
}

void LoadingScene::handle_events()
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

void LoadingScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_Loading.m_Texture, NULL, &m_Loading.m_TextureRect);
	m_loadingCircle.Draw();
}