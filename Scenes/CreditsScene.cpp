#include "CreditsScene.h"
#include "Game.h"

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

	m_graphicsDesign.Load(Game::Renderer, "Assets/Graphics/credits_scene/graphics_design.png");
	m_graphicsDesign.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_graphicsDesign.m_TextureRect.w / 2);
	m_graphicsDesign.m_TextureRect.y = m_creditsBox.y + 20;

	m_mj.Load(Game::Renderer, "Assets/Graphics/credits_scene/mj.png");
	m_mj.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_mj.m_TextureRect.w / 2);
	m_mj.m_TextureRect.y = m_graphicsDesign.m_TextureRect.y + 65;

	m_sound.Load(Game::Renderer, "Assets/Graphics/credits_scene/sound.png");
	m_sound.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_sound.m_TextureRect.w / 2);
	m_sound.m_TextureRect.y = m_mj.m_TextureRect.y + 75;

	m_jun.Load(Game::Renderer, "Assets/Graphics/credits_scene/jun.png");
	m_jun.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_jun.m_TextureRect.w / 2);
	m_jun.m_TextureRect.y = m_sound.m_TextureRect.y + 65;

	m_savage.Load(Game::Renderer, "Assets/Graphics/credits_scene/savage.png");
	m_savage.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_savage.m_TextureRect.w / 2);
	m_savage.m_TextureRect.y = m_jun.m_TextureRect.y + 50;

	m_reitanna.Load(Game::Renderer, "Assets/Graphics/credits_scene/reitanna.png");
	m_reitanna.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_reitanna.m_TextureRect.w / 2);
	m_reitanna.m_TextureRect.y = m_savage.m_TextureRect.y + 50;

	m_pageOne.Load(Game::Renderer, "Assets/Graphics/common/1of3.png");
	m_pageOne.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_pageOne.m_TextureRect.w / 2);
	m_pageOne.m_TextureRect.y = m_jeff.m_TextureRect.y + 75;

	m_pageTwo.Load(Game::Renderer, "Assets/Graphics/common/2of3.png");
	m_pageTwo.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_pageTwo.m_TextureRect.w / 2);
	m_pageTwo.m_TextureRect.y = m_jeff.m_TextureRect.y + 75;

	m_pageThree.Load(Game::Renderer, "Assets/Graphics/common/3of3.png");
	m_pageThree.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_pageThree.m_TextureRect.w / 2);
	m_pageThree.m_TextureRect.y = m_jeff.m_TextureRect.y + 75;

	m_devName.Load(Game::Renderer, "Assets/Graphics/common/dev_name.png");
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_version.Load(Game::Renderer, "Assets/Graphics/common/version.png");
	m_version.m_TextureRect.x = ((Game::screenWidth - m_version.m_TextureRect.w) - 20);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_rightArrow.Load(Game::Renderer, "Assets/Graphics/common/right_arrow.png");
	m_rightArrow.m_TextureRect.x = (m_pageOne.m_TextureRect.x + m_pageOne.m_TextureRect.w) + 30;
	m_rightArrow.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_rightArrowWhite.Load(Game::Renderer, "Assets/Graphics/common/right_arrow_white.png");
	m_rightArrowWhite.m_TextureRect.x = (m_pageOne.m_TextureRect.x + m_pageOne.m_TextureRect.w) + 30;
	m_rightArrowWhite.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_leftArrow.Load(Game::Renderer, "Assets/Graphics/common/left_arrow.png");
	m_leftArrow.m_TextureRect.x = (m_pageOne.m_TextureRect.x - 50) - (m_leftArrow.m_TextureRect.w / 2);
	m_leftArrow.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_leftArrowWhite.Load(Game::Renderer, "Assets/Graphics/common/left_arrow_white.png");
	m_leftArrowWhite.m_TextureRect.x = (m_pageOne.m_TextureRect.x - 50) - (m_leftArrowWhite.m_TextureRect.w / 2);
	m_leftArrowWhite.m_TextureRect.y = m_pageOne.m_TextureRect.y;

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

	m_pageOne.Unload();
	m_pageTwo.Unload();
	m_pageThree.Unload();

	m_devName.Unload();
	m_version.Unload();

	m_rightArrow.Unload();
	m_rightArrowWhite.Unload();
	m_leftArrow.Unload();
	m_leftArrowWhite.Unload();

	m_thud.Unload();
}

