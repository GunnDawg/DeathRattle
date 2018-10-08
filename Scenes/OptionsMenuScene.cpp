#include "OptionsMenuScene.h"
#include "Game.h"

void OptionsMenuScene::on_enter()
{
	m_cursor.Load(Game::Renderer, "Assets/Graphics/common/cursor2.png");
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_background.Load(Game::Renderer, "Assets/Graphics/common/main_background.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_title.Load(Game::Renderer, "Assets/Graphics/common/title.png");
	m_title.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = Game::screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_devName.Load(Game::Renderer, "Assets/Graphics/common/dev_name.png");
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_version.Load(Game::Renderer, "Assets/Graphics/common/version.png");
	m_version.m_TextureRect.x = ((Game::screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_thud.Load("Assets/Audio/thud.wav");
	m_thud.Play();
}

void OptionsMenuScene::on_exit()
{
	m_cursor.Unload();

	m_background.Unload();
	m_title.Unload();
	m_devName.Unload();
	m_version.Unload();

	m_thud.Unload();
}

void OptionsMenuScene::update()
{
	m_cursor.m_TextureRect.x = Game::mouseX;
	m_cursor.m_TextureRect.y = Game::mouseY;
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
				Game::gameStateMachine.pop();
			} break;

			case SDL_KEYDOWN:
			{
				switch (evnt.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						Game::gameStateMachine.pop();
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

void OptionsMenuScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.getTexture(), NULL, &m_background.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);

	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}