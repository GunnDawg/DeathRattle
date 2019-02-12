#include "OptionsMenuScene.h"
#include "GameSettings.h"
#include "Game.h"

void OptionsMenuScene::on_enter()
{
	game = &Game::GetInstance();

	m_optionsBox.w = 800;
	m_optionsBox.h = 500;
	m_optionsBox.x = (game->screenWidth / 2) - (m_optionsBox.w / 2);
	m_optionsBox.y = (game->screenHeight / 2) - (m_optionsBox.h / 2) + 50;

	m_optionsBoxOutline.w = m_optionsBox.w;
	m_optionsBoxOutline.h = m_optionsBox.h;
	m_optionsBoxOutline.x = m_optionsBox.x;
	m_optionsBoxOutline.y = m_optionsBox.y;

	m_options.Load();
	m_options.m_TextureRect.x = (game->screenWidth / 2) - (m_options.m_TextureRect.w / 2);
	m_options.m_TextureRect.y = m_optionsBox.y + 20;

	m_displayCheckMark.Load();
	m_displayCheckMark.m_TextureRect.w = 30;
	m_displayCheckMark.m_TextureRect.h = 30;

	//Display Mode
	m_displayMode.Load();
	m_displayMode.m_TextureRect.x = (m_optionsBox.x + 25);
	m_displayMode.m_TextureRect.y = (m_options.m_TextureRect.y + m_displayMode.m_TextureRect.h) + 50;

	m_fullScreen.Load();
	m_fullScreen.m_TextureRect.x = (m_optionsBox.x + 25);
	m_fullScreen.m_TextureRect.y = (m_displayMode.m_TextureRect.y + 75);

	m_fullScreenBox.x = (m_fullScreen.m_TextureRect.x + m_fullScreen.m_TextureRect.w) + 25;
	m_fullScreenBox.y = (m_fullScreen.m_TextureRect.y);
	m_fullScreenBox.w = 25;
	m_fullScreenBox.h = 25;

	m_fullScreenBoxOutline.x = m_fullScreenBox.x;
	m_fullScreenBoxOutline.y = m_fullScreenBox.y;
	m_fullScreenBoxOutline.w = m_fullScreenBox.w;
	m_fullScreenBoxOutline.h = m_fullScreenBox.h;

	m_windowed.Load();
	m_windowed.m_TextureRect.x = (m_optionsBox.x + 25);
	m_windowed.m_TextureRect.y = (m_fullScreen.m_TextureRect.y + 75);

	m_windowedBox.x = m_fullScreenBox.x;
	m_windowedBox.y = (m_windowed.m_TextureRect.y);
	m_windowedBox.w = 25;
	m_windowedBox.h = 25;

	m_windowedBoxOutline.x = m_windowedBox.x;
	m_windowedBoxOutline.y = m_windowedBox.y;
	m_windowedBoxOutline.w = m_windowedBox.w;
	m_windowedBoxOutline.h = m_windowedBox.h;

	//Audio Settings
	m_audioSettings.Load();
	m_audioSettings.m_TextureRect.x = (m_optionsBox.x + m_optionsBox.w) - (m_audioSettings.m_TextureRect.w) - 25;
	m_audioSettings.m_TextureRect.y = (m_options.m_TextureRect.y + m_audioSettings.m_TextureRect.h) + 50;

	m_soundEffects.Load();
	m_soundEffects.m_TextureRect.x = m_audioSettings.m_TextureRect.x;
	m_soundEffects.m_TextureRect.y = (m_audioSettings.m_TextureRect.y + 75);

	m_menuMusic.Load();
	m_menuMusic.m_TextureRect.x = m_audioSettings.m_TextureRect.x;
	m_menuMusic.m_TextureRect.y = (m_soundEffects.m_TextureRect.y + 75);

	m_gameplayMusic.Load();
	m_gameplayMusic.m_TextureRect.x = m_audioSettings.m_TextureRect.x;
	m_gameplayMusic.m_TextureRect.y = (m_menuMusic.m_TextureRect.y + 75);

	m_gameplayMusicBox.x = (m_gameplayMusic.m_TextureRect.x + m_gameplayMusic.m_TextureRect.w) + 25;
	m_gameplayMusicBox.y = m_gameplayMusic.m_TextureRect.y;
	m_gameplayMusicBox.w = 25;
	m_gameplayMusicBox.h = 25;

	m_gameplayMusicBoxOutline.x = m_gameplayMusicBox.x;
	m_gameplayMusicBoxOutline.y = m_gameplayMusicBox.y;
	m_gameplayMusicBoxOutline.w = m_gameplayMusicBox.w;
	m_gameplayMusicBoxOutline.h = m_gameplayMusicBox.h;

	m_soundEffectsBox.x = m_gameplayMusicBox.x;
	m_soundEffectsBox.y = m_soundEffects.m_TextureRect.y;
	m_soundEffectsBox.w = 25;
	m_soundEffectsBox.h = 25;

	m_soundEffectsBoxOutline.x = m_soundEffectsBox.x;
	m_soundEffectsBoxOutline.y = m_soundEffectsBox.y;
	m_soundEffectsBoxOutline.w = m_soundEffectsBox.w;
	m_soundEffectsBoxOutline.h = m_soundEffectsBox.h;

	m_menuMusicBox.x = m_gameplayMusicBox.x;
	m_menuMusicBox.y = (m_menuMusic.m_TextureRect.y);
	m_menuMusicBox.w = 25;
	m_menuMusicBox.h = 25;

	m_menuMusicBoxOutline.x = m_menuMusicBox.x;
	m_menuMusicBoxOutline.y = m_menuMusicBox.y;
	m_menuMusicBoxOutline.w = m_menuMusicBox.w;
	m_menuMusicBoxOutline.h = m_menuMusicBox.h;

	m_menuMusicCheckMark.Load();
	m_menuMusicCheckMark.m_TextureRect.w = 30;
	m_menuMusicCheckMark.m_TextureRect.h = 30;
	m_menuMusicCheckMark.m_TextureRect.x = m_menuMusicBox.x + (m_menuMusicBox.w / 5);
	m_menuMusicCheckMark.m_TextureRect.y = m_menuMusicBox.y - (m_menuMusicBox.h / 2);

	m_gameplayMusicCheckMark.Load();
	m_gameplayMusicCheckMark.m_TextureRect.w = 30;
	m_gameplayMusicCheckMark.m_TextureRect.h = 30;
	m_gameplayMusicCheckMark.m_TextureRect.x = m_gameplayMusicBox.x + (m_gameplayMusicBox.w / 5);
	m_gameplayMusicCheckMark.m_TextureRect.y = m_gameplayMusicBox.y - (m_gameplayMusicBox.h / 2);

	m_soundEffectsCheckMark.Load();
	m_soundEffectsCheckMark.m_TextureRect.w = 30;
	m_soundEffectsCheckMark.m_TextureRect.h = 30;
	m_soundEffectsCheckMark.m_TextureRect.x = m_soundEffectsBox.x + (m_soundEffectsBox.w / 5);
	m_soundEffectsCheckMark.m_TextureRect.y = m_soundEffectsBox.y - (m_soundEffectsBox.h / 2);

	// Common Items
	m_apply.Load();
	m_apply.m_TextureRect.x = (m_optionsBox.x + m_optionsBox.w) - (m_apply.m_TextureRect.w) - 50;
	m_apply.m_TextureRect.y = (m_optionsBox.y + m_optionsBox.h) - (m_apply.m_TextureRect.h) - 25;

	m_applyRed.Load();
	m_applyRed.m_TextureRect.x = m_apply.m_TextureRect.x;
	m_applyRed.m_TextureRect.y = m_apply.m_TextureRect.y;

	m_back.Load();
	m_back.m_TextureRect.x = m_optionsBox.x + 50;
	m_back.m_TextureRect.y = (m_optionsBox.y + m_optionsBox.h) - (m_back.m_TextureRect.h) - 25;

	m_backRed.Load();
	m_backRed.m_TextureRect.x = m_back.m_TextureRect.x;
	m_backRed.m_TextureRect.y = m_back.m_TextureRect.y;

	/////////////////////////////////////////////
	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Load();
		m_skulls[i].m_TextureRect.w = 100;
		m_skulls[i].m_TextureRect.h = 100;
		m_skulls[i].m_TextureRect.y = 0;
	}

	m_skulls[0].m_TextureRect.x = 125;
	m_skulls[1].m_TextureRect.x = (game->screenWidth - m_skulls[1].m_TextureRect.w) - 125;

	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = game->screenWidth;
	m_background.m_TextureRect.h = game->screenHeight;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_title.Load();
	m_title.m_TextureRect.x = (game->screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = game->screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_devName.Load();
	m_devName.m_TextureRect.x = (game->screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (game->screenHeight - m_devName.m_TextureRect.h);

	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.w = game->screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_version.Load();
	m_version.m_TextureRect.x = (game->screenWidth - m_version.m_TextureRect.w);
	m_version.m_TextureRect.y = (game->screenHeight - m_version.m_TextureRect.h);

	if (Settings::Audio::MenuMusic == 1)
	{
		m_menuMusicEnabled = true;
	}
	else if (Settings::Audio::MenuMusic == 0)
	{
		m_menuMusicEnabled = false;
	}

	if (Settings::Audio::GamePlayMusic == 1)
	{
		m_gameplayMusicEnabled = true;
	}
	else if(Settings::Audio::GamePlayMusic == 0)
	{
		m_gameplayMusicEnabled = false;
	}

	if (Settings::Audio::SoundEffects == 1)
	{
		m_soundEffectsEnabled = true;
	}
	else if(Settings::Audio::SoundEffects == 0)
	{
		m_soundEffectsEnabled = false;
	}

	m_thud.Load();
	m_thud.Play();
}

void OptionsMenuScene::on_exit()
{
	m_options.Unload();
	m_apply.Unload();
	m_applyRed.Unload();
	m_back.Unload();
	m_backRed.Unload();

	m_displayCheckMark.Unload();
	m_menuMusicCheckMark.Unload();
	m_gameplayMusicCheckMark.Unload();
	m_soundEffectsCheckMark.Unload();

	m_displayMode.Unload();
	m_fullScreen.Unload();
	m_windowed.Unload();

	m_audioSettings.Unload();
	m_menuMusic.Unload();
	m_gameplayMusic.Unload();
	m_soundEffects.Unload();

	m_background.Unload();
	m_title.Unload();
	m_devName.Unload();
	m_version.Unload();
	m_cursor.Unload();

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Unload();
	}

	m_thud.Unload();

	game = nullptr;
}

