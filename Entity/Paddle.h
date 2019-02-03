#pragma once

#include <SDL.h>
#include <cassert>
#include <typeinfo>
#include "Graphics/Texture.h"
#include "Game.h"

class Paddle
{
public:
	Paddle()=default;
	Paddle(int x, int y, int w, int h);
	~Paddle()=default;

	bool isMarked() const { return m_paddleMarked; }

	void Draw();
	void resetPaddles(int x, int y, int w, int h);
	inline void setRectX(int x) { m_paddleRect.x = x; }
	inline void setRectY(int y) { m_paddleRect.y = y; }
	inline void setRectW(int w) { m_paddleRect.w = w; }
	inline void setRectH(int h) { m_paddleRect.h = h; }
	inline SDL_Rect getRect()	{ return m_paddleRect; }

	void Heal();
	void setHit(bool hit);

private:
	Paddle(const Paddle& objt)=delete;
	Paddle& operator=(const Paddle&)=delete;

	SDL_Rect m_paddleRect             = { 0 };
	double m_moveSpeed                = 0.0;
	bool m_paddleMarked               = false;
};