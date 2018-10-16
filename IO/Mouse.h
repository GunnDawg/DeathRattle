#pragma once

#include <cstdio>
#include <SDL.h>
#include "Entity/Paddle.h"

class Mouse
{
public:
	Mouse()=default;
	Mouse(bool defaultState);
	~Mouse()=default;
	void Update(Paddle* t, Paddle* r, Paddle* b, Paddle* l);

	inline void On() { m_Enabled = true; }
	inline void Off() { m_Enabled = false; }
	inline bool isEnabled() const { return m_Enabled; }

private:
	//Mouse(const Mouse& obj)=delete;
	//Mouse& operator=(const Mouse&)=delete;

	bool m_Enabled;
	int m_MouseX;
	int m_MouseY;
};