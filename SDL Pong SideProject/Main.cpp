#include <iostream>
#include <string>
#include <Windows.h>
#include <SDL.h>
#include "GameSystem.h"

using namespace std;

int main(int argc, char **argv)
{

	GameSystem* GameSys = new GameSystem("Pong Remake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 540, 540, false);

	while (GameSys->IsClosed() == false)
	{
		GameSys->PollEvents();
		GameSys->Render();
	}

	if (GameSys->IsClosed() == true)
	{
		delete GameSys;
		return -1;
	}

	GameSys->ShutDown();

	return 0;
}