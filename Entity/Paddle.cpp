#include "Paddle.h"
#include "Game.h"

Paddle::Paddle(int x, int y, int w, int h) :
mPaddleRect({ w, h, x, y })
{
	assert(typeid(w) == typeid(int) && w > 0 && "Paddle width must be greater than 0");
	assert(typeid(h) == typeid(int) && h > 0 && "Paddle height must be greater than 0");
	assert(typeid(x) == typeid(int) && x > 0 && "Paddle must have an X value");
	assert(typeid(y) == typeid(int) && y > 0 && "Paddle must have an Y value");

	game = &Game::GetInstance();
}

void Paddle::Draw()
{
	//Render a memey shadow on paddles
	SDL_Rect border;
	border.w = mPaddleRect.w + 3;
	border.h = mPaddleRect.h + 3;
	border.x = mPaddleRect.x;
	border.y = mPaddleRect.y;

	SDL_SetRenderDrawColor(game->Renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(game->Renderer, &border);

	if (mPaddleMarked)
	{
		//SDL_SetRenderDrawColor(passedRender, 136, 4, 7, 255);
		SDL_SetRenderDrawColor(game->Renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(game->Renderer, &mPaddleRect);
	}
	else
	{
		SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(game->Renderer, &mPaddleRect);
	}

	SDL_SetRenderDrawColor(game->Renderer, 255, 255, 255, 255);
}

void Paddle::resetPaddles(int x, int y, int w, int h)
{
	mPaddleRect = { x, y, w, h };
	mPaddleMarked = false;
}

void Paddle::Heal()
{
	if (mPaddleRect.h > 15)
	{
		mPaddleRect.h += (mPaddleRect.h / 20);
	}
	else
	{
		mPaddleRect.w += (mPaddleRect.w / 20);
	}

	mPaddleMarked = false;
}

void Paddle::setHit(bool hit)
{
	mPaddleMarked = hit;
}