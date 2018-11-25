#include <cstdio>
#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = &Game::getInstance();

	if (!game->Init())
	{
		printf("Error starting Game. Please Restart!\n");
		return EXIT_FAILURE;
	}

	while (Game::isRunning)
	{
		game->processinput();
		game->Update();
		game->Draw();
	}

	return EXIT_SUCCESS;
}