#pragma once
extern "C"
{
	#include <SDL.h>
}

#include <cassert>
#include <typeinfo>
#include "Graphics/Texture.h"

class Game;

class Paddle
{
public:
	Paddle()=default;
	Paddle(int x, int y, int w, int h);

	bool isMarked() const { return mPaddleMarked; }

	void Draw();
	void resetPaddles(int x, int y, int w, int h);
	inline void setRectX(int x) { mPaddleRect.x = x; }
	inline void setRectY(int y) { mPaddleRect.y = y; }
	inline void setRectW(int w) { mPaddleRect.w = w; }
	inline void setRectH(int h) { mPaddleRect.h = h; }
	inline SDL_Rect getRect()	{ return mPaddleRect; }

	void Heal();
	void setHit(bool hit);

private:
	Game* game                        = nullptr;

	SDL_Rect mPaddleRect             = { 0 };
	double mMoveSpeed                = 0.0;
	bool mPaddleMarked               = false;
};