void OptionsMenuScene::update()
{
	if (game->mouseX >= m_apply.m_TextureRect.x &&
		game->mouseX <= m_apply.m_TextureRect.x + m_apply.m_TextureRect.w &&
		game->mouseY >= m_apply.m_TextureRect.y &&
		game->mouseY <= m_apply.m_TextureRect.y + m_apply.m_TextureRect.h)
	{
		m_isApply = true;
	}
	else if (game->mouseX >= m_back.m_TextureRect.x &&
		game->mouseX <= m_back.m_TextureRect.x + m_back.m_TextureRect.w &&
		game->mouseY >= m_back.m_TextureRect.y &&
		game->mouseY <= m_back.m_TextureRect.y + m_back.m_TextureRect.h)
	{
		m_isBack = true;
	}
	else if (game->mouseX >= m_fullScreenBox.x &&
		game->mouseX <= m_fullScreenBox.x + m_fullScreenBox.w &&
		game->mouseY >= m_fullScreenBox.y &&
		game->mouseY <= m_fullScreenBox.y + m_fullScreenBox.h)
	{
		m_isFullScreen = true;
	}
	else if (game->mouseX >= m_windowedBox.x &&
		game->mouseX <= m_windowedBox.x + m_windowedBox.w &&
		game->mouseY >= m_windowedBox.y &&
		game->mouseY <= m_windowedBox.y + m_windowedBox.h)
	{
		m_isWindowed = true;
	}
	else if (game->mouseX >= m_soundEffectsBox.x &&
		game->mouseX <= m_soundEffectsBox.x + m_soundEffectsBox.w &&
		game->mouseY >= m_soundEffectsBox.y &&
		game->mouseY <= m_soundEffectsBox.y + m_soundEffectsBox.h)
	{
		m_isSoundEffects = true;
	}
	else if (game->mouseX >= m_menuMusicBox.x &&
		game->mouseX <= m_menuMusicBox.x + m_menuMusicBox.w &&
		game->mouseY >= m_menuMusicBox.y &&
		game->mouseY <= m_menuMusicBox.y + m_menuMusicBox.h)
	{
		m_isMenuMusic = true;
	}
	else if (game->mouseX >= m_gameplayMusicBox.x &&
		game->mouseX <= m_gameplayMusicBox.x + m_gameplayMusicBox.w &&
		game->mouseY >= m_gameplayMusicBox.y &&
		game->mouseY <= m_gameplayMusicBox.y + m_gameplayMusicBox.h)
	{
		m_isGameplayMusic = true;
	}
	else
	{
		m_isApply = false;
		m_isBack = false;
		m_isFullScreen = false;
		m_isWindowed = false;
		m_isSoundEffects = false;
		m_isMenuMusic = false;
		m_isGameplayMusic = false;
	}

	if (m_fullScreenEnabled)
	{
		m_displayCheckMark.m_TextureRect.x = m_fullScreenBox.x + (m_fullScreenBox.w / 5);
		m_displayCheckMark.m_TextureRect.y = m_fullScreenBox.y - (m_fullScreenBox.h / 2);
	}
	else if (m_windowedEnabled)
	{
		m_displayCheckMark.m_TextureRect.x = m_windowedBox.x + (m_windowedBox.w / 5);
		m_displayCheckMark.m_TextureRect.y = m_windowedBox.y - (m_windowedBox.h / 2);
	}

	m_cursor.setRect(game->mouseX, game->mouseY);
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
	}
}

