#include <cstdio>
#include "Game.h"

int main(int argc, char* args[])
{
	(void*)argc;
	(void*)args;

	Game& game = Game::getInstance();

	if (game.Init())
	{
		while (game.isRunning)
		{
			game.processinput();
			game.Update();
			game.Draw();
		}
	}
	else
	{
		printf("Error starting Game. Please Restart!\n");
		return(EXIT_FAILURE);
	}

	return(EXIT_SUCCESS);
}