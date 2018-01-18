#include "Collisions.h"



Collisions::Collisions()
{
}

bool Collisions::CheckCollisions(SDL_Rect Ball, SDL_Rect Paddle)
{
	TopA = Ball.y;
	BottomA = Ball.y + Ball.h;
	LeftA = Ball.x;
	RightA = Ball.x + Ball.w;
	
	TopB = Paddle.y;
	BottomB = Paddle.y + Paddle.h;
	LeftB = Paddle.x;
	RightB = Paddle.y + Paddle.h;

	if (TopA >= TopB)
	{
		return Collided;
	}
	
	if (BottomA >= BottomB)
	{
		return Collided;
	}

	if (LeftA >= LeftB)
	{
		return Collided;
	}

	if (RightA >= RightB)
	{
		return Collided;
	}

	return Collided = true;
}
