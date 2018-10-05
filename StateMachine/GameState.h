#pragma once
#include <cstdio>

class GameState
{
public:
	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
	virtual void update(double dt) = 0;
};