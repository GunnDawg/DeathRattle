#pragma once

#include <SDL.h>
#include "Entity/Paddle.h"

class Mouse
{
public:
	Mouse()=default;
	Mouse(bool defaultState);
	void Update(Paddle* t, Paddle* r, Paddle* b, Paddle* l);

	inline void On() { m_Enabled = true; }
	inline void Off() { m_Enabled = false; }
	inline bool isEnabled() const { return m_Enabled; }

private:
	bool m_Enabled;
	int m_MouseX;
	int m_MouseY;
};