#pragma once
#include <SDL.h>
#include <cstdio>

class GameState
{
public:
	virtual void on_enter(SDL_Renderer* passedRenderer) = 0;
	virtual void on_exit() = 0;
	virtual void update(double dt) = 0;
	virtual void handle_events() = 0;
	virtual void draw(SDL_Renderer* passedRenderer) = 0;
};