#include "Collisions.h"



Collisions::Collisions()
{
}

bool Collisions::CheckCollisions(SDL_Rect Ball, SDL_Rect Paddle)
{
	int TopA = Ball.y, BottomA = Ball.y + Ball.h, LeftA = Ball.x, RightA = Ball.x + Ball.w;
	int TopB = Paddle.y, BottomB = Paddle.y + Paddle.h, LeftB = Paddle.x, RightB = Paddle.x + Paddle.w;

	if (TopA >= TopB)
	{
		return false;
	}
	
	if (BottomA >= BottomB)
	{
		return false;
	}

	if (LeftA >= LeftB)
	{
		return false;
	}

	if (RightA >= RightB)
	{
		return false;
	}

	return true;
}
