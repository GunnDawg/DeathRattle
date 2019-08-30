//#include "Stage.h"
//#include "Game.h"
//
//Stage::Stage()
//{
//	game = &Game::GetInstance();
//}
//
//Stage::~Stage()
//{
//
//}
//
//void Stage::Load()
//{
//	m_Texture.Load();
//	m_Texture.setRect(0, 0, game->screenWidth, game->screenHeight);
//
//	m_Flames[0].Load(12, -200, 320, 512);
//	m_Flames[1].Load(942, -200, 320, 512);
//}
//
//void Stage::Unload()
//{
//	for (size_t i = 0; i < m_Flames.size(); ++i)
//	{
//		m_Flames[i].Unload();
//	}
//
//	m_Texture.Unload();
//
//	game = nullptr;
//}
//
//void Stage::Update()
//{
//	for (size_t i = 0; i < m_Flames.size(); ++i)
//	{
//		m_Flames[i].Play(game->avgDeltaTime);
//	}
//}
//
//void Stage::Draw()
//{
//	SDL_RenderCopy(game->Renderer, m_Texture.m_Texture, NULL, &m_Texture.m_TextureRect);
//
//	for (size_t i = 0; i < m_Flames.size(); ++i)
//	{
//		m_Flames[i].Draw();
//	}
//}