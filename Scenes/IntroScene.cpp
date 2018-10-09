#include "IntroScene.h"
#include "MainMenuScene.h"
#include "Game.h"

void IntroSceneState::on_enter()
{
	m_cursor.Load(Game::Renderer, "Assets/Graphics/common/cursor2.png");
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_background.Load(Game::Renderer, "Assets/Graphics/common/main_background.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_plug.Load(Game::Renderer, "Assets/Graphics/intro_scene/plug.png");
	m_plug.m_TextureRect.x = (Game::screenWidth / 2) - (m_plug.m_TextureRect.w / 2);
	m_plug.m_TextureRect.y = 0;

	m_keepIt.Load(Game::Renderer, "Assets/Graphics/intro_scene/keepit.png");
	m_keepIt.m_TextureRect.x = (Game::screenWidth / 2) - (m_keepIt.m_TextureRect.w / 2);
	m_keepIt.m_TextureRect.y = 0 - (m_keepIt.m_TextureRect.h);

	m_alive.Load(Game::Renderer, "Assets/Graphics/intro_scene/alive.png");
	m_alive.m_TextureRect.x = (Game::screenWidth / 2) - (m_alive.m_TextureRect.w / 2);
	m_alive.m_TextureRect.y = 720;

	m_pressEnter.Load(Game::Renderer, "Assets/Graphics/intro_scene/pressenter.png");
	m_pressEnter.m_TextureRect.x = (Game::screenWidth / 2) - (m_pressEnter.m_TextureRect.w / 2);
	m_pressEnter.m_TextureRect.y = 500;

	m_website.Load(Game::Renderer, "Assets/Graphics/intro_scene/website.png");
	m_website.m_TextureRect.x = (Game::screenWidth / 2) - (m_website.m_TextureRect.w / 2);
	m_website.m_TextureRect.y = (Game::screenHeight - m_website.m_TextureRect.h);

	m_pressEnterBox.x = 0;
	m_pressEnterBox.y = m_pressEnter.m_TextureRect.y;
	m_pressEnterBox.w = Game::screenWidth;
	m_pressEnterBox.h = m_pressEnter.m_TextureRect.h;

	m_plugBox.x = 0;
	m_plugBox.y = m_plug.m_TextureRect.y;
	m_plugBox.w = Game::screenWidth;
	m_plugBox.h = m_plug.m_TextureRect.h;

	m_websiteBox.x = 0;
	m_websiteBox.y = m_website.m_TextureRect.y;
	m_websiteBox.w = Game::screenWidth;
	m_websiteBox.h = m_website.m_TextureRect.h;

	m_introSound.Load("Assets/Audio/splat.wav");
	m_introSound.Play();
}
void IntroSceneState::on_exit()
{
	m_cursor.Unload();

	m_background.Unload();
	m_keepIt.Unload();
	m_alive.Unload();
	m_pressEnter.Unload();
	m_plug.Unload();
	m_website.Unload();

	m_introSound.Unload();
}

void IntroSceneState::update()
{
	m_cursor.m_TextureRect.x = Game::mouseX;
	m_cursor.m_TextureRect.y = Game::mouseY;

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
				Game::isRunning = false;
			} break;

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_RETURN:
					{
						Game::gameStateMachine.pop();

						std::unique_ptr<GameState> mainMenuState = std::make_unique<MainMenuScene>();
						Game::gameStateMachine.push(std::move(mainMenuState));
					} break;

					case SDLK_ESCAPE:
					{
						Game::isRunning = false;
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
	SDL_RenderCopy(Game::Renderer, m_background.getTexture(), NULL, &m_background.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_keepIt.getTexture(), NULL, &m_keepIt.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_alive.getTexture(), NULL, &m_alive.m_TextureRect);

	if (m_alive.m_TextureRect.y <= 325)
	{
		SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);

		SDL_RenderFillRect(Game::Renderer, &m_pressEnterBox);
		SDL_RenderFillRect(Game::Renderer, &m_plugBox);
		SDL_RenderFillRect(Game::Renderer, &m_websiteBox);

		SDL_RenderCopy(Game::Renderer, m_plug.m_Texture, NULL, &m_plug.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_pressEnter.getTexture(), NULL, &m_pressEnter.m_TextureRect);

		SDL_RenderCopy(Game::Renderer, m_website.m_Texture, NULL, &m_website.m_TextureRect);
	}

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}