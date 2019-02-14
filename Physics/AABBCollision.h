#pragma once
extern "C"
{
	#include <SDL.h>
}

class AABBCollision
{
public:
	AABBCollision()=default;

	bool CheckCollision(SDL_Rect firstRect, SDL_Rect secondRect) const;
};