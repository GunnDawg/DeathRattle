#include "Game.h"
#include "Log/Log.h"

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
		GUNN_CORE_FATAL("Failed to initialize game. Please restart!");
		return EXIT_FAILURE;
	}

	while (game->isRunning)
	{
		game->ProcessInput();
		game->Update();
		game->Draw();
	}

	Game::DestroyGame();
	game = nullptr;

	return EXIT_SUCCESS;
}