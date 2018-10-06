#include <cstdio>
#include "Game.h"

int main(int argc, char* argv[])
{
	if (Game::getInstance().Init())
	{
		while(Game::getInstance().Running())
		{
			Game::getInstance().processinput();
			Game::getInstance().Update();
			Game::getInstance().Draw();
		}
	}
	else
	{
		printf("Error starting Game. Please Restart!\n");
	}

	return(0);
}