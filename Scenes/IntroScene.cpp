#include "IntroScene.h"
#include "MainMenuScene.h"
#include "Game.h"

void IntroSceneState::on_enter()
{
	game = &Game::GetInstance();

	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = game->screenWidth;
	m_background.m_TextureRect.h = game->screenHeight;

	m_title.Load();
	m_title.m_TextureRect.x = (game->screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = (game->screenHeight / 2) - (m_title.m_TextureRect.h / 2) - 60;

	m_howLong.Load();
	m_howLong.m_TextureRect.x = (game->screenWidth / 2) - (m_howLong.m_TextureRect.w / 2);
	m_howLong.m_TextureRect.y = m_title.m_TextureRect.y + 85;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_plug.Load();
	m_plug.m_TextureRect.x = (game->screenWidth / 2) - (m_plug.m_TextureRect.w / 2);
	m_plug.m_TextureRect.y = 0;

	m_blood.Load();
	m_blood.m_TextureRect.x = (game->screenWidth / 2) - (m_blood.m_TextureRect.w / 2);
	m_blood.m_TextureRect.y = (game->screenHeight / 2) - (m_blood.m_TextureRect.h / 2);

	m_skullBox.w = game->screenWidth;
	m_skullBox.h = 100;
	m_skullBox.x = (game->screenWidth / 2) - (m_skullBox.w / 2);
	m_skullBox.y = 550;

	m_skullWhite.Load();
	m_skullWhite.m_TextureRect.w = 125;
	m_skullWhite.m_TextureRect.h = 125;
	m_skullWhite.m_TextureRect.x = (game->screenWidth / 2) - m_skullWhite.m_TextureRect.w / 2;
	m_skullWhite.m_TextureRect.y = m_skullBox.y - 10;

	m_skullCollider.w = m_skullWhite.m_TextureRect.w / 2;
	m_skullCollider.h = m_skullWhite.m_TextureRect.h / 2;
	m_skullCollider.x = m_skullWhite.m_TextureRect.x + m_skullCollider.w / 2;
	m_skullCollider.y = m_skullWhite.m_TextureRect.y + m_skullCollider.h / 2;

	m_skull.Load();
	m_skull.m_TextureRect.w = 125;
	m_skull.m_TextureRect.h = 125;
	m_skull.m_TextureRect.x = m_skullWhite.m_TextureRect.x;
	m_skull.m_TextureRect.y = m_skullWhite.m_TextureRect.y;

	m_press.Load();
	m_press.m_TextureRect.x = (m_skullWhite.m_TextureRect.x) - (m_press.m_TextureRect.w) - 10;
	m_press.m_TextureRect.y = (m_skullBox.y + m_press.m_TextureRect.h / 2);

	m_enter.Load();
	m_enter.m_TextureRect.x = (m_skullWhite.m_TextureRect.x) + (m_enter.m_TextureRect.w) - 10;
	m_enter.m_TextureRect.y = (m_skullBox.y + m_enter.m_TextureRect.h / 2);

	m_plugBox.x = 0;
	m_plugBox.y = m_plug.m_TextureRect.y;
	m_plugBox.w = game->screenWidth;
	m_plugBox.h = m_plug.m_TextureRect.h;

	m_version.Load();
	m_version.m_TextureRect.x = ((game->screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (game->screenHeight - m_version.m_TextureRect.h);

	m_timer.Start();

	m_introSound.Load();
	m_introSound.Play();

	m_scare.Load();
	m_scare.setVolume(5);
}

void IntroSceneState::on_exit()
{
	m_cursor.Unload();
	m_background.Unload();
	m_title.Unload();
	m_howLong.Unload();
	m_plug.Unload();
	m_blood.Unload();
	m_skullWhite.Unload();
	m_skull.Unload();
	m_press.Unload();
	m_enter.Unload();
	m_version.Unload();

	//m_introSound.Unload();
	//m_scare.Unload();

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	game = nullptr;
}

void IntroSceneState::update()
{
	m_cursor.setRect(game->mouseX, game->mouseY);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
	}

	if (m_timer.elapsedMilliseconds() > 200)
	{
		m_isBlood = true;
		m_timer.Stop();
	}

	if (game->mouseX >= m_skullCollider.x &&
		game->mouseX <= m_skullCollider.x + m_skullCollider.w &&
		game->mouseY >= m_skullCollider.y &&
		game->mouseY <= m_skullCollider.y + m_skullCollider.h)
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

		m_skull.m_TextureRect.w += (10.00 * game->avgDeltaTime);
		m_skull.m_TextureRect.h += (10.00 * game->avgDeltaTime);
		m_skull.m_TextureRect.x -= (5.00  * game->avgDeltaTime);
		m_skull.m_TextureRect.y -= (5.00  * game->avgDeltaTime);

		m_skullWhite.m_TextureRect.w = m_skull.m_TextureRect.w;
		m_skullWhite.m_TextureRect.h = m_skull.m_TextureRect.h;
		m_skullWhite.m_TextureRect.x = m_skull.m_TextureRect.x;
		m_skullWhite.m_TextureRect.y = m_skull.m_TextureRect.y;

		m_skullBox.y += 50;
		m_press.m_TextureRect.x -= 100;
		m_enter.m_TextureRect.x += 100;

		if (m_timer.elapsedMilliseconds() > 250)
		{
			game->gameStateMachine.pop();

			std::unique_ptr<GameState> mainMenuState = std::make_unique<MainMenuScene>();
			game->gameStateMachine.push(std::move(mainMenuState));
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
				game->isRunning = false;
			} break;

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_RETURN:
					{
						m_timer.Start();
						m_isClicked = true;
						m_isSkull = true;
					} break;

					case SDLK_ESCAPE:
					{
						game->isRunning = false;
					} break;

				default:
					break;
				}
			} break;

			case SDL_MOUSEBUTTONDOWN:
			{
				if (m_isSkull)
				{
					m_timer.Start();
					m_isClicked = true;
				}
			} break;

		default:
			break;
		}
	}
}

void IntroSceneState::draw()
{
	SDL_RenderCopy(game->Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	if (m_isBlood)
	{
		SDL_RenderCopy(game->Renderer, m_blood.m_Texture, NULL, &m_blood.m_TextureRect);
		SDL_RenderCopy(game->Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);
		SDL_RenderCopy(game->Renderer, m_howLong.m_Texture, NULL, &m_howLong.m_TextureRect);
	}

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_plugBox);
	SDL_RenderFillRect(game->Renderer, &m_skullBox);
	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	if (m_isSkull)
	{
		SDL_RenderCopy(game->Renderer, m_skull.m_Texture, NULL, &m_skull.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_skullWhite.m_Texture, NULL, &m_skullWhite.m_TextureRect);
	}
	SDL_RenderCopy(game->Renderer, m_press.m_Texture, NULL, &m_press.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_enter.m_Texture, NULL, &m_enter.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_plug.m_Texture, NULL, &m_plug.m_TextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}