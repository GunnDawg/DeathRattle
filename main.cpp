#include "Game.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")

int main(int argc, char* args[])
{
	Gunn::Log::Init();

	Game* game = &Game::GetInstance();

	if (!game->Init())
	{
		return EXIT_FAILURE;
		GUNN_CORE_FATAL("Failed to initialize game. Please restart!");
	}

	while (game->isRunning)
	{
		game->ProcessInput();
		game->Update();
		game->Draw();
	}

	game->DestroyGame();
	game = nullptr;

	return EXIT_SUCCESS;
}