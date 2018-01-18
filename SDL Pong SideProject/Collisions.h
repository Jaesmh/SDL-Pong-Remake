#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "GameSystem.h"

class Collisions
{
private:
	bool Collided = false;
	int TopA, BottomA, LeftA, RightA = NULL;
	int TopB, BottomB, LeftB, RightB = NULL;
public:
	Collisions();
	bool CheckCollisions(SDL_Rect Ball, SDL_Rect Paddle);
};

#endif //COLLISIONS_H
