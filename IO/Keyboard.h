#pragma once

#include <SDL.h>
#include <cassert>
#include <cstdio>
#include "Entity/Paddle.h"

class Keyboard
{
public:
	Keyboard()=default;
	Keyboard(bool defaultState);
	~Keyboard()=default;
	void Update(double d, int sensitivity, int boundsX, int boundsY, Paddle& t, Paddle& r, Paddle& b, Paddle& l);

	inline void On() { m_Enabled = true; }
	inline void Off() { m_Enabled = false; }
	inline bool isEnabled() const { return m_Enabled; }

private:
	//Keyboard(const Keyboard& obj)=delete;
	//Keyboard& operator=(const Keyboard&)=delete;

	bool m_Enabled;
};