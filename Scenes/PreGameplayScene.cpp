#include <memory>

#include "PreGameplayScene.h"
#include "Game.h"

void PreGameplayScene::on_enter()
{
	game = &Game::GetInstance();

	m_difficultyBox.w = 800;
	m_difficultyBox.h = 450;
	m_difficultyBox.x = (game->screenWidth / 2) - (m_difficultyBox.w / 2);
	m_difficultyBox.y = (game->screenHeight / 2) - (m_difficultyBox.h / 2) + 25;

	m_difficultyBoxOUtline.w = m_difficultyBox.w;
	m_difficultyBoxOUtline.h = m_difficultyBox.h;
	m_difficultyBoxOUtline.x = m_difficultyBox.x;
	m_difficultyBoxOUtline.y = m_difficultyBox.y;

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Load();
		m_skulls[i].mTextureRect.w = 100;
		m_skulls[i].mTextureRect.h = 100;
		m_skulls[i].mTextureRect.y = 0;
	}

	m_skulls[0].mTextureRect.x = 125;
	m_skulls[1].mTextureRect.x = (game->screenWidth - m_skulls[1].mTextureRect.w) - 125;

	m_cursor.Load();
	m_cursor.mTextureRect.w = 48;
	m_cursor.mTextureRect.h = 48;

	m_title.Load();
	m_title.mTextureRect.x = (game->screenWidth / 2) - (m_title.mTextureRect.w / 2);
	m_title.mTextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.mTextureRect.y;
	m_titleBox.w = game->screenWidth;
	m_titleBox.h = m_title.mTextureRect.h;

	m_background.Load();
	m_background.mTextureRect.x = 0;
	m_background.mTextureRect.y = 0;
	m_background.mTextureRect.w = game->screenWidth;
	m_background.mTextureRect.h = game->screenHeight;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_selectDifficulty.Load();
	m_selectDifficulty.mTextureRect.x = (game->screenWidth / 2) - (m_selectDifficulty.mTextureRect.w / 2);
	m_selectDifficulty.mTextureRect.y = m_difficultyBox.y + 20;

	m_easyRed.Load();
	m_easyRed.mTextureRect.x = (game->screenWidth / 2) - (m_easyRed.mTextureRect.w / 2);
	m_easyRed.mTextureRect.y = m_selectDifficulty.mTextureRect.y + 100;
	m_easyWhite.Load();
	m_easyWhite.mTextureRect.x = m_easyRed.mTextureRect.x;
	m_easyWhite.mTextureRect.y = m_easyRed.mTextureRect.y;

	m_mediumRed.Load();
	m_mediumRed.mTextureRect.x = (game->screenWidth / 2) - (m_mediumRed.mTextureRect.w / 2);
	m_mediumRed.mTextureRect.y = m_easyRed.mTextureRect.y + 65;
	m_mediumWhite.Load();
	m_mediumWhite.mTextureRect.x = m_mediumRed.mTextureRect.x;
	m_mediumWhite.mTextureRect.y = m_mediumRed.mTextureRect.y;

	m_hardRed.Load();
	m_hardRed.mTextureRect.x = (game->screenWidth / 2) - (m_hardRed.mTextureRect.w / 2);
	m_hardRed.mTextureRect.y = m_mediumRed.mTextureRect.y + 65;
	m_hardWhite.Load();
	m_hardWhite.mTextureRect.x = m_hardRed.mTextureRect.x;
	m_hardWhite.mTextureRect.y = m_hardRed.mTextureRect.y;

	m_devName.Load();
	m_devName.mTextureRect.x = (game->screenWidth / 2) - (m_devName.mTextureRect.w / 2);
	m_devName.mTextureRect.y = (game->screenHeight - m_devName.mTextureRect.h);

	m_version.Load();
	m_version.mTextureRect.x = ((game->screenWidth - m_version.mTextureRect.w) - 20);
	m_version.mTextureRect.y = (game->screenHeight - m_version.mTextureRect.h);

	m_devNameBox.w = game->screenWidth;
	m_devNameBox.h = m_devName.mTextureRect.h;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.mTextureRect.y;

	m_thud.Load();
	m_thud.Play();
}

void PreGameplayScene::on_exit()
{
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Unload();
	}

	m_cursor.Unload();
	m_title.Unload();
	m_background.Unload();
	m_devName.Unload();
	m_version.Unload();

	m_selectDifficulty.Unload();
	m_easyRed.Unload();
	m_easyWhite.Unload();
	m_mediumRed.Unload();
	m_mediumWhite.Unload();
	m_hardRed.Unload();
	m_hardWhite.Unload();

	m_thud.Unload();

	game = nullptr;
}

void PreGameplayScene::update()
{
	m_cursor.setRect(game->mouseX, game->mouseY);
	for(std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
	}
}

void PreGameplayScene::handle_events()
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

		default:
			break;
		}
	}
}

void PreGameplayScene::draw()
{
	SDL_RenderCopy(game->Renderer, m_background.mTexture, NULL, &m_background.mTextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 170);
	SDL_RenderFillRect(game->Renderer, &m_titleBox);
	SDL_RenderFillRect(game->Renderer, &m_devNameBox);
	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(game->Renderer, &m_difficultyBox);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(game->Renderer, &m_difficultyBoxOUtline);

	SDL_RenderCopyEx(game->Renderer, m_skulls[0].mTexture, NULL, &m_skulls[0].mTextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(game->Renderer, m_skulls[1].mTexture, NULL, &m_skulls[1].mTextureRect);

	SDL_RenderCopy(game->Renderer, m_title.mTexture, NULL, &m_title.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_devName.mTexture, NULL, &m_devName.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_version.mTexture, NULL, &m_version.mTextureRect);

	SDL_RenderCopy(game->Renderer, m_selectDifficulty.mTexture, NULL, &m_selectDifficulty.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_easyRed.mTexture, NULL, &m_easyRed.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_mediumRed.mTexture, NULL, &m_mediumRed.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_hardRed.mTexture, NULL, &m_hardRed.mTextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.mTexture, NULL, &m_cursor.mTextureRect);
}