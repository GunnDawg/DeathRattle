#include "CreditsScene.h"
#include "Game.h"

void CreditsScene::on_enter()
{
	GUNN_CORE_INFO("----------ENTERING CREDITS SCENE----------");

	game = &Game::GetInstance();

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

	m_creditsBox.w = 800;
	m_creditsBox.h = 500;
	m_creditsBox.x = (game->screenWidth / 2) - (m_creditsBox.w / 2);
	m_creditsBox.y = (game->screenHeight / 2) - (m_creditsBox.h / 2) + 50;

	m_creditBoxOutline.w = m_creditsBox.w;
	m_creditBoxOutline.h = m_creditsBox.h;
	m_creditBoxOutline.x = m_creditsBox.x;
	m_creditBoxOutline.y = m_creditsBox.y;

	m_leadProgramming.Load();
	m_leadProgramming.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_leadProgramming.mTextureRect.w / 2);
	m_leadProgramming.mTextureRect.y = m_creditsBox.y + 20;

	m_calvin.Load();
	m_calvin.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_calvin.mTextureRect.w / 2);
	m_calvin.mTextureRect.y = m_leadProgramming.mTextureRect.y + 65;

	m_additionalProgramming.Load();
	m_additionalProgramming.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_additionalProgramming.mTextureRect.w / 2);
	m_additionalProgramming.mTextureRect.y = m_calvin.mTextureRect.y + 75;

	m_kelson.Load();
	m_kelson.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_kelson.mTextureRect.w / 2);
	m_kelson.mTextureRect.y = m_additionalProgramming.mTextureRect.y + 65;

	m_panda.Load();
	m_panda.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_panda.mTextureRect.w / 2);
	m_panda.mTextureRect.y = m_kelson.mTextureRect.y + 50;

	m_jeff.Load();
	m_jeff.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_jeff.mTextureRect.w / 2);
	m_jeff.mTextureRect.y = m_panda.mTextureRect.y + 50;

	m_graphicsDesign.Load();
	m_graphicsDesign.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_graphicsDesign.mTextureRect.w / 2);
	m_graphicsDesign.mTextureRect.y = m_creditsBox.y + 20;

	m_mj.Load();
	m_mj.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_mj.mTextureRect.w / 2);
	m_mj.mTextureRect.y = m_graphicsDesign.mTextureRect.y + 65;

	m_sound.Load();
	m_sound.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_sound.mTextureRect.w / 2);
	m_sound.mTextureRect.y = m_mj.mTextureRect.y + 75;

	m_jun.Load();
	m_jun.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_jun.mTextureRect.w / 2);
	m_jun.mTextureRect.y = m_sound.mTextureRect.y + 65;

	m_savage.Load();
	m_savage.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_savage.mTextureRect.w / 2);
	m_savage.mTextureRect.y = m_jun.mTextureRect.y + 50;

	m_reitanna.Load();
	m_reitanna.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_reitanna.mTextureRect.w / 2);
	m_reitanna.mTextureRect.y = m_savage.mTextureRect.y + 50;

	m_pageOne.Load();
	m_pageOne.mTextureRect.x = m_creditsBox.x + ((m_creditsBox.w / 2) - m_pageOne.mTextureRect.w / 2);
	m_pageOne.mTextureRect.y = m_jeff.mTextureRect.y + 75;

	m_pageTwo.Load();
	m_pageTwo.mTextureRect.x = m_pageOne.mTextureRect.x;
	m_pageTwo.mTextureRect.y = m_pageOne.mTextureRect.y;

	m_pageThree.Load();
	m_pageThree.mTextureRect.x = m_pageOne.mTextureRect.x;
	m_pageThree.mTextureRect.y = m_pageOne.mTextureRect.y;

	m_devName.Load();
	m_devName.mTextureRect.x = (game->screenWidth / 2) - (m_devName.mTextureRect.w / 2);
	m_devName.mTextureRect.y = (game->screenHeight - m_devName.mTextureRect.h);

	m_version.Load();
	m_version.mTextureRect.x = (game->screenWidth - m_version.mTextureRect.w);
	m_version.mTextureRect.y = (game->screenHeight - m_version.mTextureRect.h);

	m_devNameBox.w = game->screenWidth;
	m_devNameBox.h = m_devName.mTextureRect.h;
	m_devNameBox.x = 0;
	m_devNameBox.y = m_devName.mTextureRect.y;

	m_rightArrow.Load();
	m_rightArrow.mTextureRect.x = (m_pageOne.mTextureRect.x + m_pageOne.mTextureRect.w) + 30;
	m_rightArrow.mTextureRect.y = m_pageOne.mTextureRect.y;
	m_rightArrowWhite.Load();
	m_rightArrowWhite.mTextureRect.x = m_rightArrow.mTextureRect.x;
	m_rightArrowWhite.mTextureRect.y = m_pageOne.mTextureRect.y;

	m_leftArrow.Load();
	m_leftArrow.mTextureRect.x = (m_pageOne.mTextureRect.x - 50) - (m_leftArrow.mTextureRect.w / 2);
	m_leftArrow.mTextureRect.y = m_pageOne.mTextureRect.y;
	m_leftArrowWhite.Load();
	m_leftArrowWhite.mTextureRect.x = m_leftArrow.mTextureRect.x;
	m_leftArrowWhite.mTextureRect.y = m_pageOne.mTextureRect.y;

	m_logo.Load();
	m_logo.mTextureRect.w = 300;
	m_logo.mTextureRect.h = 300;
	m_logo.mTextureRect.x = (game->screenWidth / 2) - (m_logo.mTextureRect.w / 2);
	m_logo.mTextureRect.y = m_creditsBox.y + 50;

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

	game = nullptr;
}

