#include <cstdio>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game game("Test", 1280, 720);
	if (game.Init())
	{
		while (game.isRunning())
		{
			game.processinput();
			game.Update();
			game.Draw();
		}
	}
	else
	{
		printf("Error starting Game. Please Restart!\n");
	}

	return(0);
}