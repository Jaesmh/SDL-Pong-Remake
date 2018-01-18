#ifndef PONG_H
#define PONG_H

#include "GameSystem.h"

class Pong : protected GameSystem
{
protected:
	SDL_Rect Paddle1, Paddle2;
	SDL_Rect Ball;
	SDL_Texture* BallTexture = nullptr;
	int BallX, BallY, BallW, BallH;
	int Paddle1X, Paddle1Y, Paddle1W, Paddle1H = NULL;
	int Paddle2X, Paddle2Y, Paddle2W, Paddle2H = NULL;
	int BallVelX, BallVelY = NULL;
public:
	Pong(const GameSystem& GameSys, int P1X, int P1Y, int P1W, int P1H, int P2X, int P2Y, int P2W, int P2H, int BW, int BH);
	~Pong();
	void PollEvents();
	void BallCollisions();
	void Draw();
	inline int BallMovement(int Max, int Min) { return rand() % Max + rand() % Min; }
};

#endif //PONG_H