void CreditsScene::update()
{
	if (game->mouseX >= m_rightArrow.mTextureRect.x &&
		game->mouseX <= m_rightArrow.mTextureRect.x + m_rightArrow.mTextureRect.w &&
		game->mouseY >= m_rightArrow.mTextureRect.y &&
		game->mouseY <= m_rightArrow.mTextureRect.y + m_rightArrow.mTextureRect.h)
	{
		m_isRight = true;
	}
	else if (game->mouseX >= m_leftArrow.mTextureRect.x &&
		game->mouseX <= m_leftArrow.mTextureRect.x + m_leftArrow.mTextureRect.w &&
		game->mouseY >= m_leftArrow.mTextureRect.y &&
		game->mouseY <= m_leftArrow.mTextureRect.y + m_leftArrow.mTextureRect.h)
	{
		m_isLeft = true;
	}
	else
	{
		m_isRight = false;
		m_isLeft = false;
	}

	m_cursor.setRect(game->mouseX, game->mouseY);
	for (std::size_t i = 0; i < m_Flames.size(); ++i)
	{
		m_Flames[i].Play(game->avgDeltaTime);
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
				game->isRunning = false;
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

void CreditsScene::draw()
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
	SDL_RenderFillRect(game->Renderer, &m_creditsBox);
	SDL_SetRenderDrawBlendMode(game->Renderer, SDL_BLENDMODE_NONE);

	if (m_pageNum == 0)
	{
		SDL_RenderCopy(game->Renderer, m_leadProgramming.mTexture, NULL, &m_leadProgramming.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_calvin.mTexture, NULL, &m_calvin.mTextureRect);

		SDL_RenderCopy(game->Renderer, m_additionalProgramming.mTexture, NULL, &m_additionalProgramming.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_kelson.mTexture, NULL, &m_kelson.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_panda.mTexture, NULL, &m_panda.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_jeff.mTexture, NULL, &m_jeff.mTextureRect);

		SDL_RenderCopy(game->Renderer, m_pageOne.mTexture, NULL, &m_pageOne.mTextureRect);
	}

	else if (m_pageNum == 1)
	{
		SDL_RenderCopy(game->Renderer, m_graphicsDesign.mTexture, NULL, &m_graphicsDesign.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_mj.mTexture, NULL, &m_mj.mTextureRect);

		SDL_RenderCopy(game->Renderer, m_sound.mTexture, NULL, &m_sound.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_jun.mTexture, NULL, &m_jun.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_savage.mTexture, NULL, &m_savage.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_reitanna.mTexture, NULL, &m_reitanna.mTextureRect);

		SDL_RenderCopy(game->Renderer, m_pageTwo.mTexture, NULL, &m_pageTwo.mTextureRect);
	}

	else if (m_pageNum == 2)
	{
		SDL_RenderCopy(game->Renderer, m_logo.mTexture, NULL, &m_logo.mTextureRect);
		SDL_RenderCopy(game->Renderer, m_pageThree.mTexture, NULL, &m_pageThree.mTextureRect);
	}

	SDL_RenderCopy(game->Renderer, m_devName.mTexture, NULL, &m_devName.mTextureRect);
	SDL_RenderCopy(game->Renderer, m_version.mTexture, NULL, &m_version.mTextureRect);

	SDL_RenderCopy(game->Renderer, m_title.mTexture, NULL, &m_title.mTextureRect);

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(game->Renderer, &m_creditBoxOutline);

	if (m_isRight)
	{
		SDL_RenderCopy(game->Renderer, m_rightArrowWhite.mTexture, NULL, &m_rightArrowWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_rightArrow.mTexture, NULL, &m_rightArrow.mTextureRect);
	}

	if (m_isLeft)
	{
		SDL_RenderCopy(game->Renderer, m_leftArrowWhite.mTexture, NULL, &m_leftArrowWhite.mTextureRect);
	}
	else
	{
		SDL_RenderCopy(game->Renderer, m_leftArrow.mTexture, NULL, &m_leftArrow.mTextureRect);
	}

	SDL_RenderCopyEx(game->Renderer, m_skulls[0].mTexture, NULL, &m_skulls[0].mTextureRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(game->Renderer, m_skulls[1].mTexture, NULL, &m_skulls[1].mTextureRect);

	SDL_RenderCopy(game->Renderer, m_cursor.mTexture, NULL, &m_cursor.mTextureRect);
}