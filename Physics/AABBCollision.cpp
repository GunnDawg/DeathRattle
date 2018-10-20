#include "AABBCollision.h"

bool AABBCollision::CheckCollision(SDL_Rect firstRect, SDL_Rect secondRect) const
{
	if (firstRect.x + firstRect.w >= secondRect.x &&
		secondRect.x + secondRect.w >= firstRect.x &&
		firstRect.y + firstRect.h >= secondRect.y &&
		secondRect.y + secondRect.h >= firstRect.y)
	{
		return(true);
	}

	return(false);
}