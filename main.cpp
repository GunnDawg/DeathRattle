#include <cstdio>
#include "Game.h"
#include "GameSettings.h"

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
		game->ProcessInput();
		game->Update();
		game->Draw();
	}

	game->DestroyGame();
	game = nullptr;

	return EXIT_SUCCESS;
}