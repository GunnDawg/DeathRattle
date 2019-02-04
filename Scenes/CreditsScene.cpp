#include "CreditsScene.h"
#include "Game.h"

void CreditsScene::on_enter()
{
	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Load();
		m_skulls[i].m_TextureRect.w = 100;
		m_skulls[i].m_TextureRect.h = 100;
		m_skulls[i].m_TextureRect.y = 0;
	}

	m_skulls[0].m_TextureRect.x = 125;
	m_skulls[1].m_TextureRect.x = (Game::screenWidth - m_skulls[1].m_TextureRect.w) - 125;

	m_cursor.Load();
	m_cursor.m_TextureRect.w = 48;
	m_cursor.m_TextureRect.h = 48;

	m_title.Load();
	m_title.m_TextureRect.x = (Game::screenWidth / 2) - (m_title.m_TextureRect.w / 2);
	m_title.m_TextureRect.y = 0;

	m_titleBox.x = 0;
	m_titleBox.y = m_title.m_TextureRect.y;
	m_titleBox.w = Game::screenWidth;
	m_titleBox.h = m_title.m_TextureRect.h;

	m_background.Load();
	m_background.m_TextureRect.x = 0;
	m_background.m_TextureRect.y = 0;
	m_background.m_TextureRect.w = Game::screenWidth;
	m_background.m_TextureRect.h = Game::screenHeight;

	m_Flames[0].Load(12, -200, 320, 512);
	m_Flames[1].Load(942, -200, 320, 512);

	m_creditsBox.w = 800;
	m_creditsBox.h = 500;
	m_creditsBox.x = (Game::screenWidth / 2) - (m_creditsBox.w / 2);
	m_creditsBox.y = (Game::screenHeight / 2) - (m_creditsBox.h / 2) + 50;

	m_creditBoxOutline.w = m_creditsBox.w;
	m_creditBoxOutline.h = m_creditsBox.h;
	m_creditBoxOutline.x = m_creditsBox.x;
	m_creditBoxOutline.y = m_creditsBox.y;

	m_leadProgramming.Load();
	m_leadProgramming.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_leadProgramming.m_TextureRect.w / 2);
	m_leadProgramming.m_TextureRect.y = m_creditsBox.y + 20;

	m_calvin.Load();
	m_calvin.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_calvin.m_TextureRect.w / 2);
	m_calvin.m_TextureRect.y = m_leadProgramming.m_TextureRect.y + 65;

	m_additionalProgramming.Load();
	m_additionalProgramming.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_additionalProgramming.m_TextureRect.w / 2);
	m_additionalProgramming.m_TextureRect.y = m_calvin.m_TextureRect.y + 75;

	m_kelson.Load();
	m_kelson.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_kelson.m_TextureRect.w / 2);
	m_kelson.m_TextureRect.y = m_additionalProgramming.m_TextureRect.y + 65;

	m_panda.Load();
	m_panda.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_panda.m_TextureRect.w / 2);
	m_panda.m_TextureRect.y = m_kelson.m_TextureRect.y + 50;

	m_jeff.Load();
	m_jeff.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_jeff.m_TextureRect.w / 2);
	m_jeff.m_TextureRect.y = m_panda.m_TextureRect.y + 50;

	m_graphicsDesign.Load();
	m_graphicsDesign.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_graphicsDesign.m_TextureRect.w / 2);
	m_graphicsDesign.m_TextureRect.y = m_creditsBox.y + 20;

	m_mj.Load();
	m_mj.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_mj.m_TextureRect.w / 2);
	m_mj.m_TextureRect.y = m_graphicsDesign.m_TextureRect.y + 65;

	m_sound.Load();
	m_sound.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_sound.m_TextureRect.w / 2);
	m_sound.m_TextureRect.y = m_mj.m_TextureRect.y + 75;

	m_jun.Load();
	m_jun.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_jun.m_TextureRect.w / 2);
	m_jun.m_TextureRect.y = m_sound.m_TextureRect.y + 65;

	m_savage.Load();
	m_savage.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_savage.m_TextureRect.w / 2);
	m_savage.m_TextureRect.y = m_jun.m_TextureRect.y + 50;

	m_reitanna.Load();
	m_reitanna.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_reitanna.m_TextureRect.w / 2);
	m_reitanna.m_TextureRect.y = m_savage.m_TextureRect.y + 50;

	m_pageOne.Load();
	m_pageOne.m_TextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_pageOne.m_TextureRect.w / 2);
	m_pageOne.m_TextureRect.y = m_jeff.m_TextureRect.y + 75;

	m_pageTwo.Load();
	m_pageTwo.m_TextureRect.x = m_pageOne.m_TextureRect.x;
	m_pageTwo.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_pageThree.Load();
	m_pageThree.m_TextureRect.x = m_pageOne.m_TextureRect.x;
	m_pageThree.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_devName.Load();
	m_devName.m_TextureRect.x = (Game::screenWidth / 2) - (m_devName.m_TextureRect.w / 2);
	m_devName.m_TextureRect.y = (Game::screenHeight - m_devName.m_TextureRect.h);

	m_version.Load();
	m_version.m_TextureRect.x = (Game::screenWidth - m_version.m_TextureRect.w);
	m_version.m_TextureRect.y = (Game::screenHeight - m_version.m_TextureRect.h);

	m_devNameBox.w = Game::screenWidth;
	m_devNameBox.h = m_devName.m_TextureRect.h;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.m_TextureRect.y;

	m_rightArrow.Load();
	m_rightArrow.m_TextureRect.x = (m_pageOne.m_TextureRect.x + m_pageOne.m_TextureRect.w) + 30;
	m_rightArrow.m_TextureRect.y = m_pageOne.m_TextureRect.y;
	m_rightArrowWhite.Load();
	m_rightArrowWhite.m_TextureRect.x = m_rightArrow.m_TextureRect.x;
	m_rightArrowWhite.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_leftArrow.Load();
	m_leftArrow.m_TextureRect.x = (m_pageOne.m_TextureRect.x - 50) - (m_leftArrow.m_TextureRect.w / 2);
	m_leftArrow.m_TextureRect.y = m_pageOne.m_TextureRect.y;
	m_leftArrowWhite.Load();
	m_leftArrowWhite.m_TextureRect.x = m_leftArrow.m_TextureRect.x;
	m_leftArrowWhite.m_TextureRect.y = m_pageOne.m_TextureRect.y;

	m_logo.Load();
	m_logo.m_TextureRect.w = 300;
	m_logo.m_TextureRect.h = 300;
	m_logo.m_TextureRect.x = (Game::screenWidth / 2) - (m_logo.m_TextureRect.w / 2);
	m_logo.m_TextureRect.y = m_creditsBox.y + 50;

	m_thud.Load();
	m_thud.Play();
}

