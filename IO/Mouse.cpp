#include "Mouse.h"
#include "Game.h"

Mouse::Mouse(bool defaultState) :
m_Enabled(defaultState),
m_MouseX(0), m_MouseY(0)
{
	assert(typeid(defaultState) == typeid(bool));

	game = &Game::GetInstance();
}

void Mouse::Update(Paddle* t, Paddle* r, Paddle* b, Paddle* l)
{
	m_MouseX = game->mouseX;
	m_MouseY = game->mouseY;
	m_MouseY -= (r->getRect().h / 2);
	m_MouseX -= (t->getRect().w / 2);

	t->setRectX(m_MouseX);
	b->setRectX(m_MouseX);
	l->setRectY(m_MouseY);
	r->setRectY(m_MouseY);
}