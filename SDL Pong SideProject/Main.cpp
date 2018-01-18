#include <iostream>
#include <string>
#include <Windows.h>
#include <SDL.h>
#include "GameSystem.h"
#include "LMusic.h"
#include "Pong.h"

using namespace std;

int main(int argc, char **argv)
{

	GameSystem* GameSys = new GameSystem("Pong Remake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 540, 540, false);
	Pong* pong = new Pong(*GameSys, 10, 270, 40, 40, 490, 270, 40, 40, 40, 40);
	LMusic Lmusic;

	while (GameSys->IsClosed() == false)
	{
		pong->Draw();
		pong->PollEvents();
		GameSys->PollEvents();
		GameSys->Render();
	}

	if (GameSys->IsClosed() == true)
	{
		delete GameSys;
		delete pong;
		return -1;
	}

	GameSys->ShutDown();

	return 0;
}