void OptionsMenuScene::handle_events()
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
					case SDLK_ESCAPE:
					{
						game->gameStateMachine.pop();
					} break;

				default:
					break;
				}
			} break;

			case SDL_MOUSEBUTTONDOWN:
			{
				if (m_isBack)
				{
					game->gameStateMachine.pop();
				}

				if (m_isFullScreen)
				{
					m_fullScreenEnabled = true;
					m_windowedEnabled = false;
				}
				else if (m_isWindowed)
				{
					m_fullScreenEnabled = false;
					m_windowedEnabled = true;
				}

				if (m_isSoundEffects)
				{
					if (!m_soundEffectsEnabled)
					{
						m_soundEffectsEnabled = true;
					}
					else if (m_soundEffectsEnabled)
					{
						m_soundEffectsEnabled = false;
					}
				}

				if (m_isMenuMusic)
				{
					if (!m_menuMusicEnabled)
					{
						m_menuMusicEnabled = true;
					}
					else if (m_menuMusicEnabled)
					{
						m_menuMusicEnabled = false;
					}
				}

				if (m_isGameplayMusic)
				{

					if (!m_gameplayMusicEnabled)
					{
						m_gameplayMusicEnabled = true;
					}
					else if (m_gameplayMusicEnabled)
					{
						m_gameplayMusicEnabled = false;
					}
				}

				if (m_isApply)
				{
					//m_thud.Play();

					if (m_menuMusicEnabled)
					{
						Settings::Audio::MenuMusic = 1;
						JukeBox->Load(JukeBox->MenuMusic);
						JukeBox->Setvolume(JukeBox->MenuMusic, 1.5);
						JukeBox->Play(JukeBox->MenuMusic);
					}
					else if (!m_menuMusicEnabled)
					{
						Settings::Audio::MenuMusic = 0;
						JukeBox->Stop(JukeBox->MenuMusic);
						JukeBox->Unload(JukeBox->MenuMusic);
					}

					if (m_gameplayMusicEnabled)
					{
						Settings::Audio::GamePlayMusic = 1;
					}
					else if (!m_gameplayMusicEnabled)
					{
						Settings::Audio::GamePlayMusic = 0;
					}

					if (m_soundEffectsEnabled)
					{
						Settings::Audio::SoundEffects = 1;
					}
					else if (!m_soundEffectsEnabled)
					{
						Settings::Audio::SoundEffects = 0;
					}

					game->gameStateMachine.pop();
				}

			} break;

		default:
			break;
		}
	}
}

