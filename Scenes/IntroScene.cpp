#include "IntroScene.h"
#include "MainMenuScene.h"
#include "Game.h"

void IntroSceneState::on_enter()
{
	m_cursor = Texture("Assets/Graphics/common/cursor2.png");
	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_background = Texture("Assets/Graphics/common/main_background.png");
	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_plug = Texture("Assets/Graphics/intro_scene/plug.png");
	m_plug.Load();
	m_plug.m_TextureRect.x = (Game::screenWidth / 2) - (m_plug.m_TextureRect.w / 2);
	m_plug.m_TextureRect.y = 0;

	m_keepIt = Texture("Assets/Graphics/intro_scene/keepit.png");
	m_keepIt.Load();
	m_keepIt.m_TextureRect.x = (Game::screenWidth / 2) - (m_keepIt.m_TextureRect.w / 2);
	m_keepIt.m_TextureRect.y = 0 - (m_keepIt.m_TextureRect.h);

	m_alive = Texture("Assets/Graphics/intro_scene/alive.png");
	m_alive.Load();
	m_alive.m_TextureRect.x = (Game::screenWidth / 2) - (m_alive.m_TextureRect.w / 2) + 25;
	m_alive.m_TextureRect.y = 720;

	m_blood = Texture("Assets/Graphics/intro_scene/blood.png");
	m_blood.Load();
	m_blood.m_TextureRect.x = (Game::screenWidth / 2) - (m_blood.m_TextureRect.w / 2);
	m_blood.m_TextureRect.y = (Game::screenHeight / 2) - (m_blood.m_TextureRect.h / 2);

	m_skullBox.w = Game::screenWidth;
	m_skullBox.h = 100;
	m_skullBox.x = (Game::screenWidth / 2) - (m_skullBox.w / 2);
	m_skullBox.y = 550;

	m_skullWhite = Texture("Assets/Graphics/intro_scene/skull_white.png");
	m_skullWhite.Load();
	m_skullWhite.m_TextureRect.w = 125;
	m_skullWhite.m_TextureRect.h = 125;
	m_skullWhite.m_TextureRect.x = (Game::screenWidth / 2) - m_skullWhite.m_TextureRect.w / 2;
	m_skullWhite.m_TextureRect.y = m_skullBox.y - 10;

	m_skullCollider.w = m_skullWhite.m_TextureRect.w / 2;
	m_skullCollider.h = m_skullWhite.m_TextureRect.h / 2;
	m_skullCollider.x = m_skullWhite.m_TextureRect.x + m_skullCollider.w / 2;
	m_skullCollider.y = m_skullWhite.m_TextureRect.y + m_skullCollider.h / 2;

	m_skull = Texture("Assets/Graphics/intro_scene/skull.png");
	m_skull.Load();
	m_skull.m_TextureRect.w = 125;
	m_skull.m_TextureRect.h = 125;
	m_skull.m_TextureRect.x = m_skullWhite.m_TextureRect.x;
	m_skull.m_TextureRect.y = m_skullWhite.m_TextureRect.y;

	m_press = Texture("Assets/Graphics/intro_scene/press.png");
	m_press.Load();
	m_press.m_TextureRect.x = (m_skullWhite.m_TextureRect.x) - (m_press.m_TextureRect.w) - 10;
	m_press.m_TextureRect.y = (m_skullBox.y + m_press.m_TextureRect.h / 2);

	m_enter = Texture("Assets/Graphics/intro_scene/enter.png");
	m_enter.Load();
	m_enter.m_TextureRect.x = (m_skullWhite.m_TextureRect.x) + (m_enter.m_TextureRect.w) - 10;
	m_enter.m_TextureRect.y = (m_skullBox.y + m_enter.m_TextureRect.h / 2);

	m_plugBox.x = 0;
	m_plugBox.y = m_plug.m_TextureRect.y;
	m_plugBox.w = Game::screenWidth;
	m_plugBox.h = m_plug.m_TextureRect.h;

	m_version = Texture("Assets/Graphics/common/version.png");
	m_version.Load();
	m_version.m_TextureRect.x = ((Game::screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_timer.start();

	m_scare.Load("Assets/Audio/scare.wav");
	m_scare.setVolume(5);

	m_introSound.Load("Assets/Audio/splat.wav");
	m_introSound.Play();
}

void IntroSceneState::on_exit()
{
	m_background.Unload();
	m_keepIt.Unload();
	m_alive.Unload();
	m_plug.Unload();
	m_cursor.Unload();
	m_blood.Unload();

	m_introSound.Unload();
	//m_scare.Unload();
}

void IntroSceneState::update()
{
	m_cursor.m_TextureRect.x = Game::mouseX;
	m_cursor.m_TextureRect.y = Game::mouseY;

	if(m_keepIt.m_TextureRect.y <= 200)
	{
		m_keepIt.m_TextureRect.y += 20;
	}

	if(m_alive.m_TextureRect.y >= 300)
	{
		m_alive.m_TextureRect.y -= 25;
	}

	if (m_timer.elapsedMilliseconds() > 200)
	{
		m_isBlood = true;
		m_timer.stop();
	}

	if (Game::mouseX >= m_skullCollider.x &&
		Game::mouseX <= m_skullCollider.x + m_skullCollider.w &&
		Game::mouseY >= m_skullCollider.y &&
		Game::mouseY <= m_skullCollider.y + m_skullCollider.h)
	{
		m_isSkull = true;
	}
	else
	{
		m_isSkull = false;
	}

	if (m_isClicked)
	{
		m_isSkull = false;
		m_scare.Play();

		m_skull.m_TextureRect.w += 200;
		m_skull.m_TextureRect.h += 200;
		m_skull.m_TextureRect.x -= 100;
		m_skull.m_TextureRect.y -= 100;

		m_skullWhite.m_TextureRect.w = m_skull.m_TextureRect.w;
		m_skullWhite.m_TextureRect.h = m_skull.m_TextureRect.h;
		m_skullWhite.m_TextureRect.x = m_skull.m_TextureRect.x;
		m_skullWhite.m_TextureRect.y = m_skull.m_TextureRect.y;

		m_skullBox.y += 50;
		m_press.m_TextureRect.x -= 100;
		m_enter.m_TextureRect.x += 100;

		if (m_timer.elapsedMilliseconds() > 250)
		{
			Game::gameStateMachine.pop();

			std::unique_ptr<GameState> mainMenuState = std::make_unique<MainMenuScene>();
			Game::gameStateMachine.push(std::move(mainMenuState));
		}
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
						m_timer.start();
						m_isClicked = true;
						m_isSkull = true;
					} break;

					case SDLK_ESCAPE:
					{
						Game::isRunning = false;
					} break;

					default:
						break;
				}
			} break;

			case SDL_MOUSEBUTTONDOWN:
			{
				if (m_isSkull)
				{
					m_timer.start();
					m_isClicked = true;
				}
			}

			default:
				break;
		}
	}
}

