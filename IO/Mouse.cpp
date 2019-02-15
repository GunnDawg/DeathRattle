#include "Mouse.h"
#include "Game.h"

Mouse::Mouse(bool defaultState) :
mEnabled(defaultState),
mMouseX(0), mMouseY(0)
{
	assert(typeid(defaultState) == typeid(bool));

	game = &Game::GetInstance();
}

void Mouse::Update(Paddle* t, Paddle* r, Paddle* b, Paddle* l)
{
	mMouseX = game->mouseX;
	mMouseY = game->mouseY;
	mMouseY -= (r->getRect().h / 2);
	mMouseX -= (t->getRect().w / 2);

	t->setRectX(mMouseX);
	b->setRectX(mMouseX);
	l->setRectY(mMouseY);
	r->setRectY(mMouseY);
}