void CreditsScene::on_exit()
{
	m_cursor.Unload();

	m_background.Unload();
	m_title.Unload();
	m_logo.Unload();

	m_leadProgramming.Unload();
	m_calvin.Unload();

	m_additionalProgramming.Unload();
	m_kelson.Unload();
	m_panda.Unload();
	m_jeff.Unload();

	m_graphicsDesign.Unload();
	m_mj.Unload();

	m_pageOne.Unload();
	m_pageTwo.Unload();
	m_pageThree.Unload();

	m_sound.Unload();
	m_jun.Unload();
	m_savage.Unload();
	m_reitanna.Unload();

	m_devName.Unload();
	m_version.Unload();

	m_rightArrow.Unload();
	m_rightArrowWhite.Unload();
	m_leftArrow.Unload();
	m_leftArrowWhite.Unload();

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Unload();
	}

	for (std::size_t i = 0; i < m_skulls.size(); ++i)
	{
		m_skulls[i].Unload();
	}

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

	m_cursor.setRect(Game::mouseX, Game::mouseY);
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(Game::avgDeltaTime);
	}
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

					m_thud.Play();
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

					m_thud.Play();
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
			} break;

		default:
			break;
		}
	}
}

void CreditsScene::draw()
{
	SDL_RenderCopy(Game::Renderer, m_background.m_Texture, NULL, &m_background.m_TextureRect);

	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Draw();
	}

	SDL_SetRenderDrawBlendMode(Game::Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 170);
	SDL_RenderFillRect(Game::Renderer, &m_titleBox);
	SDL_RenderFillRect(Game::Renderer, &m_devNameBox);
	SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 0, 200);
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
		SDL_RenderCopy(Game::Renderer, m_logo.m_Texture, NULL, &m_logo.m_TextureRect);
		SDL_RenderCopy(Game::Renderer, m_pageThree.m_Texture, NULL, &m_pageThree.m_TextureRect);
	}

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

	SDL_RenderCopyEx(Game::Renderer, m_skulls[0].m_Texture, NULL, &m_skulls[0].m_TextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(Game::Renderer, m_skulls[1].m_Texture, NULL, &m_skulls[1].m_TextureRect);

	SDL_RenderCopy(Game::Renderer, m_cursor.m_Texture, NULL, &m_cursor.m_TextureRect);
}