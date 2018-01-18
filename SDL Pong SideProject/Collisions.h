#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "GameSystem.h"

class Collisions
{
public:
	Collisions();
	static bool CheckCollisions(SDL_Rect Ball, SDL_Rect Paddle);
};

#endif //COLLISIONS_H
