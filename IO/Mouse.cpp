#include "Mouse.h"

Mouse::Mouse(bool defaultState) :
m_Enabled(defaultState),
m_MouseX(0), m_MouseY(0)
{
	assert(typeid(defaultState) == typeid(bool));
}

void Mouse::Update(Paddle* t, Paddle* r, Paddle* b, Paddle* l)
{
	SDL_GetMouseState(&m_MouseX, &m_MouseY);
	m_MouseY -= (r->getRect().h / 2);
	m_MouseX -= (t->getRect().w / 2);

	t->setRectX(m_MouseX);
	b->setRectX(m_MouseX);
	l->setRectY(m_MouseY);
	r->setRectY(m_MouseY);
}