void IntroSceneState::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);
	if (m_isBlood)
	{
		SDL_RenderCopy(Game::Renderer, m_blood.m_Texture, NULL, &m_blood.m_TextureRect);
	}
	SDL_RenderCopyEx(Game::Renderer, m_keepIt.m_Texture, NULL, &m_keepIt.m_TextureRect, -25, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(Game::Renderer, m_alive.m_Texture, NULL, &m_alive.m_TextureRect, -25, NULL, SDL_FLIP_NONE);

	if (m_alive.m_TextureRect.y <= 325)
	{
		SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
		SDL_RenderFillRect(Game::Renderer, &m_plugBox);
		SDL_RenderFillRect(Game::Renderer, &m_skullBox);
		SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
		SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

		if (m_isSkull)
		{
			SDL_RenderCopy(Game::Renderer, m_skull.m_Texture, NULL, &m_skull.m_TextureRect);
		}
		else
		{
			SDL_RenderCopy(Game::Renderer, m_skullWhite.m_Texture, NULL, &m_skullWhite.m_TextureRect);
		}
		SDL_RenderCopy(Game::Renderer, m_press.m_Texture, NULL, &m_press.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_enter.m_Texture, NULL, &m_enter.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_plug.m_Texture, NULL, &m_plug.m_TextureRect);
	}

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}