#include "BackgroundScene.h"
#include "Game.h"

void BackgroundScene::on_enter()
{
	game = &Game::GetInstance();
}

void BackgroundScene::on_exit()
{
	mBackground.Unload();
	mBall.Unload();

	for (std::size_t i = 0; i < mFlames.size(); ++i)
	{
		mFlames[i].Unload();
	}

	game = nullptr;
}

void BackgroundScene::update()
{

}

void BackgroundScene::draw()
{

}