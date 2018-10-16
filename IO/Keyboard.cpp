#include "Keyboard.h"

Keyboard::Keyboard(bool defaultState) :
m_Enabled(defaultState)
{
	assert(typeid(defaultState) == typeid(bool));
}

void Keyboard::Update(double d, int sensitivity, int boundsX, int boundsY, Paddle& t, Paddle& r, Paddle& b, Paddle& l)
{
	const Uint8* keyState = SDL_GetKeyboardState(nullptr);
	if (keyState[SDL_SCANCODE_D])
	{
		if (t.getRect().x < boundsX - (t.getRect().w / 2))
		{
			t.setRectX(t.getRect().x + static_cast<int>(sensitivity * d));
			b.setRectX(b.getRect().x + static_cast<int>(sensitivity * d));
		}
	}
	else if (keyState[SDL_SCANCODE_A])
	{
		if (t.getRect().x > 0 - (t.getRect().w / 2))
		{
			t.setRectX(t.getRect().x - static_cast<int>(sensitivity * d));
			b.setRectX(b.getRect().x - static_cast<int>(sensitivity * d));
		} 
	}

	if (keyState[SDL_SCANCODE_W])
	{
		if (r.getRect().y > 0 - (r.getRect().h) / 2)
		{
			r.setRectY(r.getRect().y - static_cast<int>(sensitivity * d));
			l.setRectY(r.getRect().y - static_cast<int>(sensitivity * d));
		}
	}
	else if (keyState[SDL_SCANCODE_S])
	{
		if (r.getRect().y < boundsY - (r.getRect().h) / 2)
		{
			r.setRectY(r.getRect().y + static_cast<int>(sensitivity * d));
			l.setRectY(l.getRect().y + static_cast<int>(sensitivity * d));
		}
	}
}