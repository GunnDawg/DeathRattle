#include "IntroScene.h"
#include "MainMenuScene.h"
#include "Game.h"
#include "Graphics/FadeEffect.h"

void IntroSceneState::on_enter()
{
	GUNN_CORE_INFO("----------ENTERING INTRO SCENE----------");

	game = &Game::GetInstance();

	m_cursor.Load();
	m_cursor.mTextureRect.w = 48;
	m_cursor.mTextureRect.h = 48;

	m_background.Load();
	m_background.mTextureRect.x = 0;
	m_background.mTextureRect.y = 0;
	m_background.mTextureRect.w = game->screenWidth;
	m_background.mTextureRect.h = game->screenHeight;

	m_title.Load();
	m_title.mTextureRect.x = (game->screenWidth / 2) - (m_title.mTextureRect.w / 2);
	m_title.mTextureRect.y = (game->screenHeight / 2) - (m_title.mTextureRect.h / 2) - 60;

	m_howLong.Load();
	m_howLong.mTextureRect.x = (game->screenWidth / 2) - (m_howLong.mTextureRect.w / 2);
	m_howLong.mTextureRect.y = m_title.mTextureRect.y + 85;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_plug.Load();
	m_plug.mTextureRect.x = (game->screenWidth / 2) - (m_plug.mTextureRect.w / 2);
	m_plug.mTextureRect.y = 0;

	m_blood.Load();
	m_blood.mTextureRect.x = (game->screenWidth / 2) - (m_blood.mTextureRect.w / 2);
	m_blood.mTextureRect.y = (game->screenHeight / 2) - (m_blood.mTextureRect.h / 2);

	m_skullBox.w = game->screenWidth;
	m_skullBox.h = 100;
	m_skullBox.x = (game->screenWidth / 2) - (m_skullBox.w / 2);
	m_skullBox.y = 550;

	m_skullWhite.Load();
	m_skullWhite.mTextureRect.w = 125;
	m_skullWhite.mTextureRect.h = 125;
	m_skullWhite.mTextureRect.x = (game->screenWidth / 2) - m_skullWhite.mTextureRect.w / 2;
	m_skullWhite.mTextureRect.y = m_skullBox.y - 10;

	m_skullCollider.w = m_skullWhite.mTextureRect.w / 2;
	m_skullCollider.h = m_skullWhite.mTextureRect.h / 2;
	m_skullCollider.x = m_skullWhite.mTextureRect.x + m_skullCollider.w / 2;
	m_skullCollider.y = m_skullWhite.mTextureRect.y + m_skullCollider.h / 2;

	m_skull.Load();
	m_skull.mTextureRect.w = 125;
	m_skull.mTextureRect.h = 125;
	m_skull.mTextureRect.x = m_skullWhite.mTextureRect.x;
	m_skull.mTextureRect.y = m_skullWhite.mTextureRect.y;

	m_press.Load();
	m_press.mTextureRect.x = (m_skullWhite.mTextureRect.x) - (m_press.mTextureRect.w) - 10;
	m_press.mTextureRect.y = (m_skullBox.y + m_press.mTextureRect.h / 2);

	m_enter.Load();
	m_enter.mTextureRect.x = (m_skullWhite.mTextureRect.x) + (m_enter.mTextureRect.w) - 10;
	m_enter.mTextureRect.y = (m_skullBox.y + m_enter.mTextureRect.h / 2);

	m_plugBox.x = 0;
	m_plugBox.y = m_plug.mTextureRect.y;
	m_plugBox.w = game->screenWidth;
	m_plugBox.h = m_plug.mTextureRect.h;

	m_version.Load();
	m_version.mTextureRect.x = ((game->screenWidth - m_version.mTextureRect.w) - 20);
	m_version.mTextureRect.y = (game->screenHeight - m_version.mTextureRect.h);

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

	if (m_timer.ElapsedMilliseconds() > 200)
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
		mFadeValue = 255;
		mFadeIn = false;
		mFadeOut = false;

		m_isSkull = false;
		m_scare.Play();

		m_skull.mTextureRect.w += (10.00 * game->avgDeltaTime);
		m_skull.mTextureRect.h += (10.00 * game->avgDeltaTime);
		m_skull.mTextureRect.x -= (5.00 * game->avgDeltaTime);
		m_skull.mTextureRect.y -= (5.00 * game->avgDeltaTime);

		m_skullWhite.mTextureRect.w = m_skull.mTextureRect.w;
		m_skullWhite.mTextureRect.h = m_skull.mTextureRect.h;
		m_skullWhite.mTextureRect.x = m_skull.mTextureRect.x;
		m_skullWhite.mTextureRect.y = m_skull.mTextureRect.y;

		m_skullBox.y += 50;
		m_press.mTextureRect.x -= 100;
		m_enter.mTextureRect.x += 100;

		if (m_timer.ElapsedMilliseconds() > 250)
		{
			m_timer.Stop();

			game->gameStateMachine.pop();

			std::unique_ptr<GameState> mainMenuState = std::make_unique<MainMenuScene>();
			game->gameStateMachine.push(std::move(mainMenuState));
		}
	}

	if (!m_isClicked)
	{
		if (mFadeOut)
		{
			mFadeValue -= (0.2f * game->avgDeltaTime);
			if (mFadeValue <= SDL_ALPHA_TRANSPARENT)
			{
				mFadeOut = false;
				mFadeIn = true;
			}
		}

		if (mFadeIn)
		{
			mFadeValue += (0.2f * game->avgDeltaTime);
			if (mFadeValue >= SDL_ALPHA_OPAQUE)
			{
				mFadeOut = true;
				mFadeIn = false;
			}
		}

	}

	SDL_SetTextureAlphaMod(m_skullWhite.mTexture, static_cast<Uint8>(mFadeValue));
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
	SDL_RenderCopy(game->Renderer, m_background.mTexture, NULL, &m_background.mTextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	if (m_isBlood)
	{
		SDL_RenderCopy(game->Renderer, m_blood.mTexture, NULL, &m_blood.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_title.mTexture, NULL, &m_title.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_howLong.mTexture, NULL, &m_howLong.mTextureRect);
	}

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_plugBox);
	SDL_RenderFillRect(game->Renderer, &m_skullBox);
	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	if (m_isSkull)
	{
		SDL_RenderCopy(game->Renderer, m_skull.mTexture, NULL, &m_skull.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_skullWhite.mTexture, NULL, &m_skullWhite.mTextureRect);
	}
	SDL_RenderCopy(game->Renderer, m_press.mTexture, NULL, &m_press.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_enter.mTexture, NULL, &m_enter.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_plug.mTexture, NULL, &m_plug.mTextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.mTexture, NULL, &m_cursor.mTextureRect);
}