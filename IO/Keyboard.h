#pragma once

#include <cassert>
#include "Entity/Paddle.h"

class Keyboard
{
public:
	Keyboard()=default;
	Keyboard(bool defaultState);
	void Update(double d, int sensitivity, int boundsX, int boundsY, Paddle& t, Paddle& r, Paddle& b, Paddle& l);

	inline void On() { mEnabled = true; }
	inline void Off() { mEnabled = false; }
	inline bool isEnabled() const { return mEnabled; }

private:
	bool mEnabled;
};