void OptionsMenuScene::draw()
{
	SDL_RenderCopy(game->Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 170);
	SDL_RenderFillRect(game->Renderer, &m_titleBox);
	SDL_RenderFillRect(game->Renderer, &m_devNameBox);
	SDL_RenderFillRect(game->Renderer, &m_fullScreenBox);
	SDL_RenderFillRect(game->Renderer, &m_windowedBox);
	SDL_RenderFillRect(game->Renderer, &m_menuMusicBox);
	SDL_RenderFillRect(game->Renderer, &m_gameplayMusicBox);
	SDL_RenderFillRect(game->Renderer, &m_soundEffectsBox);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_optionsBox);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	SDL_RenderCopy(game->Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);

	SDL_RenderCopyEx(game->Renderer, m_skulls[0].m_Texture, NULL, &m_skulls[0].m_TextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(game->Renderer, m_skulls[1].m_Texture, NULL, &m_skulls[1].m_TextureRect);

	SDL_RenderCopy(game->Renderer, m_options.m_Texture, NULL, &m_options.m_TextureRect);

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(game->Renderer, &m_optionsBoxOutline);
	SDL_RenderDrawRect(game->Renderer, &m_fullScreenBoxOutline);
	SDL_RenderDrawRect(game->Renderer, &m_windowedBoxOutline);
	SDL_RenderDrawRect(game->Renderer, &m_gameplayMusicBoxOutline);
	SDL_RenderDrawRect(game->Renderer, &m_menuMusicBoxOutline);
	SDL_RenderDrawRect(game->Renderer, &m_soundEffectsBoxOutline);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 255);

	//Display Mode
	SDL_RenderCopy(game->Renderer, m_displayMode.m_Texture, NULL, &m_displayMode.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_fullScreen.m_Texture, NULL, &m_fullScreen.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_windowed.m_Texture, NULL, &m_windowed.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_displayCheckMark.m_Texture, NULL, &m_displayCheckMark.m_TextureRect);

	//Audio Settings
	SDL_RenderCopy(game->Renderer, m_audioSettings.m_Texture, NULL, &m_audioSettings.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_soundEffects.m_Texture, NULL, &m_soundEffects.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_menuMusic.m_Texture, NULL, &m_menuMusic.m_TextureRect);
	SDL_RenderCopy(game->Renderer, m_gameplayMusic.m_Texture, NULL, &m_gameplayMusic.m_TextureRect);

	if (m_soundEffectsEnabled)
	{
		SDL_RenderCopy(game->Renderer, m_soundEffectsCheckMark.m_Texture, NULL, &m_soundEffectsCheckMark.m_TextureRect);
	}

	if (m_menuMusicEnabled)
	{
		SDL_RenderCopy(game->Renderer, m_menuMusicCheckMark.m_Texture, NULL, &m_menuMusicCheckMark.m_TextureRect);
	}

	if (m_gameplayMusicEnabled)
	{
		SDL_RenderCopy(game->Renderer, m_gameplayMusicCheckMark.m_Texture, NULL, &m_gameplayMusicCheckMark.m_TextureRect);
	}

	if (m_isApply)
	{
		SDL_RenderCopy(game->Renderer, m_applyRed.m_Texture, NULL, &m_applyRed.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_apply.m_Texture, NULL, &m_apply.m_TextureRect);
	}

	if (m_isBack)
	{
		SDL_RenderCopy(game->Renderer, m_backRed.m_Texture, NULL, &m_backRed.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_back.m_Texture, NULL, &m_back.m_TextureRect);
	}

	SDL_RenderCopy(game->Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}