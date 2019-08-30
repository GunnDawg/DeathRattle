#pragma once
#include <array>

#include "StateMachine/GameState.h"
#include "Graphics/Texture.h"
#include "Graphics/Animation.h"

class Game;

class BackgroundScene : public GameState
{
public:
	void on_enter() override;
	void on_exit() override;
	void update() override;
	void draw() override;

private:
	Game* game = nullptr;

	Texture mBackground;
	Texture mBall;
	std::array<Animation, 2> mFlames;
};