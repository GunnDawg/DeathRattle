#include "PreGameplayScene.h"
#include "../Game.h"

void PreGameplayScene::on_enter()
{
	m_difficultyBox.w = 800;
	m_difficultyBox.h = 450;
	m_difficultyBox.x = (Game::screenWidth / 2) - (m_difficultyBox.w / 2);
	m_difficultyBox.y = (Game::screenHeight / 2) - (m_difficultyBox.h / 2) + 25;

	m_difficultyBoxOUtline.w = m_difficultyBox.w;
	m_difficultyBoxOUtline.h = m_difficultyBox.h;
	m_difficultyBoxOUtline.x = m_difficultyBox.x;
	m_difficultyBoxOUtline.y = m_difficultyBox.y;

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i] = Texture("Assets/Graphics/common/skull.png");
		m_skulls[i].Load();
		m_skulls[i].m_TextureRect.w = 100;
		m_skulls[i].m_TextureRect.h = 100;
		m_skulls[i].m_TextureRect.y = 0;
	}

	m_skulls[0].m_TextureRect.x = 125;
	m_skulls[1].m_TextureRect.x = (Game::screenWidth - m_skulls[1].m_TextureRect.w) - 125;

	m_cursor = Texture("Assets/Graphics/common/cursor.png");
	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_title = Texture("Assets/Graphics/common/title.png");
	m_title.Load();
	m_title.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = Game::screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_background = Texture("Assets/Graphics/common/main_background.png");
	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_Flames[0].Load(12, -200);
	m_Flames[1].Load(942, -200);

	m_devName = Texture("Assets/Graphics/common/dev_name.png");
	m_devName.Load();
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_version = Texture("Assets/Graphics/common/version.png");
	m_version.Load();
	m_version.m_TextureRect.x = ((Game::screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_thud.Load();
	m_thud.Play();
}

void PreGameplayScene::on_exit()
{
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Stop();
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

	m_thud.Unload();
}

void PreGameplayScene::update()
{
	m_cursor.setRect(Game::mouseX, Game::mouseY);
	m_Flames[0].Play(Game::deltaTime);
	m_Flames[1].Play(Game::deltaTime);
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
				Game::isRunning = false;
			} break;

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						Game::gameStateMachine.pop();
					} break;
				}
			} break;

			default:
				break;
		}
	}
}

void PreGameplayScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	m_Flames[0].Draw();
	m_Flames[1].Draw();

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 170);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_difficultyBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::Renderer, &m_difficultyBoxOUtline);

	SDL_RenderCopyEx(Game::Renderer, m_skulls[0].m_Texture, NULL, &m_skulls[0].m_TextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(Game::Renderer, m_skulls[1].m_Texture, NULL, &m_skulls[1].m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}