void CreditsScene::update()
{
	if (Game::mouseX >= m_rightArrow.m_TextureRect.x &&
		Game::mouseX <= m_rightArrow.m_TextureRect.x + m_rightArrow.m_TextureRect.w &&
		Game::mouseY >= m_rightArrow.m_TextureRect.y &&
		Game::mouseY <= m_rightArrow.m_TextureRect.y + m_rightArrow.m_TextureRect.h)
	{
		m_isRight = true;
	}
	else if (Game::mouseX >= m_leftArrow.m_TextureRect.x &&
		Game::mouseX <= m_leftArrow.m_TextureRect.x + m_leftArrow.m_TextureRect.w &&
		Game::mouseY >= m_leftArrow.m_TextureRect.y &&
		Game::mouseY <= m_leftArrow.m_TextureRect.y + m_leftArrow.m_TextureRect.h)
	{
		m_isLeft = true;
	}
	else
	{
		m_isRight = false;
		m_isLeft = false;
	}

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

			case SDL_MOUSEBUTTONDOWN:
			{
				if (m_isRight)
				{
					if (m_pageNum < 2)
					{
						++m_pageNum;
					}
					else
					{
						m_pageNum = 0;
					}
				}
				else if (m_isLeft)
				{
					if (m_pageNum > 0)
					{
						--m_pageNum;
					}
					else
					{
						m_pageNum = 2;
					}
				}
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

	if (m_pageNum == 0)
	{
		SDL_RenderCopy(Game::Renderer, m_leadProgramming.m_Texture, NULL, &m_leadProgramming.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_calvin.m_Texture, NULL, &m_calvin.m_TextureRect);

		SDL_RenderCopy(Game::Renderer, m_additionalProgramming.m_Texture, NULL, &m_additionalProgramming.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_kelson.m_Texture, NULL, &m_kelson.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_panda.m_Texture, NULL, &m_panda.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_jeff.m_Texture, NULL, &m_jeff.m_TextureRect);

		SDL_RenderCopy(Game::Renderer, m_pageOne.m_Texture, NULL, &m_pageOne.m_TextureRect);
	}

	else if (m_pageNum == 1)
	{
		SDL_RenderCopy(Game::Renderer, m_graphicsDesign.m_Texture, NULL, &m_graphicsDesign.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_mj.m_Texture, NULL, &m_mj.m_TextureRect);

		SDL_RenderCopy(Game::Renderer, m_sound.m_Texture, NULL, &m_sound.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_jun.m_Texture, NULL, &m_jun.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_savage.m_Texture, NULL, &m_savage.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_reitanna.m_Texture, NULL, &m_reitanna.m_TextureRect);

		SDL_RenderCopy(Game::Renderer, m_pageTwo.m_Texture, NULL, &m_pageTwo.m_TextureRect);
	}

	else if (m_pageNum == 2)
	{
		SDL_RenderCopy(Game::Renderer, m_pageThree.m_Texture, NULL, &m_pageThree.m_TextureRect);
	}


	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_NONE);

	SDL_RenderCopy(Game::Renderer, m_devName.m_Texture, NULL, &m_devName.m_TextureRect);
	SDL_RenderCopy(Game::Renderer, m_version.m_Texture, NULL, &m_version.m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_title.m_Texture, NULL, &m_title.m_TextureRect);

	SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::Renderer, &m_creditBoxOutline);

	if (m_isRight)
	{
		SDL_RenderCopy(Game::Renderer, m_rightArrowWhite.m_Texture, NULL, &m_rightArrowWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_rightArrow.m_Texture, NULL, &m_rightArrow.m_TextureRect);
	}

	if (m_isLeft)
	{
		SDL_RenderCopy(Game::Renderer, m_leftArrowWhite.m_Texture, NULL, &m_leftArrowWhite.m_TextureRect);
	}
	else
	{
		SDL_RenderCopy(Game::Renderer, m_leftArrow.m_Texture, NULL, &m_leftArrow.m_TextureRect);
	}

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}