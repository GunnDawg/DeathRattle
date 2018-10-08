#include "CreditsScene.h"
#include "../Game.h"

void CreditsScene::on_enter()
{
	m_cursor.Load(Game::Renderer, "Assets/Graphics/common/cursor2.png");
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_title.Load(Game::Renderer, "Assets/Graphics/common/title.png");
	m_title.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = Game::screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_background.Load(Game::Renderer, "Assets/Graphics/common/main_background.png");
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_creditsBox.w = 800;
	m_creditsBox.h = 500;
	m_creditsBox.x = (Game::screenWidth / 2) - (m_creditsBox.w / 2);
	m_creditsBox.y = (Game::screenHeight / 2) - (m_creditsBox.h / 2) + 50;

	m_creditBoxOutline.w = m_creditsBox.w;
	m_creditBoxOutline.h = m_creditsBox.h;
	m_creditBoxOutline.x = m_creditsBox.x;
	m_creditBoxOutline.y = m_creditsBox.y;

	m_leadProgramming.Load(Game::Renderer, "Assets/Graphics/credits_scene/lead_programming.png");
	m_leadProgramming.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_leadProgramming.m_TextureRect.w / 2);
	m_leadProgramming.m_TextureRect.y = m_creditsBox.y + 20;

	m_calvin.Load(Game::Renderer, "Assets/Graphics/credits_scene/calvin.png");
	m_calvin.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_calvin.m_TextureRect.w / 2);
	m_calvin.m_TextureRect.y = m_leadProgramming.m_TextureRect.y + 65;

	m_additionalProgramming.Load(Game::Renderer, "Assets/Graphics/credits_scene/additional_programming.png");
	m_additionalProgramming.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_additionalProgramming.m_TextureRect.w / 2);
	m_additionalProgramming.m_TextureRect.y = m_calvin.m_TextureRect.y + 75;

	m_kelson.Load(Game::Renderer, "Assets/Graphics/credits_scene/kelson.png");
	m_kelson.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_kelson.m_TextureRect.w / 2);
	m_kelson.m_TextureRect.y = m_additionalProgramming.m_TextureRect.y + 65;

	m_panda.Load(Game::Renderer, "Assets/Graphics/credits_scene/fancykillerpanda.png");
	m_panda.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_panda.m_TextureRect.w / 2);
	m_panda.m_TextureRect.y = m_kelson.m_TextureRect.y + 50;

	m_jeff.Load(Game::Renderer, "Assets/Graphics/credits_scene/jeff.png");
	m_jeff.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_jeff.m_TextureRect.w / 2);
	m_jeff.m_TextureRect.y = m_panda.m_TextureRect.y + 50;

	m_thanks.Load(Game::Renderer, "Assets/Graphics/credits_scene/thankyou.png");
	m_thanks.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_thanks.m_TextureRect.w / 2);
	m_thanks.m_TextureRect.y = m_jeff.m_TextureRect.y + 75;

	m_devName.Load(Game::Renderer, "Assets/Graphics/common/dev_name.png");
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_version.Load(Game::Renderer, "Assets/Graphics/common/version.png");
	m_version.m_TextureRect.x = ((Game::screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_thud.Load("Assets/Audio/thud.wav");
	m_thud.Play();
}

void CreditsScene::on_exit()
{
	m_cursor.Unload();

	m_background.Unload();
	m_title.Unload();

	m_leadProgramming.Unload();
	m_calvin.Unload();

	m_additionalProgramming.Unload();
	m_kelson.Unload();
	m_panda.Unload();
	m_jeff.Unload();

	m_thanks.Unload();

	m_devName.Unload();
	m_version.Unload();

	m_thud.Unload();
}

void CreditsScene::update()
{
	m_cursor.m_TextureRect.x = Game::mouseX;
	m_cursor.m_TextureRect.y = Game::mouseY;
}

void CreditsScene::handle_events()
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

					default:
						break;
				}
			}

			default:
				break;
		}
	}
}

void CreditsScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_creditsBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

	SDL_RenderCopy(Game::Renderer, m_leadProgramming.m_Texture, NULL, &m_leadProgramming.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_calvin.m_Texture, NULL, &m_calvin.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_additionalProgramming.m_Texture, NULL, &m_additionalProgramming.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_kelson.m_Texture, NULL, &m_kelson.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_panda.m_Texture, NULL, &m_panda.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_jeff.m_Texture, NULL, &m_jeff.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_thanks.m_Texture, NULL, &m_thanks.m_TextureRect);

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::Renderer, &m_creditBoxOutline);

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}