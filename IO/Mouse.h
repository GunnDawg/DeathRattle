#pragma once
#include "Entity/Paddle.h"

class Game;

class Mouse
{
public:
	Mouse()=default;
	Mouse(bool defaultState);
	void Update(Paddle* t, Paddle* r, Paddle* b, Paddle* l);

	inline void On() { mEnabled = true; }
	inline void Off() { mEnabled = false; }
	inline bool isEnabled() const { return mEnabled; }

private:
	Game* game = nullptr;

	bool mEnabled;
	int mMouseX;
	int mMouseY;
};