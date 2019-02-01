#include "PauseScene.h"
#include "GameplayScene.h"
#include "MainMenuScene.h"
#include "Game.h"

void PauseScene::on_enter()
{
	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;
}

void PauseScene::on_exit()
{
	m_background.Unload();

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}
}

void PauseScene::update()
{

}

void PauseScene::handle_events()
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

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						std::unique_ptr<GameState> mainMenuScene = std::make_unique<MainMenuScene>();
						Game::gameStateMachine.push(std::move(mainMenuScene));
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

void PauseScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);
}