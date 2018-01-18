#include "Pong.h"
#include "Collisions.h"
#include "LTexture.h"

Pong::Pong(const GameSystem& GameSys, int P1X, int P1Y, int P1W, int P1H, int P2X, int P2Y, int P2W, int P2H, int BW, int BH)
	:GameSystem(GameSys),Paddle1X(P1X),Paddle2X(P2X),Paddle1Y(P1Y),Paddle2Y(P2Y),Paddle1W(P1W), Paddle2W(P2W),Paddle1H(P1H),
	Paddle2H(P2H), BallW(BW), BallH(BH)
{
}

Pong::~Pong()
{
	SDL_DestroyTexture(BallTexture);
}

void Pong::PollEvents()
{
	if (SDL_PollEvent(&Event))
	{
		switch (Event.key.keysym.sym)
		{
		case SDLK_w:
		Paddle1Y -= 5;
		break;

		case SDLK_s:
		Paddle1Y += 5;
		break;

		default:
			break;
		}
	}
}

void Pong::BallCollisions()
{
	if (BallX < 0)
	{
		BallX += 5;
	}

	else if (BallX > 520)
	{
		BallX -= 5;
	}

	if (Collisions::CheckCollisions(Ball, Paddle1) == true)
	{
		BallVelX += BallMovement(2, 0);
	}
}

void Pong::Draw() 
{
    
}
