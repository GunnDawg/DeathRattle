#include "Game.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")

int main(int argc, char* args[])
{
	Game* game = &Game::GetInstance();

	if (!game->Init())
	{
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