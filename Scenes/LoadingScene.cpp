//#include "LoadingScene.h"
//#include "SplashScene.h"
//#include "Game.h"
//
//void LoadingScene::on_enter()
//{
//	m_Loading.Load();
//	m_Loading.m_TextureRect.x = (Game::screenWidth / 2) - (m_Loading.m_TextureRect.w / 2);
//	m_Loading.m_TextureRect.y = (Game::screenHeight / 2) - (m_Loading.m_TextureRect.h / 2);
//
//	m_timer.Start();
//}
//
//void LoadingScene::on_exit()
//{
//	m_Loading.Unload();
//}
//
//void LoadingScene::update()
//{
//	if (m_timer.elapsedSeconds() >= 2)
//	{
//		m_timer.Stop();
//		Game::gameStateMachine.pop();
//
//		std::unique_ptr<GameState> splashScene = std::make_unique<SplashScene>();
//		Game::gameStateMachine.push(std::move(splashScene));
//	}
//}
//
//void LoadingScene::handle_events()
//{
//	SDL_Event evnt;
//	while (SDL_PollEvent(&evnt))
//	{
//		switch (evnt.type)
//		{
//			case SDL_QUIT:
//			{
//				game->isRunning = false;
//			} break;
//
//		default:
//			break;
//		}
//	}
//}
//
//void LoadingScene::draw()
//{
//	SDL_RenderCopy(Game::Renderer, m_Loading.m_Texture, NULL, &m_Loading.m_TextureRect);
//}