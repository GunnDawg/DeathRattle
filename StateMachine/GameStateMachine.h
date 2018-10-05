#pragma once
#include <cstdio>
#include <memory>
#include <vector>

#include "GameState.h"

class GameStateMachine
{
public:
	void push(SDL_Renderer* passedRenderer, std::unique_ptr<GameState> states);
	void pop();
	void update(double dt);
	void draw(SDL_Renderer* passedRenderer);
	void handleEvents();

	std::vector<std::unique_ptr<GameState>> m_gameStates;
};