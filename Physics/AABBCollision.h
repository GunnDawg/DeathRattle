#pragma once
#include <SDL.h>
#include <cstdio>

class AABBCollision
{
public:
	AABBCollision();
	~AABBCollision()=default;

	bool CheckCollision(SDL_Rect firstRect, SDL_Rect secondRect) const;
private:
	//AABBCollision(const AABBCollision& obj)=delete;
	//AABBCollision& operator=(const AABBCollision&)=delete;
};