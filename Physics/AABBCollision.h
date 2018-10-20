#pragma once
#include <SDL.h>
#include <cstdio>

class AABBCollision
{
public:
	AABBCollision()=default;
	~AABBCollision()=default;

	bool CheckCollision(SDL_Rect firstRect, SDL_Rect secondRect) const;
};